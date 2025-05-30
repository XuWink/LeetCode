
```C++

#include <iostream>
#include <memory>
#include <mutex>

class Singleton{
private:
	Singleton(){
		std::cout<<"单例模式的构造函数"<<std::endl;	
	}
	
	static std::mutex _mtx;
	static std::shared_ptr<Singleton> _instance;
	
public:
	
	~Singleton(){
		std::cout<<"单例模式的析构函数"<<std::endl;
	}
	
	//删除拷贝构造函数和赋值运算符函数
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete; 
	
	static std::shared_ptr<Singleton> getSingleton(){
		if(_instance == nullptr){
		
			std::unique_lock<std::mutex> lock(_mtx);
			if(_instance == nullptr){
				_instance = std::shared_ptr<Singleton>(new Singleton());
			}
			
		}
		return _instance;
	}
	
	void doSomething(){
		std::cout<<"do something..."<<std::endl;	
	}
	
};

std::shared_ptr<Singleton> Singleton::_instance = nullptr;
std::mutex Singleton::_mtx;


int main()
{
   Singleton::getSingleton()->doSomething();
   return 0;
}

```