/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "OverviewWindow.h"

#include "AboutDialog.h"
#include "GtkConnect.h"
#include "Parbat.h"

void Permute(guint8* pData, int iWidth, int iHeight) {
  for (int i = 0; i < iWidth * iHeight * 4; ++i) {
    pData[i] += 64;
  }
}

//----------------------------------------------------------------------------
OverviewWindow::OverviewWindow(BaseObjectType* cobject,
			       const glade_ref_t& refGlade) :
  Gtk::Window(cobject),
  m_pDrawingArea(NULL)
{
  ConnectActivate<Gtk::MenuItem>("about1", *this, &OverviewWindow::MnuAboutClicked);
  ConnectActivate<Gtk::MenuItem>("quit1", *this, &OverviewWindow::MnuQuitClicked);

  ConnectExposeEvent<Gtk::DrawingArea>("OverviewDrawingArea", *this, &OverviewWindow::DrawEvent);

  GetGladeRef()->get_widget("OverviewDrawingArea", m_pDrawingArea);

  m_iOverviewWidth = m_pDrawingArea->get_width();
  m_iOverviewHeight = m_pDrawingArea->get_height();

  m_aOverviewPixels = new guint8[m_iOverviewWidth * m_iOverviewHeight * 4];

  for (int y = 0; y < m_iOverviewHeight; ++y) {
    for (int x = 0; x < m_iOverviewWidth; ++x) {
      const int iBaseIndex = (x * 4) + (y * m_iOverviewWidth * 4);
      m_aOverviewPixels[iBaseIndex] = x;
      m_aOverviewPixels[iBaseIndex + 1] = (x + y) % 256;
      m_aOverviewPixels[iBaseIndex + 2] = y;
      m_aOverviewPixels[iBaseIndex + 3] = 255;
    }
  }

  opixbuf = 
    Gdk::Pixbuf::create_from_data(m_aOverviewPixels, Gdk::COLORSPACE_RGB, true, 8, m_iOverviewWidth, m_iOverviewHeight, m_iOverviewWidth * 4);
}

//----------------------------------------------------------------------------
OverviewWindow::~OverviewWindow()
{
  delete[] m_aOverviewPixels;
  m_aOverviewPixels = 0;
}

//----------------------------------------------------------------------------
void OverviewWindow::MnuAboutClicked()
{
  AboutDialog* pAbout(NULL);
  GetGladeRef()->get_widget_derived("AboutDialog", pAbout);
  pAbout->show();
}

//----------------------------------------------------------------------------
void OverviewWindow::MnuQuitClicked()
{
  // Close documents
  
  // Close windows

  // Quit
  Gtk::Main::quit();
}

//-----------------------------------------------------------------------------
bool OverviewWindow::DrawEvent(GdkEventExpose* event)
{
  Glib::RefPtr<Gdk::Window> oWindow = m_pDrawingArea->get_window();
  if (oWindow) {
    Cairo::RefPtr<Cairo::Context> cr = oWindow->create_cairo_context();
    
    Gdk::Cairo::set_source_pixbuf(cr, opixbuf, 0, 0);

    cr->paint();

    Permute(m_aOverviewPixels, 200, 200);
  }

  return true;
}

