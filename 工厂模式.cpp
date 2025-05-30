#include <iostream>
#include <memory>

class Product{
public:
	virtual void use() const = 0;
	virtual ~Product() = default;
};

class ProductA : public Product{
public:
	void use() const override{
		std::cout << "Using ProductA" << std::endl;
	}
};

class ProductB : public Product{
public:
	void use() const override {
        std::cout << "Using ProductB" << std::endl;
    }
};

class Creator{
public:
	virtual std::unique_ptr<Product> createProduct() const = 0;
	virtual ~Creator() = default;
};

class ConcreteCreatorA : public Creator{
public:
	std::unique_ptr<Product> createProduct() const override{
		return std::make_unique<ProductA>();
	}
};

class ConcreteCreatorB : public Creator{
public:
	std::unique_ptr<Product> createProduct() const override{
		return std::make_unique<ProductA>();
	}

};

int main(){
	ConcreteCreatorA creatorA;
	auto productA = creatorA.createProduct();
	productA->use();
	
	ConcreteCreatorB creatorB;
	auto productB = creatorB.createProduct();
	productB->use();	
	
	return 0;
}