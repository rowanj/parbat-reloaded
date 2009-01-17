/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/
#include "PchApp.h"

#include "Parbat.h"

#include "AboutDialog.h"

//----------------------------------------------------------------------------
AboutDialog::AboutDialog() :
  m_pDialog(NULL)
{
  GetRefXML()->get_widget("AboutDialog", m_pDialog);
  m_pDialog->show();

  Gtk::Button* pCloseButton(NULL);
  GetRefXML()->get_widget("CloseButton", pCloseButton);
  pCloseButton->signal_clicked().connect(sigc::mem_fun(*this, &AboutDialog::BtnCloseClick));
}

//----------------------------------------------------------------------------
AboutDialog::~AboutDialog()
{
  m_pDialog->hide();
  delete m_pDialog;
  m_pDialog = NULL;
}

//----------------------------------------------------------------------------
void AboutDialog::BtnCloseClick()
{
  delete this;
}
