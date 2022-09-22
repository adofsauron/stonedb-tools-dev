#ifndef TIANMU_SYSTEM_STREAM_H_
#define TIANMU_SYSTEM_STREAM_H_
#pragma once

#include <string>

namespace Tianmu {
namespace system {
class Stream {

 public:
  Stream() = default;
  virtual ~Stream() = default;

  virtual bool IsOpen() const = 0;
  virtual int Close() = 0;
  virtual int OpenReadOnly(std::string const &filename) = 0;
  virtual int OpenReadWrite(std::string const &filename) = 0;
  virtual int OpenCreateEmpty(std::string const &filename) = 0;
  virtual void WriteExact(const void *buf, size_t count) = 0;
  virtual size_t Read(void *buf, size_t count) = 0;
  virtual void ReadExact(void *buf, size_t count) = 0;
  void ThrowError(int errnum);
  void ThrowError(std::string serror);
  const std::string &Name() const { return name_; }

 protected:
  std::string name_;
};

}  // namespace system
}  // namespace Tianmu

#endif  // TIANMU_SYSTEM_STREAM_H_
