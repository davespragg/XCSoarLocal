#include "GlideResult.hpp"
#include "GlideState.hpp"
#include <math.h>
#include "Math/NavFunctions.hpp"

GLIDE_RESULT::GLIDE_RESULT(const GLIDE_STATE &task, 
                           const double V):
    Solution(RESULT_NOSOLUTION),
    Vector(task.Vector),
    DistanceToFinal(task.Vector.Distance),
    CruiseTrackBearing(task.Vector.Bearing),
    VOpt(V),
    HeightClimb(0.0),
    HeightGlide(0.0),
    TimeElapsed(0.0),
    TimeVirtual(0.0),
    AltitudeDifference(task.AltitudeDifference),
    EffectiveWindSpeed(task.EffectiveWindSpeed),
    EffectiveWindAngle(task.EffectiveWindAngle)
{
}


void
GLIDE_RESULT::calc_cruise_bearing()
{
  CruiseTrackBearing= Vector.Bearing;
  if (EffectiveWindSpeed>0.0) {
    const double sintheta = sin(DEG_TO_RAD*EffectiveWindAngle);
    if (sintheta==0.0) {
      return;
    }
    // Wn/sin(alpha) = V/sin(theta)
    //   (Wn/V)*sin(theta) = sin(alpha)
    CruiseTrackBearing += RAD_TO_DEG*asin(sintheta*EffectiveWindSpeed/VOpt);
  }
}



void 
GLIDE_RESULT::add(const GLIDE_RESULT &s2) 
{
  TimeElapsed += s2.TimeElapsed;
  HeightGlide += s2.HeightGlide;
  HeightClimb += s2.HeightClimb;
  Vector.Distance += s2.Vector.Distance;
  DistanceToFinal += s2.DistanceToFinal;
  TimeVirtual += s2.TimeVirtual;

  if ((AltitudeDifference<0) || (s2.AltitudeDifference<0)) {
    AltitudeDifference= std::min(s2.AltitudeDifference+AltitudeDifference,
      AltitudeDifference);
  } else {
    AltitudeDifference= std::min(s2.AltitudeDifference, AltitudeDifference);
  }
}


double 
GLIDE_RESULT::calc_vspeed(const double mc) 
{
  if (!ok_or_partial()) {
    TimeVirtual = 0.0;
    return 1.0e6;
  }
  if (Vector.Distance>0.0) {
    if (mc>0.0) {
      // equivalent time to gain the height that was used
      TimeVirtual = HeightGlide/mc;
      return (TimeElapsed+TimeVirtual)/Vector.Distance;
    } else {
      TimeVirtual = 0.0;
      // minimise 1.0/LD over ground 
      return -HeightGlide/Vector.Distance;
    }
  } else {
    TimeVirtual = 0.0;
    return 0.0;
  }
}

double 
GLIDE_RESULT::glide_angle_ground() const
{
  if (Vector.Distance>0) {
    return HeightGlide/Vector.Distance;
  } else {
    return 100.0;
  }
}

