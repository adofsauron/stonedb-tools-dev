#ifndef __BASE__H__
#define __BASE__H__

enum FileType {
    FT_VER  = 0,
    FT_DPN  = 1,
    FT_META = 2,
    FT_DATA = 3
};


#define FILE_TYPE_VER       "ver"
#define FILE_TYPE_DPN       "dpn"
#define FILE_TYPE_COLUMN    "column"

#define COLUMN_FILE_NUM_LIMIT 4

#endif  //!__BASE__H__

