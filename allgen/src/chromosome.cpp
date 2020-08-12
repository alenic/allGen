#include "chromosome.hpp"

using namespace allgen;

Chromosome::Chromosome()
{
    m_fitness_value = 0.0;
}

void Chromosome::pushGene(Gene *t_gene)
{
    m_genes.push_back(t_gene);
}

void Chromosome::mutate(int t_index, float t_intensity)
{
    m_genes[t_index]->mutate(t_intensity);
}

void Chromosome::random()
{
    for(size_t i=0; i<m_genes.size(); i++) {
        m_genes[i]->random();
    }
}

void Chromosome::random(int t_index)
{
    m_genes[t_index]->random();
}
