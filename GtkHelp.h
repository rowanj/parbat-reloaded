#pragma once
#ifndef GtkHelpH
#define GtkHelpH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

template <typename T>
void Connect(const string& strMenuItemName, T& instance, void (T::*function)()) {
  Gtk::MenuItem* pItem(NULL);
  GetGladeRef()->get_widget(strMenuItemName, pItem);
  pItem->signal_activate().connect(sigc::mem_fun(instance, function));
}


#endif
