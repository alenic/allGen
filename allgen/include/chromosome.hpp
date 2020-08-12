#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "gene.hpp"
#include <vector>

namespace allgen {

    class Chromosome
    {
    public:
        Chromosome();
        void pushGene(Gene *t_gene);
        void mutate(float t_intensity);
        void mutate(int t_index, float t_intensity);
        void random();
        void random(int t_index);
    private:
        std::vector<Gene *> m_genes;
        double m_fitness_value;
    };

}

#endif // CHROMOSOME_H
