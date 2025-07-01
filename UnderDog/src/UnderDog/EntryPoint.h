#pragma once

#ifdef UD_PLATFORM_WINDOWS

extern Underdog::Application* Underdog::CreateApplication();

int main(int argc, char** argv)
{
	Underdog::Log::Init();
	UD_CORE_WARN("Initialized Log!");
	UD_CLIENT_INFO("Hello from Underdog!");

	auto app = Underdog::CreateApplication();
	app->Run();
	delete app;
	
}

#endif // UD_PLATFORM_WINDOWS

