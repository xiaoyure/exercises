#include "local_util.h"

void copy_work(std::vector<int>& src, std::list<int>& dst)
{
    std::sort(src.begin(), src.end());
    std::unique_copy(src.begin(), src.end(), std::back_inserter(dst));
}

int main()
{
    std::vector<int> src = cpp5::random_vector(20, -5, 5);
    std::list<int> dst;
    copy_work(src, dst);

    cpp5::output_container(src.begin(), src.end());
    cpp5::output_container(dst.begin(), dst.end());

    std::vector<int> inc(9);
    for (int i = 0; i < inc.size(); ++i) {
        inc[i] = i + 1;
    }
    cpp5::output_container(inc.begin(), inc.end());

    std::forward_list<int> list1;
    std::copy(inc.begin(), inc.end(), std::front_inserter(list1));
    cpp5::output_container(list1.begin(), list1.end());

    std::list<int> list2;
    std::copy(inc.begin(), inc.end(), std::back_inserter(list2));
    cpp5::output_container(list2.begin(), list2.end());

    std::vector<int> list3;
    std::copy(inc.begin(), inc.end(), std::inserter(list3, list3.begin()));
    cpp5::output_container(list3.begin(), list3.end());

    return 0;
}
