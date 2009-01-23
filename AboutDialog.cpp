/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "AboutDialog.h"

#include "GtkHelp.h"
#include "Parbat.h"

//----------------------------------------------------------------------------
AboutDialog::AboutDialog(BaseObjectType* cobject,
			 const glade_ref_t& refGlade) :
  Gtk::Dialog(cobject)
{
  ConnectButton("CloseButton", *this, &AboutDialog::BtnCloseClick);
}

//----------------------------------------------------------------------------
AboutDialog::~AboutDialog()
{
}

//----------------------------------------------------------------------------
void AboutDialog::BtnCloseClick()
{
  hide();
}
