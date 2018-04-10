
#include <iostream>

// --------------------- declare interface --------------------

class FactoryInterface
{
public:
	virtual void factory_function1() = 0;
	virtual void factory_function2() = 0;

	virtual ~FactoryInterface() {}
};

//-------------------- implement interface ------------------------

class FactoryImplementation1 : public FactoryInterface
{
public:
	FactoryImplementation1(){
		std::cout << "Constructing FactoryImplementation1..." << std::endl;
	}

    void factory_function1() {
		std::cout << "From FactoryImplementation1::factory_function1()" << std::endl;
	}

    void factory_function2() {
		std::cout << "From FactoryImplementation1::factory_function2()" << std::endl;
	}

	~FactoryImplementation1(){
		std::cout << "Destructing FactoryImplementation1..." << std::endl;
	}
};

class FactoryImplementation2 : public FactoryInterface
{
public:
	FactoryImplementation2(){
		std::cout << "Constructing FactoryImplementation2..." << std::endl;
	}

    void factory_function1() {
		std::cout << "From FactoryImplementation2::factory_function1()" << std::endl;
	}

    void factory_function2() {
		std::cout << "From FactoryImplementation2::factory_function2()" << std::endl;
	}

	~FactoryImplementation2(){
		std::cout << "Destructing FactoryImplementation2..." << std::endl;
	}
};

// ---------------------- get specific object ----------------------

enum FactoryType
{
	FactoryType1,
	FactoryType2
};


class FactoryProvider{
public:
	static FactoryInterface* getFactoryObject(FactoryType factoryType)
	{
		switch (factoryType)
		{
		case FactoryType1:
			return new FactoryImplementation1();

		case FactoryType2:
			return new FactoryImplementation2();

		default:
			return nullptr;
		}
	}
};


// ----------------- test factory pattern -----------

void factory_pattern()
{
	FactoryInterface *factoryInterface1 = FactoryProvider::getFactoryObject(FactoryType1);
    factoryInterface1->factory_function1();
    factoryInterface1->factory_function2();
	delete factoryInterface1;

	std::cout << "----------------------------" << std::endl;

	FactoryInterface *factoryInterface2 = FactoryProvider::getFactoryObject(FactoryType2);
    factoryInterface2->factory_function1();
    factoryInterface2->factory_function2();
	delete factoryInterface2;
}
