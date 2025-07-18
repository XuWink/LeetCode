#include <iostream>

template <typename T>
class my_unique_ptr
{
private:
    T* raw_ptr;
public:
    explicit my_unique_ptr(T* ptr = nullptr) : raw_ptr(ptr) {}
    ~my_unique_ptr() {
        delete raw_ptr;
    }

    // 禁止拷贝
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    // 移动语义
    my_unique_ptr(my_unique_ptr&& other) : raw_ptr(other.raw_ptr) {
        other.raw_ptr = nullptr;
    }
    my_unique_ptr& operator=(my_unique_ptr&& other) {
        if (this != &other) {
            delete raw_ptr;
            raw_ptr = other.raw_ptr;
            other.raw_ptr = nullptr;
        }
        return *this; // 添加返回语句
    }

    // get
    T* get() const {
        return raw_ptr;
    }

    // release but do not release memory
    T* release() {
        T* temp = raw_ptr;
        raw_ptr = nullptr;
        return temp;
    }

    // reset
    void reset(T* ptr = nullptr) {
        delete raw_ptr;
        raw_ptr = ptr; // 修正参数名称
    }
};