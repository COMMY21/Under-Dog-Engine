#pragma once

#ifdef UD_PLATFORM_WINDOWS

extern Underdog::Application* Underdog::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to Underdog Engine \n");
	auto app = Underdog::CreateApplication();
	app->Run();
	delete app;
	
}

#endif // UD_PLATFORM_WINDOWS

