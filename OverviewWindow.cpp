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
}

//----------------------------------------------------------------------------
OverviewWindow::~OverviewWindow()
{
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

    int xc, yc;
    xc = width / 2;
    yc = height / 2;

    Cairo::RefPtr<Cairo::Context> cr = oWindow->create_cairo_context();
    cr->set_line_width(10.0);

    // clip to the area indicated by the expose event so that we only redraw
    // the portion of the window that needs to be redrawn
    cr->rectangle(event->area.x, event->area.y,
            event->area.width, event->area.height);
    cr->clip();

    // draw red lines out from the center of the window
    cr->set_source_rgb(0.8, 0.0, 0.0);
    cr->move_to(0, 0);
    cr->line_to(xc, yc);
    cr->line_to(0, height);
    cr->move_to(xc, yc);
    cr->line_to(width, yc);
    cr->stroke();
  
  }

  /*  Gdk::Region oRegion(ptr->region, true);
  Glib::ArrayHandle<Gdk::Rectangle> aRects(oRegion.get_rectangles());

  for (Glib::ArrayHandle<Gdk::Rectangle>::iterator it = aRects.begin();
       it != aRects.end(); ++it) {
       } /**/

  return true;
}

