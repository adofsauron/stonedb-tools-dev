/* Copyright (c) 2022 StoneAtom, Inc. All rights reserved.
   Use is subject to license terms

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1335 USA
*/
#ifndef TIANMU_COMMON_DEFS_H_
#define TIANMU_COMMON_DEFS_H_
#pragma once

#include <cstdint>

namespace Tianmu {
namespace common {

// Column Type
// NOTE: do not change the order of implemented data types! Stored as int(...)
// on disk.
enum class CT : unsigned char {
  STRING,   // string treated either as dictionary value or "free" text
  VARCHAR,  // as above (discerned for compatibility with SQL)
  INT,      // integer 32-bit

  NUM,   // numerical: decimal, up to DEC(18,18)
  DATE,  // numerical (treated as integer in YYYYMMDD format)
  TIME,  // numerical (treated as integer in HHMMSS format)

  BYTEINT,   // integer 8-bit
  SMALLINT,  // integer 16-bit

  BIN,      // free binary (BLOB), no encoding
  BYTE,     // free binary, fixed size, no encoding
  VARBYTE,  // free binary, variable size, no encoding
  REAL,     // double (stored as non-interpreted int64_t, null value is
            // NULL_VALUE_64)
  DATETIME,
  TIMESTAMP,
  DATETIME_N,
  TIMESTAMP_N,
  TIME_N,

  FLOAT,
  YEAR,
  MEDIUMINT,
  BIGINT,
  LONGTEXT,
  UNK = 255
};

// pack data format, stored on disk so only append new ones at the end.
enum class PackFmt : char { DEFAULT, PPM1, PPM2, RANGECODE, LZ4, LOOKUP, NOCOMPRESS, TRIE, ZLIB };

constexpr uint64_t FILE_MAGIC = 0x4254756d6e616954;  // "TianmuTB"
constexpr const char *TIANMU_EXT = ".tianmu";

constexpr uint32_t TABLE_DATA_VERSION = 3;
constexpr const char *TABLE_DESC_FILE = "TABLE_DESC";
constexpr const char *TABLE_VERSION_FILE = "VERSION";
constexpr const char *TABLE_VERSION_FILE_TMP = "VERSION.tmp";
constexpr const char *TABLE_VERSION_PREFIX = "V.";

constexpr uint32_t COL_FILE_MAGIC = 0x004c4f43;  // "COL"
constexpr const char *COLUMN_DIR = "columns";
constexpr const char *COL_DICT_DIR = "dict";
constexpr const char *COL_FILTER_DIR = "filters";
constexpr const char *COL_FILTER_BLOOM_DIR = "bloom";
constexpr const char *COL_FILTER_CMAP_DIR = "cmap";
constexpr const char *COL_FILTER_HIST_DIR = "hist";
constexpr const char *COL_KN_FILE = "KN";
constexpr const char *COL_META_FILE = "META";
constexpr const char *COL_DN_FILE = "DN";
/*
   The size of the file where the DPN metadata resides, in bytes
   At present, the size of a single DPN is 88 bytes, and the storage limit is 8.589 billion lines
*/
constexpr size_t COL_DN_FILE_SIZE = 11 * 1024 * 1024;
constexpr const char *COL_DATA_FILE = "DATA";
constexpr const char *COL_VERSION_DIR = "v";
constexpr uint32_t COL_FILE_VERSION = 3;
constexpr uint32_t MAX_COLUMNS_PER_TABLE = 4000;

constexpr uint8_t MAX_PSS = 16;
constexpr uint8_t DFT_PSS = 16;
constexpr size_t MAX_CMPR_SIZE = 0x007D000000;

using PACK_INDEX = uint32_t;
constexpr PACK_INDEX INVALID_PACK_INDEX = -1;

}  // namespace common
}  // namespace Tianmu

#endif  // TIANMU_COMMON_DEFS_H_
