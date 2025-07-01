#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"


namespace Underdog
{
	class UD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define UD_CORE_TRACE(...)		::Underdog::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UD_CORE_INFO(...)		::Underdog::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UD_CORE_WARN(...)		::Underdog::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UD_CORE_ERROR(...)		::Underdog::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UD_CORE_CRITICAL(...)	::Underdog::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define UD_CLIENT_TRACE(...)    ::Underdog::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UD_CLIENT_INFO(...)     ::Underdog::Log::GetClientLogger()->info(__VA_ARGS__)
#define UD_CLIENT_WARN(...)     ::Underdog::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UD_CLIENT_ERROR(...)    ::Underdog::Log::GetClientLogger()->error(__VA_ARGS__)
#define UD_CLIENT_CRITICAL(...) ::Underdog::Log::GetClientLogger()->critical(__VA_ARGS__)



