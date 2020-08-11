#ifndef GENE_H
#define GENE_H

namespace allgen {

    class Gene {
    public:
        virtual void mutate(float t_intensity) = 0;
        virtual void random() = 0;
    };

}

#endif // GENE_H
