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