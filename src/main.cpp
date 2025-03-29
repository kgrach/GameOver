#include <iostream>
#include <utility>
#include <memory>

using namespace std;

class Animal
{
    public:
        void eat() { cout << "I'm eating generic food."<< endl; }
};

class Cat : public Animal
{
    public:
        void eat() { cout << "I'm eating a rat."<<endl; }
};

void func(Animal *xyz) { xyz->eat(); }


class Base {
	virtual void method() {std::cout << "from Base" << std::endl;}
	virtual void func() {std::cout << "Base::func" << std::endl;}
public:
  Base() {
		func();
	}
	virtual ~Base() {method();}
	void baseMethod() {method();}
};

class A : public Base {
	void method() {std::cout << "from A" << std::endl;}
	void func() override {std::cout << "A::func" << std::endl;}
public:
	A() : Base(){

	}
	~A() {method();}
};

struct aaa{
};

struct bbb {
	char x1;
	int32_t x2;
	bbb() : x1('a'), x2(0x12345678) {
	}
};


class B{
	int i_;

public:
	B(int i) {
		i_ = i;
	}
	int Get(){
		return i_;
	}
};

void f(const bbb& x) {
	std::cout << x.x1 << std::endl;
}

int
main(int argc, char **argv)
{

	f(bbb());

	std::weak_ptr<B> ppB;
	{
		std::shared_ptr<B> pB = std::make_shared<B>(1);
		ppB = pB;
	}

	std::shared_ptr<B> pB = ppB.lock();

	int i;
	if (pB)
		i = pB->Get();

	std::cout << "B::i_=" << i << endl;

	{
		A a;
	}

	unsigned char half_limit = 150;
	
	http://stackoverflow.com/ 
	for (unsigned char i = 0; i < 2 * half_limit; ++i)
	{
			//что-то происходит;
	}

	return 0;
}