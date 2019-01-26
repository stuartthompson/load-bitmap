#pragma once
#ifndef LOAD_BITMAP_LOG_HPP
#define LOAD_BITMAP_LOG_HPP

#include "stdafx.h"

// Log macros
#define LOG_DEBUG(message) \
	Log::LogMessage('D', message, __func__, __FILE__, __LINE__);

#define LOG_INFO(message) \
	Log::LogMessage('I', message, __func__, __FILE__, __LINE__);

#define LOG_WARN(message) \
	Log::LogMessage('W', message, __func__, __FILE__, __LINE__);

#define LOG_ERROR(message) \
	Log::LogMessage('E', message, __func__, __FILE__, __LINE__);

// Provides logging services.
class Log
{
public:
	static void Initialize();

	static std::string GetDatestamp();
	static std::string GetTimestamp();

	static void LogMessage(
		const char type,
		const std::string message,
		const std::string method_name,
		const std::string file_name,
		const int line_number);
};

#endif