#ifndef AIRSPACECIRCLE_HPP
#define AIRSPACECIRCLE_HPP

#include "AbstractAirspace.hpp"

class AirspaceCircle: public AbstractAirspace 
{
public:
  AirspaceCircle(const GEOPOINT &loc, const double _radius);

  const FlatBoundingBox get_bounding_box(const TaskProjection& task_projection) const;

  bool inside(const AIRCRAFT_STATE &loc) const;

  friend std::ostream& operator<< (std::ostream& f, 
                                   const AirspaceCircle& as);

private:
  const GEOPOINT center;
  const double radius;
};


#endif
