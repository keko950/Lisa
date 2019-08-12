#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"


namespace Lisa
{

	class LISA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr <spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//Core macros
#define LS_CORE_ERROR(...) ::Lisa::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LS_CORE_WARN(...) ::Lisa::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LS_CORE_INFO(...) ::Lisa::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LS_CORE_TRACE(...) ::Lisa::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LS_CORE_FATAL(...) ::Lisa::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define LS_CLIENT_ERROR(...) ::Lisa::Log::GetClientLogger()->error(__VA_ARGS__)
#define LS_CLIENT_WARN(...) ::Lisa::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LS_CLIENT_INFO(...) ::Lisa::Log::GetClientLogger()->info(__VA_ARGS__)
#define LS_CLIENT_TRACE(...) ::Lisa::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LS_CLIENT_FATAL(...) ::Lisa::Log::GetClientLogger()->fatal(__VA_ARGS__)