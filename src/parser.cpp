#include "parser.h"
#include "parser_ver.h"
#include "base.h"
#include "log.h"
#include "tools.h"

#include <string>

bool parse_file(const char* file_type, const char* file_path)
{
    LOG_INFO("file_type = " << file_type);
    LOG_INFO("file_path = " << file_path);

    if (!check_file_exists(file_path))
    {
        LOG_ERR("check_file_exists false, file_path = " << file_path);
        return false;
    }

    if (FILE_TYPE_VER == std::string(file_type))
    {
        return parse_ver(file_path);
    }

    return true;
}

