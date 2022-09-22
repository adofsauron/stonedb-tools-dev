#include "parser_ver.h"
#include "base.h"
#include "log.h"
#include "tianmu/tianmu_file.h"
#include "tianmu/file_layout.h"
#include "tianmu/defs.h"
#include "tianmu/dpn.h"

#include <memory>

bool parser_ver(const char* file_path, Tianmu::COL_VER_HDR_TOTAL* hdr_total)
{
    LOG_INFO("file_path = " << file_path);

    Tianmu::system::TianmuFile fv;

    fv.OpenReadOnly(file_path);
    fv.ReadExact(&hdr_total->hdr, sizeof(hdr_total->hdr));

    if (hdr_total->hdr.numOfPacks == 0) {
        return true;
    }

    hdr_total->arr = std::make_unique<Tianmu::common::PACK_INDEX[]>(hdr_total->hdr.numOfPacks);
    fv.ReadExact(hdr_total->arr.get(), hdr_total->hdr.numOfPacks * sizeof(Tianmu::common::PACK_INDEX));
    
    return true;
}

void parser_ver_print(Tianmu::COL_VER_HDR_TOTAL* hdr_total)
{
    LOG_INFO("hdr_total->hdr.numOfRecords = " << hdr_total->hdr.numOfRecords);
    LOG_INFO("hdr_total->hdr.numOfNulls = " << hdr_total->hdr.numOfNulls);
    LOG_INFO("hdr_total->hdr.numOfPacks = " << hdr_total->hdr.numOfPacks);
    LOG_INFO("hdr_total->hdr.numOfDeleted = " << hdr_total->hdr.numOfDeleted);

    LOG_INFO("hdr_total->hdr.auto_inc_next = " << hdr_total->hdr.auto_inc_next);
    LOG_INFO("hdr_total->hdr.min = " << hdr_total->hdr.min);
    LOG_INFO("hdr_total->hdr.max = " << hdr_total->hdr.max);
    LOG_INFO("hdr_total->hdr.dict_ver = " << hdr_total->hdr.dict_ver);
    LOG_INFO("hdr_total->hdr.unique = " << hdr_total->hdr.unique);
    LOG_INFO("hdr_total->hdr.unique_updated = " << hdr_total->hdr.unique_updated);
    LOG_INFO("hdr_total->hdr.natural_size = " << hdr_total->hdr.natural_size);
    LOG_INFO("hdr_total->hdr.compressed_size = " << hdr_total->hdr.compressed_size);

    auto end = hdr_total->arr.get() + hdr_total->hdr.numOfPacks;

    for (int i = 0; i < hdr_total->hdr.numOfPacks; i++)
    {
        Tianmu::common::PACK_INDEX index = hdr_total->arr[i];
        LOG_INFO("arr i: " << i << ", PACK_INDEX: " << index);
    }
}
