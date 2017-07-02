
///6.2 参数传递

/*
使用引用避免拷贝拷贝
若要编写一个函数比较两个string的长度，由于string对象可能非常长，所以应该尽量
避免直接拷贝他们，此时使用形参是比较明智的选择。
*/
//如果函数无需改变引用形参的值，最好将其声明为常量
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

/*
数组引用形参
*/
void print(int (&arr)[10])
{
    for (auto elem: arr)
        cout << elem << endl;
}
//arr两端的括号必不可少
f(int &arr[10])   //错误：将arr声明成了引用的数据
f(int (&arr)[10]) //正确：arr是具有10个整数的整型数组的引用

int *matrix[10];    //10个指针构成的数组
int (*matrix)[10];  //指向含有10个整数的数组的指针



///6.5

//默认实参
/*
在给定的作用域中，一个形参只能被赋予一次默认实参。
换句话说，函数的后续声明只能为之前那些没有默认值的形参添加默认实参，
而且该形参右侧所有形参必须有默认值。
*/
string screen(sz, sz, char = ' ');
string screen(sz, sz, char = '*');              //错误：重复声明
string screen(sz = 24, sz = 80, char = ' ');    //正确：添加默认实参

//assert预处理宏
/*
对expr求值，若表达式为假，assert输出信息并终止程序的执行。
常用语检查“不能发生”的条件
*/
assert(expr);



///6.7函数指针
//为啥遇到指针就懵呢= =
