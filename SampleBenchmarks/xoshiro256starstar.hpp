/*  Written in 2018 by David Blackman and Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

#include <cstdint>
#include <array>

/* This is xoshiro256** 1.0, our all-purpose, rock-solid generator. It has
   excellent (sub-ns) speed, a state (256 bits) that is large enough for
   any parallel application, and it passes all tests we are aware of.

   For generating just floating-point numbers, xoshiro256+ is even faster.

   The state must be seeded so that it is not everywhere zero. If you have
   a 64-bit seed, we suggest to seed a splitmix64 generator and use its
   output to fill s. */

class xoshiro256starstar
{
public:
    using result_type = uint64_t;
    static constexpr result_type(min)() { return 0; }
    static constexpr result_type(max)() { return UINT64_MAX; }
    explicit xoshiro256starstar(uint64_t seed0, uint64_t seed1 = 21406692542301193ULL, uint64_t seed2 = 18446744073709551427ULL, uint64_t seed3 = 6255165016499934569ULL) : s{seed0,seed1,seed2,seed3}
    {
        operator()();
    }

    uint64_t operator()()
    {
        const uint64_t result_starstar = rotl(s[1] * 5, 7) * 9;

        const uint64_t t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return result_starstar;
    }
    
    
private:
    inline uint64_t rotl(const uint64_t x, int k)
    {
        return (x << k) | (x >> (64 - k));
    }

    
    std::array<uint64_t,4> s;
};


