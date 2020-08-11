#ifndef REALGENE_H
#define REALGENE_H

#include "gene.hpp"

namespace allgen {

    template <class RealType>
    class RealGene: Gene {
    public:
        RealGene(RealType t_lower_value, RealType t_upper_value);
        void mutate(float t_intensity) override;
        void random() override;
    private:
        RealType m_value;
    };

}

#endif // REALGENE_H
