#ifndef TIANMU_UTIL_LOG_CTL_H_
#define TIANMU_UTIL_LOG_CTL_H_
// #pragma once

#include <string>

namespace Tianmu {

namespace logger {
enum class LogCtl_Level { DISABLED = 0, FATAL = 1, ERROR = 2, WARN = 3, INFO = 4, DEBUG = 5, TRACE = 6 };
}  // namespace logger

namespace utils {
// a class help to check debug switch and print debug msg
// class LogCtl {
//  public:
//   static logger::LogCtl_Level GetSessionLevel();
//   static logger::LogCtl_Level GetGlobalLevel();

//   static bool LogEnabled(logger::LogCtl_Level level);

//   static void LogMsg(logger::LogCtl_Level level, const char *format, ...);
//   static void LogMsg(logger::LogCtl_Level level, const char *file, int line, const char *format, ...);
//   static void LogMsg(logger::LogCtl_Level level, const std::string &msg);
//   static void LogMsg(logger::LogCtl_Level level, const char *file, int line, const std::string &msg);
//   static void LogMsg(logger::LogCtl_Level level, std::stringstream &msg_ss);
// };
}  // namespace utils

constexpr size_t MAX_LOG_LEN = 4096;

// Tianmu logger API
// #define TIANMU_LOG(_level, ...) Tianmu::utils::LogCtl::LogMsg(logger::_level, __FILE__, __LINE__, ##__VA_ARGS__)

// #define TIANMU_LOGCHECK(_level) (Tianmu::utils::LogCtl::LogEnabled(logger::_level))
// #define LOG_MSG(_level, msg) Tianmu::utils::LogCtl::LogMsg(logger::_level, __FILE__, __LINE__, msg);

#define TIANMU_LOG(_level, ...)
#define TIANMU_LOGCHECK(_level)
#define LOG_MSG(_level, msg)

void log_setup(const std::string &log_file);

}  // namespace Tianmu

#endif  // TIANMU_UTIL_LOG_CTL_H_
