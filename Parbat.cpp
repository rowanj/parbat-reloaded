/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "Parbat.h"
#include "OverviewWindow.h"

//----------------------------------------------------------------------------
ParbatApp* ParbatApp::s_pInstance(NULL);

namespace {
  // We use Glade to load the user interface from XML
  Glib::RefPtr<Gnome::Glade::Xml> g_RefXML;
}

//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  g_RefXML = Gnome::Glade::Xml::create("parbat3d-ui.glade");

  GetApp();

  return 0;
}


//----------------------------------------------------------------------------
Glib::RefPtr<Gnome::Glade::Xml> GetRefXML()
{
  return g_RefXML;
}

//----------------------------------------------------------------------------
ParbatApp& GetApp()
{
  return ParbatApp::GetInstance();
}

//----------------------------------------------------------------------------
ParbatApp& ParbatApp::GetInstance()
{
  if (s_pInstance == NULL) {
    s_pInstance = new ParbatApp();
  }
  return *s_pInstance;
}

//----------------------------------------------------------------------------
// Actual class implementation for ParbatApp
//----------------------------------------------------------------------------
ParbatApp::ParbatApp() :
  m_pOverviewWindow(NULL)
{

  m_pOverviewWindow = new OverviewWindow();

  Gtk::Main::run(*(m_pOverviewWindow->GetWindowPtr()));
}

//----------------------------------------------------------------------------
OverviewWindow& ParbatApp::GetOverviewWindow()
{
  return *m_pOverviewWindow;
}
