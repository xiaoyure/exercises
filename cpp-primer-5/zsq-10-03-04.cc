#include "local_util.h"

bool size_ge(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

void find_first_ge(std::string& str, std::vector<int>& values)
{
    auto it = std::find_if_not(values.begin(), values.end(),
            std::bind(size_ge, std::cref(str), std::placeholders::_1));
    std::cout << "in array: ";
    cpp5::output_container(values.begin(), values.end());
    if (it == values.end()) {
        std::cout << "no one is grater than " << str.size();
    }
    else {
        std::cout << (*it) << " is the first value greater than "
            << str.size() << std::endl;
    }
}

void biggies(std::vector<std::string> &words,
        std::vector<std::string>::size_type sz)
{
    std::sort(words.begin(), words.end());
    words.erase(std::unique(words.begin(), words.end()), words.end());
    auto it = std::stable_partition(words.begin(), words.end(),
            std::bind(size_ge, std::placeholders::_1, sz));
    auto count = it - words.begin();
    std::cout << count << " word(s) with its length >= " << sz << "\n";
    cpp5::output_container(words.begin(), it);
}

int main()
{
    auto size_ge6 = std::bind(size_ge, std::placeholders::_1, 6);
    std::string str(7, 'a');
    std::cout << size_ge6(str) << std::endl;

    // values have to be nature number for size_ge use a unsigned parameter
    // 'sz'
    auto values = cpp5::random_vector(10, 0, 10);
    str = "text";
    find_first_ge(str, values);

    std::vector<std::string> words = {
        "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };
    biggies(words, 4);
    return 0;
};

