#include "local_util.h"

void elim_dups_in_forward_list(std::forward_list<std::string> &words)
{
    words.sort();
    words.unique();
    cpp5::output_container(words.begin(), words.end());
}

int main()
{
    std::forward_list<std::string> words = {
        "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };
    elim_dups_in_forward_list(words);
    return 0;
}
