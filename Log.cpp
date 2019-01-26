#include "Log.hpp"

void Log::Initialize() {
	std::ofstream l;
	l.open("log.txt", std::ofstream::out | std::ofstream::app);

	l << std::endl
		<< "===== APPLICATION LAUNCHED =====" << std::endl
		<< "   " << Log::GetDatestamp() << ' ' << Log::GetTimestamp() << std::endl
		<< "================================" << std::endl;
}

// Gets the current datestamp.
std::string Log::GetDatestamp() {
	std::time_t t = time(0);
	struct tm now;
	localtime_r(&t, &now);

	std::ostringstream oss;

	int daynum = now.tm_mday;
	int monthnum = now.tm_mon + 1;

	oss << (now.tm_year + 1900) << '-';
	if (monthnum < 10) oss << '0'; 	// Pad month with leading zero, if necessary
	oss << monthnum << '-';
	if (daynum < 10) oss << '0';	// Pad day with leading zero, if necessary
	oss << daynum;

	return oss.str();
}

// Gets the current timestamp.
std::string Log::GetTimestamp() {
	std::time_t t = time(0);
	struct tm now;
	localtime_r(&t, &now);

	std::ostringstream oss;

	int hour = now.tm_hour;
	int minutes = now.tm_min;
	int seconds = now.tm_sec;

	if (hour < 10) oss << '0';		// Pad hour, if necessary
	oss << hour << ':';
	if (minutes < 10) oss << '0';	// Pad minutes, if necessary
	oss << minutes << ':';
	if (seconds < 10) oss << '0';	// Pad seconds, if necessary
	oss << seconds;

	return oss.str();
}

// Logs a message.
void Log::LogMessage(
	const char level,
	const std::string message,
	const std::string method_name,
	const std::string file_name,
	const int line_number)
{
	std::ofstream l;
	l.open("log.txt", std::ofstream::out | std::ofstream::app); // Output, append mode

	std::string timestamp = Log::GetTimestamp();

	l << std::setw(2) << std::left << level 				// Log level
	  << std::setw(9) << std::left << timestamp				// Timestamp
	  << "[" << file_name << ", " << line_number << "] "	// File name and line number
	  << std::setw(20) << std::left << method_name			// Method name
	  << std::setw(59) << std::left << message 				// Message
	  << std::endl;

	l.close();
}