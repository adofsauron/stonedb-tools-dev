#ifndef __PARSER_DPN__H__
#define __PARSER_DPN__H__

#include "tianmu/dpn.h"

bool parser_dpn(const char* file_path, std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks);

void parser_dpn_print(const std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks);

#endif  //!__PARSER_DPN__H__