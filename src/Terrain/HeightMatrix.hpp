/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2010 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#ifndef XCSOAR_TERRAIN_HEIGHT_MATRIX_HPP
#define XCSOAR_TERRAIN_HEIGHT_MATRIX_HPP

#include "Util/NonCopyable.hpp"
#include "Util/AllocatedArray.hpp"
#include "Compiler.h"

class RasterMap;
class WindowProjection;

class HeightMatrix : private NonCopyable {
  AllocatedArray<short> data;
  unsigned width, height;

  short minimum, maximum;

public:
  HeightMatrix():width(0), height(0) {}

protected:
  void SetSize(size_t _size);
  void SetSize(unsigned width, unsigned height);
  void SetSize(unsigned width, unsigned height, unsigned quantisation_pixels);

public:
  void Fill(const RasterMap &map, const WindowProjection &map_projection,
            unsigned quantisation_pixels);

  unsigned get_width() const {
    return width;
  }

  unsigned get_height() const {
    return height;
  }

  const short *GetData() const {
    return data.begin();
  }

  const short *GetRow(unsigned y) const {
    return data.begin() + y * width;
  }

  const short *GetDataEnd() const {
    return GetRow(height);
  }

  /**
   * Determine the smalles height value in this buffer.
   */
  gcc_pure
  short get_minimum() const {
    return minimum;
  }

  /**
   * Determine the biggest height value in this buffer.
   */
  gcc_pure
  short get_maximum() const {
    return maximum;
  }
};

#endif
