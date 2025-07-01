
#include "UnderDog.h"

class Sandbox : public Underdog::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Underdog::Application* Underdog::CreateApplication()
{
	return new Sandbox();
}