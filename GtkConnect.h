#pragma once
#ifndef GtkConnectH
#define GtkConnectH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

#include "Parbat.h"

template <typename Widget_T, typename T>
void ConnectActivate(const string& strObjectName, T& instance, void (T::*function)()) {
  Widget_T* pWidget(NULL);
  GetGladeRef()->get_widget(strObjectName, pWidget);
  pWidget->signal_activate().connect(sigc::mem_fun(instance, function));
}

template <typename Widget_T, typename T>
void ConnectClicked(const string& strObjectName, T& instance, void (T::*function)()) {
  Widget_T* pWidget(NULL);
  GetGladeRef()->get_widget(strObjectName, pWidget);
  pWidget->signal_clicked().connect(sigc::mem_fun(instance, function));
}

template <typename Widget_T, typename T>
void ConnectExposeEvent(const string& strObjectName, T& instance, bool (T::*function)(GdkEventExpose*)) {
  Widget_T* pWidget(NULL);
  GetGladeRef()->get_widget(strObjectName, pWidget);
  pWidget->signal_expose_event().connect(sigc::mem_fun(instance, function));
}

#endif
