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
  glade_ref_t g_refGlade;
}

//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  g_refGlade = Gtk::Builder::create_from_file("Parbat.glade");

  GetApp();

  return 0;
}


//----------------------------------------------------------------------------
glade_ref_t GetGladeRef()
{
  return g_refGlade;
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
  GetGladeRef()->get_widget_derived("OverviewWindow", m_pOverviewWindow);

  Gtk::Main::run(*m_pOverviewWindow);
}

//----------------------------------------------------------------------------
OverviewWindow& ParbatApp::GetOverviewWindow()
{
  return *m_pOverviewWindow;
}
