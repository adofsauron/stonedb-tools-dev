#ifndef __TOOLS__H__
#define __TOOLS__H__

#include <string>
#include <vector>

bool check_file_exists(const char* file_path);

void Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters);

#endif  //!__TOOLS__H__