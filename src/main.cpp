#include "base.h"
#include "log.h"
#include "parser.h"

int	main(int argc, char **argv)
{
    if (3 > argc)
    {
        LOG_ERR("argc must >= 3, but argc is " << argc);
        return 1;
    }

    const char* file_type = argv[1];
    const char* file_path = argv[2];

    LOG_INFO("file_type = " << file_type);
    LOG_INFO("file_path = " << file_path);

    bool ret = parser_file(file_type, file_path);
    const char* ret_str = ret ? "true" : "false";

    LOG_INFO("parser_file ret = " << ret_str);

    return 0;
}

