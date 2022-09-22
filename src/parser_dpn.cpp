#include "parser_ver.h"
#include "base.h"
#include "log.h"
#include "tianmu/tianmu_file.h"
#include "tianmu/file_layout.h"
#include "tianmu/defs.h"
#include "tianmu/dpn.h"

bool parser_dpn(const char* file_path, std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks)
{
    LOG_INFO("file_path = " << file_path);
    LOG_INFO("numOfPacks = " << numOfPacks);

    dpn_total = std::make_unique<Tianmu::core::DPN[]>(numOfPacks);

    Tianmu::system::TianmuFile fdn;
    fdn.OpenReadOnly(file_path);

    fdn.ReadExact(dpn_total.get(), numOfPacks * sizeof(Tianmu::core::DPN));

    return true;
}

void parser_dpn_print(const std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks)
{
    for (int i = 0; i < numOfPacks; i++)
    {
        LOG_INFO("--------DPN index = "<<i);

        Tianmu::core::DPN dpn = dpn_total[i];

        LOG_INFO("dpn.used = " << dpn.used);
        LOG_INFO("dpn.local = " << dpn.local);
        LOG_INFO("dpn.synced = " << dpn.synced);
        LOG_INFO("dpn.null_compressed = " << dpn.null_compressed);
        LOG_INFO("dpn.delete_compressed = " << dpn.delete_compressed);
        LOG_INFO("dpn.data_compressed = " << dpn.data_compressed);
        LOG_INFO("dpn.no_compress = " << dpn.no_compress);
        LOG_INFO("dpn.padding = " << dpn.padding[0]);
        LOG_INFO("dpn.base = " << dpn.base);
        LOG_INFO("dpn.numOfRecords = " << dpn.numOfRecords);
        LOG_INFO("dpn.numOfNulls = " << dpn.numOfNulls);
        LOG_INFO("dpn.numOfDeleted = " << dpn.numOfDeleted);
        LOG_INFO("dpn.dataAddress = " << dpn.dataAddress);
        LOG_INFO("dpn.dataLength = " << dpn.dataLength);

        LOG_INFO("dpn.xmin = " << dpn.xmin.v);
        LOG_INFO("dpn.xmax = " << dpn.xmax.v);
        
        LOG_INFO("dpn.min_i = " << dpn.min_i);
        LOG_INFO("dpn.min_d = " << dpn.min_d);
        LOG_INFO("dpn.min_s = " << dpn.min_s);

        LOG_INFO("dpn.max_i = " << dpn.max_i);
        LOG_INFO("dpn.max_d = " << dpn.max_d);
        LOG_INFO("dpn.max_s = " << dpn.max_s);


        LOG_INFO("dpn.sum_i = " << dpn.sum_i);
        LOG_INFO("dpn.sum_d = " << dpn.sum_d);
        LOG_INFO("dpn.maxlen = " << dpn.maxlen);

    }

}