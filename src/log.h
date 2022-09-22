#ifndef __LOG__H__
#define __LOG__H__

#include <iostream>

#define LOG(level, msg) \
do { \
    std::cout << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << "\t" << level << " " << msg << std::endl; \
} while (0);

#define LOG_INFO(msg) \
    LOG("[INFO]", msg)

#define LOG_ERR(msg) \
    LOG("[ERROR]", msg)

#endif  //!__LOG__H__
