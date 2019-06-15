#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include "TimeHelpers.hpp"
#include "VectorHelpers.hpp"
#include "Misc.hpp"
#include <set>
#include <unordered_set>

using namespace std;


template <class RAContainer>
auto random_sample_shuffle(const RAContainer& population, int k)
{
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;

    std::vector<T> sample(population.begin(), population.end());
	for (int i = 0; i < k; ++i)
	{
		int j = random_int(i,n);
// 		cout << i << ", " << j << endl;
		std::swap(sample[i],sample[j]);
	}
	
// 	cout << "Erasing:" << endl;
	sample.erase(sample.begin()+k,sample.end());
// 	cout << "Done!" << endl;

    return sample;
}

template <class RAContainer>
auto random_sample_set(const RAContainer& population, int k)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;

    std::vector<T> sample;
    sample.reserve(k);

    // END BOILERPLATE

    std::set<size_t> explored;

    while (explored.size() < k)
    {
        size_t i = random_int<size_t>(0, population.size());
        explored.insert(i);
        sample.emplace_back(population[i]);
    }


    return sample;
}

template <class RAContainer>
auto random_sample_unordered_set(const RAContainer& population, int k)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;

    std::vector<T> sample;
    sample.reserve(k);

    // END BOILERPLATE

    std::unordered_set<size_t> explored;

    while (explored.size() < k)
    {
        size_t i = random_int<size_t>(0, population.size());
        explored.insert(i);
        sample.emplace_back(population[i]);
    }

    return sample;
}

template <class RAContainer>
auto random_sample_array(const RAContainer& population, int k)
{
    // BEGIN BOILERPLATE
    using T = typename RAContainer::value_type;

    int n = population.size();

    if (k > n)
        k = n;

    std::vector<T> sample;
    sample.reserve(k);

    // END BOILERPLATE

    std::vector<char> explored(n, 0);

    while (sample.size() < k)
    {
        size_t i = random_int<size_t>(0, n);

        if (explored[i] == 0)
        {
            explored[i] = 1;
            sample.emplace_back(population[i]);
        }
    }

    return sample;
}

template <class RAContainer>
auto random_sample_online(const RAContainer& population, int k)
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
        if (probability_of_true(p))
        {
            sample.emplace_back(population[i]);
            --k;
			if (k == 0)
				break;
        }
    }

    return sample;
}

