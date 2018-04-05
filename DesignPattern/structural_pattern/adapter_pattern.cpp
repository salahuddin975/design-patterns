/*
--------------- Adapter Design Pattern | Structural Pattern -----------------
Allows 2 incompatible interfaces to work together.

From a real-world example, I have a mobile phone and a charger to charge the phone. But, the problem is the charger is a
round-pin charger where the mobile supports flat-pin charger. So, to solve the problem, I need an adapter(converter) which 
will allow me to charge the mobile.
*/


#include <iostream>


class MobileInterface                                  // Interface of Adaptee
{         
public:
	virtual void flat_pin() = 0;
};

class MobilePhone : public MobileInterface             // Concrete Adaptee
{
public:
	void flat_pin() {
		std::cout << "I only support flat pin!!!" << std::endl;
	}
};

class AdapterInterface                                 // Target, the interface of Adapter which client will use
{
public:
	virtual void round_pin() = 0;
};

class Adapter : public AdapterInterface  
{
private:
	MobileInterface *mobile_interface;

public:
	Adapter(MobileInterface *mi) {
		mobile_interface = mi;
	}

	void round_pin() {
		mobile_interface->flat_pin();
	}
};


void adapter_pattern()                                               // client code, charger -> I only support round pin
{
	MobilePhone *my_mobile_phone = new MobilePhone();                // Adaptee -> Mobile Phone
	AdapterInterface *adapter = new Adapter(my_mobile_phone);        
	adapter->round_pin();
}
