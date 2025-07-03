#pragma once

#include "Core.h"


namespace Underdog
{
	class UD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
