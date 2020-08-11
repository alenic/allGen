#include "realgene.hpp"

using namespace allgen;

template<class RealType>
RealGene<RealType>::RealGene(RealType t_lower_value, RealType t_upper_value)
{
    m_value = (t_lower_value + t_upper_value)/2.0;
}

template<class RealType>
void RealGene<RealType>::mutate(float t_intensity)
{
    //intensity is
}
