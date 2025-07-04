
#include "UnderDog.h"

class ExampleLayer : public Underdog::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		UD_CORE_INFO("ExampleLayer::OnUpdate");
	}
	void OnEvent(Underdog::Event& event) override
	{
		UD_CORE_TRACE("Event received: {0}", event);
	}
};

class Sandbox : public Underdog::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	}
};

Underdog::Application* Underdog::CreateApplication()
{
	return new Sandbox();
}