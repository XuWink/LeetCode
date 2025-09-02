/*只能在堆上创建对象，不能在栈上创建对象*/

#include <iostream>

class HeapObj {

  public:
    static HeapObj * create() { return new HeapObj(); }

    void destory() { delete this; }

    void doSomething() { std::cout << "只能在堆上创建对象，不能在栈上创建对象" << std::endl; }

  private:
    // 私有构造函数和析构函数，禁止栈上分配
    HeapObj() {}

    ~HeapObj() {}

    HeapObj(const HeapObj &)             = delete;
    HeapObj & operator=(const HeapObj &) = delete;
};

int main() {
    HeapObj * obj = HeapObj::create();
    obj->doSomething();
    obj->destory();

    // HeapObj obj1;  // 报错
}
