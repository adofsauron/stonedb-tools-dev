#ifndef __PARSER_DPN__H__
#define __PARSER_DPN__H__

#include "tianmu/dpn.h"

bool parser_dpn_one(const char* file_path_args, Tianmu::core::DPN* dpn);

// index: 0 -> ...
bool parser_dpn_one(const char* file_path, Tianmu::core::DPN* dpn, int index);

void parser_dpn_one_print(Tianmu::core::DPN* dpn);

bool parser_dpn_total(const char* file_path, std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks);

void parser_dpn_print(const std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks);

#endif  //!__PARSER_DPN__H__