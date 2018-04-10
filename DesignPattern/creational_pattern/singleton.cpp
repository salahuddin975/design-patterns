#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

class SingleTon
{
private:
	static SingleTon *instance;

private:
	SingleTon(){
		std::cout << "Constructing..." << std::endl;
	}

public:
	static SingleTon* get_instance(){
		if (instance == nullptr){
			instance = new SingleTon();
		}

		return instance;
	}

	static void delete_instance(){
		if (instance != nullptr){
			delete instance;
		}
	}

	void print_test(){
		if (instance == nullptr){
			return ;
		}

		std::cout << "Print this!" << std::endl;
	}

	~SingleTon(){
		std::cout << "Destructing..." << std::endl;
		instance = nullptr;
	}
};

SingleTon *SingleTon::instance = nullptr;


void singleton_pattern()
{
	SingleTon *ins = SingleTon::get_instance();
	ins->print_test();

	SingleTon::delete_instance();
    SingleTon::delete_instance();
    SingleTon::delete_instance();

	if (ins != nullptr){
		ins->print_test();
	}

	SingleTon *ins1 = SingleTon::get_instance();
	ins1->print_test();

	SingleTon *ins2 = SingleTon::get_instance();
	ins2->print_test();

	SingleTon::delete_instance();
	ins2->print_test();
}
