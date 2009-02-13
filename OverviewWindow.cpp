/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "OverviewWindow.h"

#include "AboutDialog.h"
#include "GtkConnect.h"
#include "Parbat.h"

//----------------------------------------------------------------------------
OverviewWindow::OverviewWindow(BaseObjectType* cobject,
			       const glade_ref_t& refGlade) :
  Gtk::Window(cobject),
  m_pDrawingArea(NULL)
{
  ConnectMenuItem("about1", *this, &OverviewWindow::MnuAboutClicked);
  ConnectMenuItem("quit1", *this, &OverviewWindow::MnuQuitClicked);

  GetGladeRef()->get_widget("OverviewDrawingArea", m_pDrawingArea);
  m_pDrawingArea->signal_expose_event().connect(sigc::mem_fun(*this, &OverviewWindow::DrawEvent));

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
    Gtk::Allocation oAllocation = m_pDrawingArea->get_allocation();
    const int width = oAllocation.get_width();
    const int height = oAllocation.get_height();

    Cairo::RefPtr<Cairo::Context> cr = oWindow->create_cairo_context();

    Glib::RefPtr<Gdk::Pixbuf> opixbuf =
      Gdk::Pixbuf::create_from_data(m_aOverviewPixels, Gdk::COLORSPACE_RGB, true, 8, width, height, width * 4);

    Gdk::Cairo::set_source_pixbuf(cr, opixbuf, 0, 0);
    cr->paint();
  }

  return true;
}

