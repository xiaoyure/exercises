#ifndef _CPP_PRIMER_5_UTIL_
#define _CPP_PRIMER_5_UTIL_

#include <bits/stdc++.h>

namespace cpp5
{
    template<class Iter> void output_container(std::ostream& out, Iter begin, Iter end, char sep=' ')
    {
        if (begin == end) {
            return;
        }
        Iter it = begin;
        out << (*it++);
        for (; it != end; ++it) {
            out << sep << (*it);
        }
        out << std::endl;
    }

    template<class Iter> void output_container(Iter begin, Iter end, char sep=' ')
    {
        output_container(std::cout, begin, end, sep);
    }

    template<class T> std::vector<T> random_vector(size_t length, T lower, T upper)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<T> distribution(lower, upper);
        std::vector<T> result(length);
        auto dice = std::bind(distribution, generator);
        std::transform(result.begin(), result.end(), result.begin(),
                [&dice](T x) { return dice(); });
        return result;
    }
}

#endif
