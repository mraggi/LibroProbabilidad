#include "SageBenchmarker.hpp"
#include "Random.hpp"
#include "do_not_optimize.hpp"
#include "pcg.hpp"
#include "xoshiro256starstar.hpp"

const int n = 500000;
const int num_steps = 16;

struct LargeStruct
{
    LargeStruct(int k=0) {}
    std::array<long, 30> W;
};

template <class RAContainer, class RNG>
auto random_sample_online(const RAContainer& population, int k, RNG& rand_xo)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;

    std::vector<T> sample;
    sample.reserve(k);

    // END BOILERPLATE

    for (int i = 0; i < n; ++i)
    {
        double p = double(k) / (n - i);
        if (rand_xo.probability_of_true(p))
        {
            sample.emplace_back(population[i]);
            --k;
			if (k == 0)
				break;
        }
    }

    return sample;
}

template <class RAContainer, class RNG>
auto random_sample_shuffle(const RAContainer& population, int k, RNG& rand_xo)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;

    // END BOILERPLATE
    std::vector<T> sample(population.begin(), population.end());
	for (int i = 0; i < k; ++i)
	{
		int j = rand_xo.random_int(i,n);
		std::swap(sample[i],sample[j]);
	}
	
	sample.erase(sample.begin()+k,sample.end());

    return sample;
}

template <class RAContainer, class RNG>
auto random_sample_shuffle_indices(const RAContainer& population, int k, RNG& rand_xo)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;
    // END BOILERPLATE
    
    std::vector<int> sample_indices(n);
    std::iota(sample_indices.begin(), sample_indices.end(), 0);
    
	for (int i = 0; i < k; ++i)
	{
		int j = rand_xo.random_int(i,n);
		std::swap(sample_indices[i],sample_indices[j]);
	}
    
    std::vector<T> sample;
    sample.reserve(k);
    for (int i = 0; i < k; ++i)
        sample.emplace_back(population[sample_indices[i]]);

    return sample;
}

template <class RAContainer, class RNG>
auto random_sample_array(const RAContainer& population, int k, RNG& rand_xo)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;
    // END BOILERPLATE

    std::vector<T> sample;
    sample.reserve(k);

    std::vector<char> explored(n, 0);

    while (sample.size() < k)
    {
        int i = rand_xo.random_int(0, n);

        if (!explored[i])
        {
            explored[i] = 1;
            sample.emplace_back(population[i]);
        }
    }

    return sample;
}

template <class RAContainer, class RNG>
auto random_sample_std(const RAContainer& population, int k, RNG& rand)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;
    // END BOILERPLATE

    std::vector<T> sample;
    sample.reserve(k);

    std::sample(population.begin(), population.end(),std::back_inserter(sample), k, rand.engine_copy());

    return sample;
}

int main()
{
    Random<xoshiro256starstar> rand_xo;
    Random<pcg> rand_pcg;
    Random<std::default_random_engine> rand_lcg;

// 	std::vector<LargeStruct> A(n);
	std::vector<long> A(n);
	std::generate(A.begin(), A.end(), [&rand_lcg](){ return rand_lcg.random_int(0L,10L); });
	
	SageBenchmarker S(1,n,num_steps);
	
	S.set_time_unit(SageBenchmarker::milliseconds);
    
    S.add_benchmark("Shuffle lcg",[&A,&rand_lcg](int k)
	{		
		DoNotOptimize(random_sample_shuffle(A,k,rand_lcg));
	});
    
    S.add_benchmark("Shuffle xoshiro",[&A,&rand_xo](int k)
	{		
		DoNotOptimize(random_sample_shuffle(A,k,rand_xo));
	});
    
    S.add_benchmark("Shuffle pcg",[&A,&rand_pcg](int k)
	{		
		DoNotOptimize(random_sample_shuffle(A,k,rand_pcg));
	});
    
    S.add_benchmark("Array lcg",[&A,&rand_lcg](int k)
	{		
		DoNotOptimize(random_sample_array(A,k,rand_lcg));
	});
    
    S.add_benchmark("Array xoshiro",[&A,&rand_xo](int k)
	{		
		DoNotOptimize(random_sample_array(A,k,rand_xo));
	});
    
    S.add_benchmark("Array pcg",[&A,&rand_pcg](int k)
	{		
		DoNotOptimize(random_sample_array(A,k,rand_pcg));
	});
    
    S.add_benchmark("Online lcg",[&A,&rand_lcg](int k)
	{		
		DoNotOptimize(random_sample_online(A,k,rand_lcg));
	});
    
    S.add_benchmark("Online xoshiro",[&A,&rand_xo](int k)
	{		
		DoNotOptimize(random_sample_online(A,k,rand_xo));
	});
    
    S.add_benchmark("Online pcg",[&A,&rand_pcg](int k)
	{		
		DoNotOptimize(random_sample_online(A,k,rand_pcg));
	});
    
    
    S.add_benchmark("std::sample lcg",[&A,&rand_lcg](int k)
	{		
		DoNotOptimize(random_sample_std(A,k,rand_lcg));
	});
    
    S.add_benchmark("std::sample xoshiro",[&A,&rand_xo](int k)
	{		
		DoNotOptimize(random_sample_std(A,k,rand_xo));
	});
    
    S.add_benchmark("std::sample pcg",[&A,&rand_pcg](int k)
	{		
		DoNotOptimize(random_sample_std(A,k,rand_pcg));
	});
    
    S.add_benchmark("Shuffle indices lcg",[&A,&rand_lcg](int k)
	{		
		DoNotOptimize(random_sample_shuffle_indices(A,k,rand_lcg));
	});
    
    S.add_benchmark("Shuffle indices xoshiro",[&A,&rand_xo](int k)
	{		
		DoNotOptimize(random_sample_shuffle_indices(A,k,rand_xo));
	});
    
    S.add_benchmark("Shuffle indices pcg",[&A,&rand_pcg](int k)
	{		
		DoNotOptimize(random_sample_shuffle_indices(A,k,rand_pcg));
	});

    S.set_ymax(20);
	S.print_plot_commands();
	
	return 0;
}
