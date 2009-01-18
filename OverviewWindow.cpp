/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "AboutDialog.h"
#include "Parbat.h"

#include "OverviewWindow.h"

//----------------------------------------------------------------------------
OverviewWindow::OverviewWindow() :
  m_pWindow(NULL)
{
  GetRefXML()->get_widget("OverviewWindow", m_pWindow);

  Gtk::MenuItem* pItem(NULL);
  GetRefXML()->get_widget("about1", pItem);
  pItem->signal_activate().connect(
	      sigc::mem_fun(
			    *this,
			    &OverviewWindow::MnuAboutClicked
			    )
				   );
}

//----------------------------------------------------------------------------
OverviewWindow::~OverviewWindow()
{
}

//----------------------------------------------------------------------------
Gtk::Window* OverviewWindow::GetWindowPtr()
{
  return m_pWindow;
}

//----------------------------------------------------------------------------
void OverviewWindow::MnuAboutClicked()
{
  AboutDialog* pAbout(NULL);
  GetRefXML()->get_widget_derived("AboutDialog", pAbout);
  pAbout->show();
}
