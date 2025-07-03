#include "udpch.h"
#include "Application.h"  
#include "Events/ApplicationEvents.h"


#include "Log.h"

namespace Underdog  
{  
Underdog::Application::Application()  
{  
}  

Underdog::Application::~Application()  
{  
}  
void Application::Run()  
{  
	WindowResizeEvent e(1280, 720);
	UD_CORE_TRACE(e);


	while (true);  
}  
}
