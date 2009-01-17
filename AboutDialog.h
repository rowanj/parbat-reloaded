#pragma once
#ifndef AboutDialogH
#define AboutDialogH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

class AboutDialog
{
 public:
  AboutDialog();
  virtual ~AboutDialog();

 private:
  void BtnCloseClick();

  Gtk::Dialog* m_pDialog;
};

#endif
