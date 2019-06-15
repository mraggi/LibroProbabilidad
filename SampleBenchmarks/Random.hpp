#pragma once

// #include "pcg.hpp"
#include <chrono>
#include <random>

template<class Engine>
class Random
{
public:
    Random() : engine_(std::chrono::high_resolution_clock::now().time_since_epoch().count())
    {
        //         auto t = std::chrono::high_resolution_clock::now();
        //         set_seed(t.time_since_epoch().count());
    }

    template <class IntF, class IntT>
    auto random_int(IntF from, IntT to)
    {
        using Int = std::common_type_t<IntF, IntT>;
        std::uniform_int_distribution<Int> d{};
        using parm_t = typename decltype(d)::param_type;
        return d(engine_, parm_t{from, --to});
    }

    double random_real(double from, double to)
    {
        std::uniform_real_distribution<double> d{};
        using parm_t = typename decltype(d)::param_type;
        return d(engine_, parm_t{from, to});
    }

    bool probability_of_true(double p)
    {
        std::bernoulli_distribution d(p);
        return d(engine_);
    }
    
    Engine engine_copy() const { return engine_; }
private:
    Engine engine_;
};
