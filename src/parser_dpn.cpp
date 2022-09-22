#include "parser_ver.h"
#include "base.h"
#include "log.h"
#include "tools.h"
#include "tianmu/tianmu_file.h"
#include "tianmu/file_layout.h"
#include "tianmu/defs.h"
#include "tianmu/dpn.h"

bool parser_dpn_total(const char* file_path, std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks)
{
    LOG_INFO("file_path = " << file_path);
    LOG_INFO("numOfPacks = " << numOfPacks);

    Tianmu::system::TianmuFile fdn;
    fdn.OpenReadOnly(file_path);

    dpn_total = std::make_unique<Tianmu::core::DPN[]>(numOfPacks);

    fdn.ReadExact(dpn_total.get(), numOfPacks * sizeof(Tianmu::core::DPN));

    return true;
}

bool parser_dpn_one(const char* file_path, Tianmu::core::DPN* dpn, int index)
{
    LOG_INFO("file_path = " << file_path);
    LOG_INFO("index = " << index);

    Tianmu::system::TianmuFile fdn;
    fdn.OpenReadOnly(file_path);

    off_t pos = index==0 ? 0 : ( (index-1) * sizeof(Tianmu::core::DPN) );
    fdn.Seek(pos, 0);

    fdn.ReadExact(dpn, sizeof(Tianmu::core::DPN));

    return true;
}

bool parser_dpn_one(const char* file_path_args, Tianmu::core::DPN* dpn)
{
    LOG_INFO("file_path_args = " << file_path_args);

    std::string file_str = file_path_args;

    std::vector<std::string>tokens;
    Tokenize(file_str, tokens, ",");

    int file_num = tokens.size();
    LOG_INFO("file_num: " << file_num);

    if (DPN_ONE_ARGS_NUM_LIMIT > file_num)
    {
        LOG_ERR("file_num must >= " << DPN_ONE_ARGS_NUM_LIMIT << ", but " << file_num);
        return false;
    }

    for( int i = 0; i < tokens.size() ; i++ )
    {
        LOG_INFO(tokens[i]);
    }

    std::string dpn_file = tokens[0];
    std::string dpn_index = tokens[1];

    int index = std::atoi(dpn_index.c_str());

    LOG_INFO("dpn_file = " << dpn_file);
    LOG_INFO("dpn_index = " << index);

    return parser_dpn_one(dpn_file.c_str(), dpn, index);
}

void parser_dpn_one_print(Tianmu::core::DPN* dpn)
{
    LOG_INFO("dpn->used = " << (dpn->used ? "1" : "0"));
    LOG_INFO("dpn->local = " << (dpn->local? "1" : "0"));
    LOG_INFO("dpn->synced = " << (dpn->synced ? "1" : "0"));
    LOG_INFO("dpn->null_compressed = " << (dpn->null_compressed ? "1" : "0"));
    LOG_INFO("dpn->delete_compressed = " << (dpn->delete_compressed ? "1" : "0"));
    LOG_INFO("dpn->data_compressed = " << (dpn->data_compressed ? "1" : "0"));
    LOG_INFO("dpn->no_compress = " << (dpn->no_compress ? "1" : "0"));
    LOG_INFO("dpn->padding = " << (dpn->padding[0] ? "1" : "0"));
    LOG_INFO("dpn->base = " << dpn->base);
    LOG_INFO("dpn->numOfRecords = " << dpn->numOfRecords);
    LOG_INFO("dpn->numOfNulls = " << dpn->numOfNulls);
    LOG_INFO("dpn->numOfDeleted = " << dpn->numOfDeleted);
    LOG_INFO("dpn->dataAddress = " << dpn->dataAddress);
    LOG_INFO("dpn->dataLength = " << dpn->dataLength);

    LOG_INFO("dpn->xmin = " << dpn->xmin.v);
    LOG_INFO("dpn->xmax = " << dpn->xmax.v);
    
    LOG_INFO("dpn->min_i = " << dpn->min_i);
    LOG_INFO("dpn->min_d = " << dpn->min_d);
    LOG_INFO("dpn->min_s = " << dpn->min_s);

    LOG_INFO("dpn->max_i = " << dpn->max_i);
    LOG_INFO("dpn->max_d = " << dpn->max_d);
    LOG_INFO("dpn->max_s = " << dpn->max_s);


    LOG_INFO("dpn->sum_i = " << dpn->sum_i);
    LOG_INFO("dpn->sum_d = " << dpn->sum_d);
    LOG_INFO("dpn->maxlen = " << dpn->maxlen);
}

void parser_dpn_print(const std::unique_ptr<Tianmu::core::DPN[]>& dpn_total, int numOfPacks)
{
    for (int i = 0; i < numOfPacks; i++)
    {
        LOG_INFO("--------DPN index = "<<i);

        Tianmu::core::DPN dpn = dpn_total[i];
        parser_dpn_one_print(&dpn);
    }
}

