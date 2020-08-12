#include "realgene.hpp"
#include <vector>
#include <iostream>

using namespace allgen;
using namespace std;

template<class RealType>
RealGene<RealType>::~RealGene()
{

}

template<class RealType>
RealGene<RealType>::RealGene(RealType t_min_value, RealType t_max_value)
{
    m_value = (t_min_value + t_max_value)/2.0;
    m_min_value = t_min_value;
    m_max_value = t_max_value;
    m_mutation = "uniform";
}

template<class RealType>
void RealGene<RealType>::mutate(float t_intensity)
{
    if(m_mutation == REAL_MUTATION_UNIFORM) {
        RealType half_interval = 0.5*t_intensity*(m_max_value-m_min_value);
        m_value = Stat<RealType>::uniformRand(m_value - half_interval, m_value + half_interval);
        if(m_value < m_min_value) m_value = m_min_value;
        if(m_value > m_max_value) m_value = m_max_value;
    } else if(m_mutation == REAL_MUTATION_GAUSSIAN) {
        // TODO
        cerr << "Error: gaussian mutation must be implemented!" << endl;
    }
}

template<class RealType>
void RealGene<RealType>::random()
{
    m_value = Stat<RealType>::uniformRand(m_min_value, m_max_value);
}

template<class RealType>
void RealGene<RealType>::setMutation(const std::string &t_mutation)
{
    if(t_mutation == "uniform") {
        m_mutation = REAL_MUTATION_UNIFORM;
    } else if(t_mutation == "gaussian") {
        m_mutation = REAL_MUTATION_GAUSSIAN;
    } else {
        cerr << "Error: Invalid mutation type: " << t_mutation << endl;
    }
}

template<class RealType>
RealType RealGene<RealType>::getValue() const
{
    return m_value;
}

template<class RealType>
void RealGene<RealType>::setValue(const RealType &value)
{
    m_value = value;
}
