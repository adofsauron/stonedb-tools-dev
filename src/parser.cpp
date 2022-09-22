#include "base.h"
#include "log.h"
#include "tools.h"
#include "parser.h"
#include "parser_ver.h"
#include "parser_dpn.h"
#include "parser_column.h"
#include "tianmu/dpn.h"

#include <string>

bool parser_file(const char* file_type, const char* file_path)
{
    LOG_INFO("file_type = " << file_type);
    LOG_INFO("file_path = " << file_path);

    // if (!check_file_exists(file_path))
    // {
    //     LOG_ERR("check_file_exists false, file_path = " << file_path);
    //     return false;
    // }

    std::string type_str = file_type;

    if (FILE_TYPE_COLUMN == type_str)
    {
        bool ret = parser_column(file_path);
        return ret;
    }

    if (FILE_TYPE_VER == type_str)
    {
        Tianmu::COL_VER_HDR_TOTAL hdr_total;
        bool ret = parser_ver(file_path, &hdr_total);
        if (!ret)
        {
            return false;
        }

        parser_ver_print(&hdr_total);

        return true;
    }

    if (FILE_TYPE_DPN == type_str)
    {
        Tianmu::core::DPN dpn;
        bool ret = parser_dpn_one(file_path, &dpn);
        if (!ret)
        {
            return false;
        }

        parser_dpn_one_print(&dpn);

        return true;
    }

    return true;
}

