#ifndef _CPP_PRIMER_5_UTIL_
#define _CPP_PRIMER_5_UTIL_

#include <bits/stdc++.h>

namespace cpp5 {
    //
    //
    template<class Iter> void output_container(std::ostream& out, Iter begin, Iter end) {
        if (begin == end) {
            return;
        }
        Iter it = begin;
        out << (*it++);
        for (; it != end; ++it) {
            out << " " << (*it);
        }
        out << std::endl;
    }

    template<class Iter> void output_container(Iter begin, Iter end) {
        output_container(std::cout, begin, end);
    }
}

#endif
