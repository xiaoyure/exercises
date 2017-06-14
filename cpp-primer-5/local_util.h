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

    template<class T> std::function<T()> random_generator(T lower, T upper)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<T> distribution(lower, upper);
        return std::bind(distribution, generator);
    }

    template<class T> std::vector<T> random_vector(std::function<T()>& dice, size_t length, T lower, T upper)
    {
        std::vector<T> result(length);
        std::transform(result.begin(), result.end(), result.begin(),
                [&dice](T x) { return dice(); });
        return result;
    }

    template<class T> std::vector<T> random_vector(size_t length, T lower, T upper)
    {
        auto dice = random_generator(lower, upper);
        return random_vector(dice, length, lower, upper);
    }

    std::string random_string(size_t length, std::vector<char> charset)
    {
        auto dice = random_generator(0u, (unsigned) charset.size() - 1);
        std::string result(length, ' ');
        std::transform(result.begin(), result.end(), result.begin(),
                [&charset, &dice](char c) { return charset[dice()]; });
        return result;
    }

    template<class T> std::vector<T> step_vector(size_t length, T first, T step)
    {
        std::vector<int> result(length);
        first -= step;
        std::transform(result.begin(), result.end(), result.begin(),
                [&first, step] (T x) { return first += step; });
        return result;
    }
}

#endif
