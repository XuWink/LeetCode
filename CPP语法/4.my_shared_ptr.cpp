template <typename T>
class SharedPtr {
private:
    T* ptr;               // 原始指针
    int* ref_count;       // 引用计数（存储在控制块中）

    // 辅助函数：释放资源
    void cleanup() {
        (*ref_count)--;
        if (*ref_count == 0) {
            delete ptr;
            delete ref_count;  // 释放控制块
        }
    }

public:
    // 构造函数
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}

    // 拷贝构造（增加引用计数）
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
    }

    // 拷贝赋值（增加引用计数）
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            cleanup();          // 释放当前资源
            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    // 析构函数（减少引用计数）
    ~SharedPtr() {
        cleanup();
    }

    // 解引用操作
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // 获取原始指针
    T* get() const { return ptr; }

    // 获取引用计数
    int use_count() const { return *ref_count; }
};