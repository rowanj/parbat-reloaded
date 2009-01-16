#pragma once
#ifndef OverviewWindowH
#define OverviewWindowH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

class OverviewWindow
{
 public:
  OverviewWindow();
  virtual ~OverviewWindow();

  Gtk::Window* GetWindowPtr();

 private:
  void MnuAboutClicked();


  Gtk::Window* m_pWindow;
};

#endif
