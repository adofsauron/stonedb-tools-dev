#ifndef TIANMU_SYSTEM_TIANMU_FILE_H_
#define TIANMU_SYSTEM_TIANMU_FILE_H_
#pragma once

#include "exception.h"
#include "file_system.h"
#include "stream.h"

namespace Tianmu {
namespace system {

#define O_BINARY 0

#define tianmu_umask S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP

/* A portable wrapper class for low level file I/O.
  Note - Most of the functions throws exception if it fails. So caller must
  handle exception appropriately.
*/

class TianmuFile : public Stream {
private:
  int fd_;

 public:
  TianmuFile() { fd_ = -1; }
  ~TianmuFile() {
    if (fd_ != -1) Close();
  }

  off_t Seek(off_t pos, int whence);
  off_t Tell();
  int Flush();

  int Open(std::string const &file, int flags, mode_t mode);
  int OpenCreate(std::string const &file);
  int OpenCreateNotExists(std::string const &file);
  int OpenCreateEmpty(std::string const &file) override;
  int OpenReadOnly(std::string const &file) override;
  int OpenReadWrite(std::string const &file) override;
  size_t Read(void *buf, size_t count) override;
  void ReadExact(void *buf, size_t count) override;
  void WriteExact(const void *buf, size_t count) override;

  bool IsOpen() const override;
  int Close() override;
};

}  // namespace system
}  // namespace Tianmu

#endif  // TIANMU_SYSTEM_TIANMU_FILE_H_
