#include "stat.hpp"
#include <stdlib.h>
#include <limits>

using namespace allgen;

template <class RealType>
RealType Stat<RealType>::uniformRand() {
  return (RealType)rand() / (RAND_MAX + 1.0);
}

template <class RealType>
int Stat<RealType>::uniformIndex(int t_n) {
  return rand() % t_n;
}

template <class RealType>
void Stat<RealType>::setSeed(unsigned int t_seed) {
  srand(t_seed);
}

template <class RealType>
RealType Stat<RealType>::uniformRand(RealType t_min_value, RealType t_max_value) {
  return (t_max_value-t_min_value)*uniformRand() + t_min_value;
}

template <class RealType>
RealType Stat<RealType>::gaussianRand(RealType t_mean, RealType t_std) {
  
  float x1, x2, w, y1;
  static float y2;
  static int use_last = 0;

  if (use_last)       
  {
    y1 = y2;
    use_last = 0;
  }
  else
  {
    do {
      x1 = 2.0 * uniformRand() - 1.0;
      x2 = 2.0 * uniformRand() - 1.0;
      w = x1 * x1 + x2 * x2;
    } while ( w >= 1.0 );

    w = sqrt( (-2.0 * log( w ) ) / w );
    y1 = x1 * w;
    y2 = x2 * w;
    use_last = 1;
  }
  
  return( t_mean + y1 * t_std );
}
