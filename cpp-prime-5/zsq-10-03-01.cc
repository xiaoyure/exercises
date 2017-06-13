#include "local_util.h"

void elim_dups(std::vector<std::string> &words)
{
    std::sort(std::begin(words), std::end(words));
    auto new_end = std::unique(std::begin(words), std::end(words));
    words.erase(new_end, std::end(words));
}

bool word_shorter(const std::string& fst, const std::string& sec)
{
    return fst.size() < sec.size();
}

bool size_ge5(const std::string& word)
{
    return word.size() >= 5U;
}

int main()
{
    std::vector<std::string> words = {
        "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle"
    };
    elim_dups(words);
    std::stable_sort(words.begin(), words.end(), word_shorter);
    cpp5::output_container(words.begin(), words.end());
    auto separation = std::partition(words.begin(), words.end(), size_ge5);
    cpp5::output_container(words.begin(), separation);
    return 0;
}

