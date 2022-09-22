#ifndef __FILE_FORMAT__H__
#define __FILE_FORMAT__H__

#include "defs.h"

#include <list>
#include <memory>

namespace Tianmu {

struct COL_META {
  uint32_t magic;
  uint32_t ver;         // file version
  uint8_t pss;          // pack size shift
  common::CT type;      // type
  common::PackFmt fmt;  // data format: LZ4, snappy, lookup, raw, etc
  uint8_t flag;
  uint32_t precision;
  uint32_t scale;
};

struct alignas(128) COL_VER_HDR_V3 {
  uint64_t numOfRecords;  // number of records
  uint64_t numOfNulls;    // number of nulls
  uint64_t numOfPacks;    // number of packs
  uint64_t numOfDeleted;  //number of deleted

  uint64_t auto_inc_next;
  int64_t min;
  int64_t max;
  uint32_t dict_ver;    // dict file version name. 0 means n/a
  uint32_t unique : 1;
  uint32_t unique_updated : 1;
  uint64_t natural_size;
  uint64_t compressed_size;
};

using COL_VER_HDR = COL_VER_HDR_V3;

struct COL_VER_HDR_TOTAL {
  COL_VER_HDR hdr;
  std::unique_ptr<Tianmu::common::PACK_INDEX[]> arr;
};

}

#endif  //!__FILE_FORMAT__H__