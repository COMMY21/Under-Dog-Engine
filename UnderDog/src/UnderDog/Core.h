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

#ifdef HZ_ENABLE_ASSERTS
	#define UD_ASSERT(x, ...) { if(!(x)) { UD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define UD_CORE_ASSERT(x, ...) { if(!(x)) { UD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define UD_ASSERT(x, ...)
	#define UD_CORE_ASSERT(x, ...)
#endif 


#define BIT(x) (1 << x)
