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

// we also use libglade to load the interface from XML at runtime
#include <libglademm.h>

// and Cairo for drawing bitmaps
#include <cairomm/context.h>

#include <glibmm.h>

// Other
#include <cassert>

// A bunch of typedefs for shorthand
#include "ParbatTypes.h"
using namespace NParbatTypes;

using namespace std;

#endif
