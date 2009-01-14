/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "Parbat.h"
#include "OverviewWindow.h"

int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  Glib::RefPtr<Gnome::Glade::Xml> refXml =
    Gnome::Glade::Xml::create("parbat3d-ui.glade");

  Gtk::Window* pOverviewWindow(NULL);

  refXml->get_widget("OverviewWindow", pOverviewWindow);

  Gtk::Main::run(*pOverviewWindow);

  return 0;
}
