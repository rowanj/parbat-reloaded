/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "OverviewWindow.h"

#include "AboutDialog.h"
#include "GtkHelp.h"
#include "Parbat.h"

//----------------------------------------------------------------------------
OverviewWindow::OverviewWindow(BaseObjectType* cobject,
			       const glade_ref_t& refGlade) :
  Gtk::Window(cobject)
{
  ConnectMenuItem("about1", *this, &OverviewWindow::MnuAboutClicked);
  ConnectMenuItem("quit1", *this, &OverviewWindow::MnuQuitClicked);
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
