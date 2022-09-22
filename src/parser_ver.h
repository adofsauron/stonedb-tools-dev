#ifndef __PARSER_VER__H__
#define __PARSER_VER__H__

#include "tianmu/file_layout.h"

bool parser_ver(const char* file_path, Tianmu::COL_VER_HDR_TOTAL* hdr);

void parser_ver_print(Tianmu::COL_VER_HDR_TOTAL* hdr);

#endif  //!__PARSER_VER__H__