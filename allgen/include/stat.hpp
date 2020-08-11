#ifndef STAT_H
#define STAT_H


namespace allgen {

    template <class RealType>
    class Stat {
    public:
      static RealType uniformRand();
      static RealType uniformRand(RealType t_min_value, RealType t_max_value);
      static RealType gaussianRand(RealType t_mean, RealType t_std);
      static int uniformIndex(int t_n);
      static void setSeed(unsigned int t_seed);
    };


    typedef Stat<float> FloatStat;
    typedef Stat<double> DoubleStat;

}
#endif // STAT_H
