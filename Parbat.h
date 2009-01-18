#pragma once
#ifndef ParbatH
#define ParbatH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

#include "OverviewWindow.h"

class ParbatApp
{
 public:
  static ParbatApp& GetInstance();

  // Global data and instances
  OverviewWindow& GetOverviewWindow();

 private:
  ParbatApp();

  OverviewWindow* m_pOverviewWindow;

  static ParbatApp* s_pInstance;
};

// Alias for ParbatApp::GetInstance()
ParbatApp& GetApp();
glade_ref_t GetGladeRef();

#endif
