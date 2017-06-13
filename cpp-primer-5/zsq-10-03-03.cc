#include "local_util.h"

int main()
{
    int x = 10;

    // capture of a variable is read-only
    // auto lambda = [x](int i) { return x += 10; }
    // error: assignment of a read-only variable 'x'

    auto lambda_mutable = [x] () mutable { return x += 10; };
    // this lambda will not change the value of x outside
    std::cout << lambda_mutable() << std::endl;
    std::cout << x << std::endl; // 10

    //   page 353 says that lambda without explict return type will be return
    // void if the body of it is not a return-expression
    //   but this donnot happened under my compiler.
    auto lambda_complex = [](int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    };

    auto rands = cpp5::random_vector(10, -10, 10);
    cpp5::output_container(rands.begin(), rands.end(), '\t');
    std::cout << std::count_if(rands.begin(), rands.end(), [](int x) { return x < 0; })
        << " numbers is less then 0\n";
    std::transform(rands.begin(), rands.end(), rands.begin(),
            [](int i) { return i < 0 ? -i : i; });
    cpp5::output_container(rands.begin(), rands.end(), '\t');

    int u = 10;
    auto lambda = [&u]() { return !(u -= !!u); };
    for (; not lambda(); ) {
        std::cout << "u=" << u << std::endl;
    }
    return 0;
}
