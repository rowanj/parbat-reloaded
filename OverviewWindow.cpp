/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "OverviewWindow.h"

#include "Parbat.h"

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
  Gtk::Dialog* pDialog(NULL);
  GetRefXML()->get_widget("AboutDialog", pDialog);
  pDialog->show();
  //  cout << "blarg!" << endl;
}
