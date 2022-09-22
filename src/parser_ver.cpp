#include "parser_ver.h"
#include "base.h"
#include "log.h"
#include "tianmu/tianmu_file.h"
#include "tianmu/file_layout.h"
#include "tianmu/defs.h"

bool parse_ver(const char* file_path)
{
    LOG_INFO("file_path = " << file_path);

    Tianmu::COL_VER_HDR hdr{};
    Tianmu::system::TianmuFile fv;

    fv.OpenReadOnly(file_path);
    fv.ReadExact(&hdr, sizeof(hdr));

    LOG_INFO("hdr.numOfRecords = " << hdr.numOfRecords);
    LOG_INFO("hdr.numOfNulls = " << hdr.numOfNulls);
    LOG_INFO("hdr.numOfPacks = " << hdr.numOfPacks);
    LOG_INFO("hdr.numOfDeleted = " << hdr.numOfDeleted);

    LOG_INFO("hdr.auto_inc_next = " << hdr.auto_inc_next);
    LOG_INFO("hdr.min = " << hdr.min);
    LOG_INFO("hdr.max = " << hdr.max);
    LOG_INFO("hdr.dict_ver = " << hdr.dict_ver);
    LOG_INFO("hdr.unique = " << hdr.unique);
    LOG_INFO("hdr.unique_updated = " << hdr.unique_updated);
    LOG_INFO("hdr.natural_size = " << hdr.natural_size);
    LOG_INFO("hdr.compressed_size = " << hdr.compressed_size);

    if (hdr.numOfPacks == 0) {
        return true;
    }

    auto arr = std::make_unique<tianmu::common::PACK_INDEX[]>(hdr.numOfPacks);
    fv.ReadExact(arr.get(), hdr.numOfPacks * sizeof(tianmu::common::PACK_INDEX));
    auto end = arr.get() + hdr.numOfPacks;

    // for (int i = 0; i < hdr.numOfPacks; i++)
    // {
    //     auto found = std::find(arr.get(), end, i);
    //     if (found == end) 
    //     {
    //         LOG_INFO("arr over");
    //     }
    //     else
    //     {
    //         LOG_INFO("arr i: " << i);
    //     }
        
    // }
    

    return true;
}
