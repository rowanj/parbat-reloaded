#pragma once
#ifndef GtkConnectH
#define GtkConnectH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

#include "Parbat.h"

template <typename T>
void ConnectMenuItem(const string& strMenuItemName, T& instance, void (T::*function)()) {
  Gtk::MenuItem* pItem(NULL);
  GetGladeRef()->get_widget(strMenuItemName, pItem);
  pItem->signal_activate().connect(sigc::mem_fun(instance, function));
}

template <typename T>
void ConnectButton(const string& strButtonName, T& instance, void (T::*function)()) {
  Gtk::Button* pButton(NULL);
  GetGladeRef()->get_widget(strButtonName, pButton);
  pButton->signal_clicked().connect(sigc::mem_fun(instance, function));
}


#endif
