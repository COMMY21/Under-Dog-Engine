#pragma once

#ifdef UD_PLATFORM_WINDOWS
	#ifdef UD_BUILD_DLL
		#define UD_API __declspec(dllexport)
	#else
		#define UD_API __declspec(dllimport)
	#endif
#else
	#error Underdog only supports Windows!
#endif

#define BIT(x) (1 << x)
