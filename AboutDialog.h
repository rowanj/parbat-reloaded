#pragma once
#ifndef AboutDialogH
#define AboutDialogH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

class AboutDialog: public Gtk::Dialog
{
 public:
  AboutDialog(BaseObjectType* cobject,
	      const Glib::RefPtr<Gnome::Glade::Xml>& refGlade);
  virtual ~AboutDialog();

 private:
  void BtnCloseClick();

  Gtk::Button* m_pBtnClose;
};

#endif
