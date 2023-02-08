/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2022 The XCSoar Project
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

#include "ResourceId.hpp"

#if defined(USE_GDI) || defined(ANDROID)

#define MAKE_RESOURCE(name, id) \
  static constexpr ResourceId name(id);

#else

#include <cstddef>

#define MAKE_RESOURCE(name, id) \
  extern "C" std::byte resource_ ## id[]; \
  extern "C" const size_t resource_ ## id ## _size; \
  static constexpr ResourceId name(resource_ ##id, &resource_ ## id ## _size);

#endif

MAKE_RESOURCE(IDB_LANDABLE, 139);
MAKE_RESOURCE(IDB_LANDABLE_HD, 5139);
MAKE_RESOURCE(IDB_REACHABLE, 140);
MAKE_RESOURCE(IDB_REACHABLE_HD, 5140);
MAKE_RESOURCE(IDB_TURNPOINT, 141);
MAKE_RESOURCE(IDB_TURNPOINT_HD, 5141);
MAKE_RESOURCE(IDB_SMALL, 142);
MAKE_RESOURCE(IDB_SMALL_HD, 5142);
MAKE_RESOURCE(IDB_CRUISE, 212);
MAKE_RESOURCE(IDB_CRUISE_HD, 5212);
MAKE_RESOURCE(IDB_CLIMB, 213);
MAKE_RESOURCE(IDB_CLIMB_HD, 5213);
MAKE_RESOURCE(IDB_FINALGLIDE, 214);
MAKE_RESOURCE(IDB_FINALGLIDE_HD, 5214);
MAKE_RESOURCE(IDB_TOWN, 218);
MAKE_RESOURCE(IDB_TOWN_HD, 5218);
MAKE_RESOURCE(IDB_MARK, 219);
MAKE_RESOURCE(IDB_MARK_HD, 5219);
MAKE_RESOURCE(IDB_TERRAINWARNING, 220);
MAKE_RESOURCE(IDB_TERRAINWARNING_HD, 5220);
MAKE_RESOURCE(IDB_LOGO_HD, 251);
MAKE_RESOURCE(IDB_GPSSTATUS1, 256);
MAKE_RESOURCE(IDB_GPSSTATUS1_HD, 5256);
MAKE_RESOURCE(IDB_GPSSTATUS2, 257);
MAKE_RESOURCE(IDB_GPSSTATUS2_HD, 5257);
MAKE_RESOURCE(IDB_ABORT, 269);
MAKE_RESOURCE(IDB_ABORT_HD, 5269);
MAKE_RESOURCE(IDB_AIRPORT_REACHABLE, 289);
MAKE_RESOURCE(IDB_AIRPORT_REACHABLE_HD, 5289);
MAKE_RESOURCE(IDB_AIRPORT_UNREACHABLE, 290);
MAKE_RESOURCE(IDB_AIRPORT_UNREACHABLE_HD, 5290);
MAKE_RESOURCE(IDB_OUTFIELD_REACHABLE, 291);
MAKE_RESOURCE(IDB_OUTFIELD_REACHABLE_HD, 5291);
MAKE_RESOURCE(IDB_OUTFIELD_UNREACHABLE, 292);
MAKE_RESOURCE(IDB_OUTFIELD_UNREACHABLE_HD, 5292);
MAKE_RESOURCE(IDB_CLIMBSMALL, 313);
MAKE_RESOURCE(IDB_CLIMBSMALLINV, 314);
MAKE_RESOURCE(IDB_THERMALSOURCE, 316);
MAKE_RESOURCE(IDB_THERMALSOURCE_HD, 5316);
MAKE_RESOURCE(IDB_TARGET, 320);
MAKE_RESOURCE(IDB_TARGET_HD, 5320);
MAKE_RESOURCE(IDB_TEAMMATE_POS, 322);
MAKE_RESOURCE(IDB_TEAMMATE_POS_HD, 5322);
MAKE_RESOURCE(IDB_LAUNCHER1, 330);
MAKE_RESOURCE(IDB_LAUNCHER2, 331);
MAKE_RESOURCE(IDB_LOGO, 332);
MAKE_RESOURCE(IDB_AIRPORT_UNREACHABLE2, 334);
MAKE_RESOURCE(IDB_AIRPORT_UNREACHABLE2_HD, 5334);
MAKE_RESOURCE(IDB_OUTFIELD_UNREACHABLE2, 335);
MAKE_RESOURCE(IDB_OUTFIELD_UNREACHABLE2_HD, 5335);
MAKE_RESOURCE(IDB_AIRSPACEI, 336);
MAKE_RESOURCE(IDB_AIRSPACEI_HD, 5336);
MAKE_RESOURCE(IDB_PROGRESSBORDER, 337);
MAKE_RESOURCE(IDB_TITLE, 338);
MAKE_RESOURCE(IDB_TITLE_HD, 339);
MAKE_RESOURCE(IDB_MAPSCALE_LEFT, 340);
MAKE_RESOURCE(IDB_MAPSCALE_RIGHT, 341);
MAKE_RESOURCE(IDB_MAPSCALE_LEFT_HD, 5340);
MAKE_RESOURCE(IDB_MAPSCALE_RIGHT_HD, 5341);

#ifdef EYE_CANDY
MAKE_RESOURCE(IDB_DIALOGTITLE, 342);
#endif

MAKE_RESOURCE(IDB_MOUNTAIN_TOP, 343);
MAKE_RESOURCE(IDB_MOUNTAIN_TOP_HD, 5343);
MAKE_RESOURCE(IDB_BRIDGE, 344);
MAKE_RESOURCE(IDB_BRIDGE_HD, 5344);
MAKE_RESOURCE(IDB_TUNNEL, 345);
MAKE_RESOURCE(IDB_TUNNEL_HD, 5345);
MAKE_RESOURCE(IDB_TOWER, 346);
MAKE_RESOURCE(IDB_TOWER_HD, 5346);
MAKE_RESOURCE(IDB_POWER_PLANT, 347);
MAKE_RESOURCE(IDB_POWER_PLANT_HD, 5347);
MAKE_RESOURCE(IDB_FOLDER, 348);
MAKE_RESOURCE(IDB_FOLDER_HD, 5348);
MAKE_RESOURCE(IDB_SETTINGS, 349);
MAKE_RESOURCE(IDB_SETTINGS_HD, 5349);
MAKE_RESOURCE(IDB_TASK, 350);
MAKE_RESOURCE(IDB_TASK_HD, 5350);
MAKE_RESOURCE(IDB_CALCULATOR, 351);
MAKE_RESOURCE(IDB_CALCULATOR_HD, 5351);
MAKE_RESOURCE(IDB_AIRPORT_MARGINAL, 352);
MAKE_RESOURCE(IDB_AIRPORT_MARGINAL_HD, 5352);
MAKE_RESOURCE(IDB_OUTFIELD_MARGINAL, 353);
MAKE_RESOURCE(IDB_OUTFIELD_MARGINAL_HD, 5353);
MAKE_RESOURCE(IDB_AIRPORT_MARGINAL2, 354);
MAKE_RESOURCE(IDB_AIRPORT_MARGINAL2_HD, 5354);
MAKE_RESOURCE(IDB_OUTFIELD_MARGINAL2, 355);
MAKE_RESOURCE(IDB_OUTFIELD_MARGINAL2_HD, 5355);
MAKE_RESOURCE(IDB_MARGINAL, 356);
MAKE_RESOURCE(IDB_MARGINAL_HD, 5356);
MAKE_RESOURCE(IDB_WRENCH, 357);
MAKE_RESOURCE(IDB_WRENCH_HD, 5357);
MAKE_RESOURCE(IDB_GLOBE, 358);
MAKE_RESOURCE(IDB_GLOBE_HD, 5358);
MAKE_RESOURCE(IDB_DEVICE, 359);
MAKE_RESOURCE(IDB_DEVICE_HD, 5359);
MAKE_RESOURCE(IDB_RULES, 360);
MAKE_RESOURCE(IDB_RULES_HD, 5360);
MAKE_RESOURCE(IDB_CLOCK, 361);
MAKE_RESOURCE(IDB_CLOCK_HD, 5361);
MAKE_RESOURCE(IDB_TRAFFIC_SAFE, 362);
MAKE_RESOURCE(IDB_TRAFFIC_SAFE_HD, 5362);
MAKE_RESOURCE(IDB_TRAFFIC_WARNING, 363);
MAKE_RESOURCE(IDB_TRAFFIC_WARNING_HD, 5363);
MAKE_RESOURCE(IDB_TRAFFIC_ALARM, 364);
MAKE_RESOURCE(IDB_TRAFFIC_ALARM_HD, 5364);
MAKE_RESOURCE(IDB_TASKTURNPOINT, 365);
MAKE_RESOURCE(IDB_TASKTURNPOINT_HD, 5365);
MAKE_RESOURCE(IDB_OBSTACLE, 366);
MAKE_RESOURCE(IDB_OBSTACLE_HD, 5366);
MAKE_RESOURCE(IDB_MOUNTAIN_PASS, 367);
MAKE_RESOURCE(IDB_MOUNTAIN_PASS_HD, 5367);
MAKE_RESOURCE(IDB_WEATHER_STATION, 368);
MAKE_RESOURCE(IDB_WEATHER_STATION_HD, 5368);
MAKE_RESOURCE(IDB_THERMAL_HOTSPOT, 369);
MAKE_RESOURCE(IDB_THERMAL_HOTSPOT_HD, 5369);
MAKE_RESOURCE(IDB_VOR, 370);
MAKE_RESOURCE(IDB_VOR_HD, 5370);
MAKE_RESOURCE(IDB_NDB, 371);
MAKE_RESOURCE(IDB_NDB_HD, 5371);
MAKE_RESOURCE(IDB_DAM, 372);
MAKE_RESOURCE(IDB_DAM_HD, 5372);
MAKE_RESOURCE(IDB_CASTLE, 373);
MAKE_RESOURCE(IDB_CASTLE_HD, 5373);
MAKE_RESOURCE(IDB_INTERSECTION, 374);
MAKE_RESOURCE(IDB_INTERSECTION_HD, 5374);
MAKE_RESOURCE(IDB_REPORTING_POINT, 375);
MAKE_RESOURCE(IDB_REPORTING_POINT_HD, 5375);
MAKE_RESOURCE(IDB_PGTAKEOFF, 376);
MAKE_RESOURCE(IDB_PGTAKEOFF_HD, 5376);
MAKE_RESOURCE(IDB_PGLANDING, 377);
MAKE_RESOURCE(IDB_PGLANDING_HD, 5377);
MAKE_RESOURCE(IDB_RADIO, 378);
MAKE_RESOURCE(IDB_RADIO, 5378);

#ifdef USE_GDI
MAKE_RESOURCE(IDI_XCSOAR, 101);
MAKE_RESOURCE(IDB_ABOVETERRAIN, 321);
MAKE_RESOURCE(IDB_AIRSPACE, 235);
MAKE_RESOURCE(IDB_AIRSPACE0, 240);
MAKE_RESOURCE(IDB_AIRSPACE1, 241);
MAKE_RESOURCE(IDB_AIRSPACE2, 242);
MAKE_RESOURCE(IDB_AIRSPACE3, 280);
MAKE_RESOURCE(IDB_AIRSPACE4, 306);
MAKE_RESOURCE(IDB_AIRSPACE5, 311);
MAKE_RESOURCE(IDB_AIRSPACE6, 317);
MAKE_RESOURCE(IDB_AIRSPACE7, 318);
#endif

#undef MAKE_RESOURCE
