#include "udpch.h"  
#include "Application.h"  
#include "Events/ApplicationEvents.h"  

#include "GLFW/glfw3.h"

namespace Underdog  
{

#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)  

	Underdog::Application::Application()  
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}  

	Underdog::Application::~Application()  
	{  

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		UD_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled())
				break;
		}
	}

	

	void Application::Run()  
	{  


		while (m_Running)
		{
			glClearColor(0.f, 1.f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			

			m_Window->OnUpdate();
		}
	} 

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
