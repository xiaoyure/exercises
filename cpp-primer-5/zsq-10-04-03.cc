#include "local_util.h"

int main()
{
    std::string line = "first,middle,last";
    auto comma = std::find(line.begin(), line.end(), ',');
    auto rcomma = std::find(line.rbegin(), line.rend(), ',');
    std::cout << std::string(line.begin(), comma) << std::endl; // first
    std::cout << std::string(line.rbegin(), rcomma) << std::endl; // tsal
    std::cout << std::string(rcomma.base(), line.end()) << std::endl; // last

    std::vector<char> char_seq(line.begin(), line.end());
    cpp5::output_container(char_seq.rbegin(), char_seq.rend());

    std::list<int> lst = {-1, 0, 1, 2, 1, 0, -1};
    auto last_zero = std::find(lst.rbegin(), lst.rend(), 0);
    cpp5::output_container(lst.rbegin(), last_zero);
    cpp5::output_container(last_zero, lst.rend());

    std::vector<int> vec = cpp5::step_vector(10, 0, 1);
    cpp5::output_container(vec.begin(), vec.end());

    std::list<int> lst2;
    std::copy(vec.rbegin() + 3, vec.rbegin() + 8, std::back_inserter(lst2));
    cpp5::output_container(lst2.begin(), lst2.end());
    return 0;
}
