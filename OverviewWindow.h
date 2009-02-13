#pragma once
#ifndef OverviewWindowH
#define OverviewWindowH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

class OverviewWindow: public Gtk::Window
{
 public:
  OverviewWindow(BaseObjectType* cobject,
		 const glade_ref_t& refGlade);
  virtual ~OverviewWindow();

 private:
  void MnuAboutClicked();
  void MnuQuitClicked();
  bool DrawEvent(GdkEventExpose*);

  Gtk::DrawingArea* m_pDrawingArea;

  int m_iOverviewWidth;
  int m_iOverviewHeight;
  guint8* m_aOverviewPixels;
};

#endif
