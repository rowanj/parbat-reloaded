#pragma once
#ifndef PchAppH
#define PchAppH
/****************************************************************************\
| Copyright 2009 Rowan James
\****************************************************************************/

/****************************************************************************\
| Application-wide header
| This file should be included at the start of most (all?) C++ source files
| It should *NOT* be included from any header
\****************************************************************************/

// C++ standard library
#include <iostream>
#include <string>


// STL


// Boost.org


// GDAL
#include <gdal_priv.h>

// gtkmm (GTK+ C++ bindings, a.k.a. GTK--)
#include <gtkmm.h>

// Cairo for drawing bitmaps
#include <cairomm/context.h>

// And glib for various things (like types like guint8)
#include <glibmm.h>

// Other
// C++ variants of standard C libraries
#include <cassert>

// A bunch of typedefs for shorthand
#include "ParbatTypes.h"
using namespace NParbatTypes;

using namespace std;

#endif
