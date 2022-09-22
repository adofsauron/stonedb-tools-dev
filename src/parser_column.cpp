#include "log.h"
#include "tools.h"
#include "base.h"
#include "parser_column.h"
#include "parser_ver.h"
#include "parser_dpn.h"
#include "tianmu/dpn.h"

bool parser_column(const char* file_path)
{
    LOG_INFO("file_path = " << file_path);

    std::string file_str = file_path;

    std::vector<std::string>tokens;
    Tokenize(file_str, tokens, ",");

    int file_num = tokens.size();
    LOG_INFO("file_num: " << file_num);

    if (COLUMN_FILE_NUM_LIMIT > file_num)
    {
        LOG_ERR("file_num must >= s4, but " << file_num);
        return false;
    }

    for( int i = 0; i < tokens.size() ; i++ )
    {
        LOG_INFO(tokens[i]);
    }

    std::string file_ver = tokens[0];
    std::string file_dpn = tokens[1];

    LOG_INFO("file_ver = " << file_ver);
    LOG_INFO("file_dpn = " << file_dpn);
    
    Tianmu::COL_VER_HDR_TOTAL hdr_total;
    {
        bool ret = parser_ver(file_ver.c_str(), &hdr_total);
        if (!ret)
        {
            return false;
        }

        parser_ver_print(&hdr_total);
    }

    std::unique_ptr<Tianmu::core::DPN[]> dpn_total;
    bool ret = parser_dpn(file_dpn.c_str(), dpn_total, hdr_total.hdr.numOfPacks);
    if (!ret)
    {
        return false;
    }

    parser_dpn_print(dpn_total, hdr_total.hdr.numOfPacks);


    return true;
}

