
#include <iostream>

using namespace std;


// Receiver classes
class Light
{
public:
	void light_on()
	{
		std::cout << "Light is On" << std::endl;
	}

	void light_off()
	{
		std::cout << "Light is Off" << std::endl;
	}
};


class Fan
{
public:
	void fan_on()
	{
		std::cout << "Fan is On" << std::endl;
	}

	void fan_off()
	{
		std::cout << "Fan is Off" << std::endl;
	}
};

// Command Interface
class Command
{
public:
	virtual void execute() = 0;
};


// Concrete Commands
class LightOn : public Command
{
public:
	LightOn(Light *light) : m_light(light) {}
	void execute() { m_light->light_on(); }

private:
	Light *m_light;
};


class LightOff : public Command
{
public:
	LightOff(Light *light) : m_light(light) {}
	void execute() { m_light->light_off(); }

private:
	Light *m_light;
};


class FanOn : public Command
{
public:
	FanOn(Fan *fan_command) : m_fan(fan_command) { }
	void execute() { m_fan->fan_on(); }

private:
	Fan *m_fan;
};

class FanOff : public Command
{
public:
	FanOff(Fan *fan_command) : m_fan(fan_command) { }
	void execute() { m_fan->fan_off(); }

private:
	Fan *m_fan;
};

// Invoker
class RemoteControl
{
public:
	void set_command(Command *light_command) { m_light_command = light_command; }
	void button_pressed() { m_light_command->execute(); }

private:
	Command *m_light_command;
};


// client
int command_client()
{
	RemoteControl remote_control;

	// Command client for Light
	Light light;
	LightOn light_on(&light);
	LightOff light_off(&light);

	remote_control.set_command(&light_on);
	remote_control.button_pressed();

	remote_control.set_command(&light_off);
	remote_control.button_pressed();

	// Command client for Fan
	Fan fan;
	FanOn fan_on(&fan);
	FanOff fan_off(&fan);

	remote_control.set_command(&fan_on);
	remote_control.button_pressed();

	remote_control.set_command(&fan_off);
	remote_control.button_pressed();

	return 0;
}

