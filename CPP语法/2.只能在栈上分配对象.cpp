/*禁用在堆上创建对象，只能在栈上创建对象*/
#include <iostream>

class StackObj
{

public:
    StackObj() = default;
    ~StackObj() = default;

    void doSomething()
    {
        std::cout << "禁用在堆上创建对象，只能在栈上创建对象" << std::endl;
    }

private:
    // 禁用 new 和 delete
    static void *operator new(size_t) = delete;
    static void operator delete(void *) = delete;

    StackObj(const StackObj &) = delete;
    StackObj &operator=(const StackObj &) = delete;
};

int main()
{
    StackObj obj;
    obj.doSomething();

    // StackObj obj1 = new StackObj(); // 会报错
    // obj1->doSomething();

    return 0;
}