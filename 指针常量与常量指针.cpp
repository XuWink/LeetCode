#include <iostream>

using namespace std;

int main() 
{
    int a = 10;
    int b = 20;

    // 常量指针，常量不可变
    const int *p1 = &a;
    // *p1 = 15; 错误
    p1 = &b;
    cout << "p1 = " << *p1 << endl; // 20

    // 指针常量，指针不可变
    int * const p2 = &b;
    *p2 = 17;
    // p2 = &a; 错误
    cout << "p2 = " << *p2 <<endl; //17


}

/*
常量指针与指针常量的记忆方法

读法：
    const double *ptr;     //const读作常量，*读作指针，按照顺序读作常量指针
    double * const ptr;     //const读作常量，*读作指针，按照顺序读作指针常量

    const靠近*还是double,那么谁就是不变的。
    const靠近谁，谁不变，靠近*则指针不可变，靠近double则数不可变

*/