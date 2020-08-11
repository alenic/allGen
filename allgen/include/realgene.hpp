#ifndef REALGENE_H
#define REALGENE_H

#include <string>
#include "gene.hpp"
#include "stat.hpp"

namespace allgen {

typedef enum {REAL_MUTATION_UNIFORM=0, REAL_MUTATION_GAUSSIAN} RealMutationType;

    template <class RealType>
    class RealGene: Gene {
    public:
        RealGene(RealType t_min_value, RealType t_max_value);
        void mutate(float t_intensity) override;
        void random() override;
        void setMutation(const std::string &t_mutation);
    private:
        RealType m_value;
        RealType m_min_value;
        RealType m_max_value;
        RealMutationType m_mutation;
    };

    typedef RealGene<float> FloatGene;
    typedef RealGene<double> DoubleGene;

}

#endif // REALGENE_H
