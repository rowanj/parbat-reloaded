/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "Parbat.h"

#include "AboutDialog.h"

//----------------------------------------------------------------------------
AboutDialog::AboutDialog(BaseObjectType* cobject,
			 const glade_ref_t& refGlade) :
  Gtk::Dialog(cobject),
  m_pBtnClose(NULL)
{
  refGlade->get_widget("CloseButton", m_pBtnClose);
  m_pBtnClose->signal_clicked().connect
    (sigc::mem_fun(*this, &AboutDialog::BtnCloseClick));
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
