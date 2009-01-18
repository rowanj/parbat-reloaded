/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "AboutDialog.h"
#include "Parbat.h"

#include "OverviewWindow.h"

//----------------------------------------------------------------------------
OverviewWindow::OverviewWindow(BaseObjectType* cobject,
			       const glade_ref_t& refGlade) :
  Gtk::Window(cobject)
{
  //  GetRefGlade()->get_widget("OverviewWindow", m_pWindow);
  Gtk::MenuItem* pItem(NULL);
  GetGladeRef()->get_widget("about1", pItem);
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
void OverviewWindow::MnuAboutClicked()
{
  AboutDialog* pAbout(NULL);
  GetGladeRef()->get_widget_derived("AboutDialog", pAbout);
  pAbout->show();
}
