#include <iostream>

using namespace std;

class A{
public:
    A(){
        std::cout << "执行 A 的构造函数" << std::endl;
    }

    virtual ~A(){
        std::cout << "执行 A 的析构函数" << std::endl;
    }

    virtual void use(){
        std::cout << "调用 A 的use()函数" << std::endl;
    }
};

class B : virtual public A{
public:
    B(){
        std::cout << "执行 B 的构造函数" << std::endl;
    }

    ~B() override {
        std::cout << "执行 B 的析构函数" << std::endl;
    }
};

class C : virtual public A{
public:
    C(){
        std::cout << "执行 C 的构造函数" << std::endl;
    }

    ~C() override {
        std::cout << "执行 C 的析构函数" << std::endl;
    }
};

class D : public B, public C{
public:
    D(){
        std::cout << "执行 D 的构造函数" << std::endl;
    }

    ~D(){
        std::cout << "执行 D 的析构函数" << std::endl;
    }

    void use() override {
        std::cout << "调用 D.use()函数" << std::endl;
    }
};

int main(int agrc, char** argv){
    D d;
    d.use();
    return 0;

}