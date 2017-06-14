#include "local_util.h"

void distribute(std::string path_src, std::string path_odd, std::string path_even)
{
    std::fstream file_src(path_src.c_str(), std::ios::in);
    std::fstream file_odd(path_odd.c_str(), std::ios::out);
    std::fstream file_even(path_even.c_str(), std::ios::out);

    std::istream_iterator<int> input_src(file_src);
    std::istream_iterator<int> eof;
    std::ostream_iterator<int> output_odd(file_odd, "\n");
    std::ostream_iterator<int> output_even(file_even, "\n");

    std::vector<int> buffer(input_src, eof);
    auto it = std::partition(buffer.begin(), buffer.end(), [](int x) { return !(x % 2); });
    std::copy(buffer.begin(), it, output_even);
    std::copy(it, buffer.end(), output_odd);
}

int main()
{
    std::istream_iterator<int> input_int(std::cin), eof_int;
    std::vector<int> values(input_int, eof_int);
    cpp5::output_container(values.begin(), values.end());

    std::cout << "The sum of them is:\n";
    std::cout << std::accumulate(values.begin(), values.end(), 0) << std::endl;

    // lazy evaluation... can not understand
    
    std::ostream_iterator<int> output_int(std::cout, " ");
    std::copy(values.begin(), values.end(), output_int);
    std::cout << std::endl;

    std::fstream file_text("text.txt", std::ios::in);
    std::istream_iterator<std::string> input_string(file_text), eof_string;
    std::vector<std::string> text(input_string, eof_string);
    cpp5::output_container(text.begin(), text.end());
    file_text.close();

    std::fstream file_number("numbers.txt", std::ios::in);
    std::istream_iterator<int> input_int2(file_number);
    std::vector<int> values2;
    std::copy(input_int2, eof_int, std::back_inserter(values2));
    std::sort(values2.begin(), values2.end());
    cpp5::output_container(values2.begin(), values2.end());
    std::unique_copy(values2.begin(), values2.end(), output_int);
    std::cout << std::endl;
    file_number.close();

    distribute("numbers.txt", "odd.txt", "even.txt");

    return 0;
}
