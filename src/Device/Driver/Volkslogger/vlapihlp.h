/***********************************************************************
**
**   vlapihlp.h
**
**   This file is part of libkfrgcs.
**
************************************************************************
**
**   Copyright (c):  2002 by Garrecht Ingenieurgesellschaft
**
**   This file is distributed under the terms of the General Public
**   Licence. See the file COPYING for more information.
**
**   $Id$
**
***********************************************************************/

#pragma once

#include "util/Compiler.h"

// some generally needed helper-functions


char *igc_filter(char *);

void
wordtoserno(char *buffer, unsigned serno);

[[gnu::pure]]
long
pressure2altitude(unsigned pressure);
