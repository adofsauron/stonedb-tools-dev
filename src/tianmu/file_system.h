#ifndef TIANMU_SYSTEM_FILE_SYSTEM_H_
#define TIANMU_SYSTEM_FILE_SYSTEM_H_
#pragma once

#include <string>

namespace Tianmu {
namespace system {

/** \brief Deletes a directory defined by path
 *  \param path Directory path
 *  The delete operation is recursive. It deletes all existing files and
 * subdirectories
 */
void DeleteDirectory(std::string const &path);

/** \brief Returns file's last content modification time
 *  \param name Path to the file
 *  \return Time typecasted to int
 */
time_t GetFileTime(std::string const &path);

/** \brief Returns file's last metadata modification time
 *  \param name Path to the file
 *  \return Time typecasted to int
 *  \see chown
 */
time_t GetFileCreateTime(std::string const &path);

/** \brief Checks file existense
 *  \param name Path to the file
 *  \return True if a file exists. False if a file doesn't exist
 */
bool DoesFileExist(std::string const &);

/** \brief Rename file
 *  \param OldPath Original file path
 *  \param NewPath New file path
 *  Function throws an exception in case it fails to rename a file
 */
void RenameFile(std::string const &OldPath, std::string const &NewPath);

/** \brief Delete file
 *  \param file  Path to the file
 *  Function throws an exception in case it fails to remove a file
 *  If a file does not exist, no exceptions are thrown
 */
void RemoveFile(std::string const &file, int throwerror = true);

/** \brief Flush to the disk kernel buffers with directory entries changes
 *  \param path  Directory path
 *  Function throws an exception in case it fails to perform
 */
void FlushDirectoryChanges(std::string const &path);

void FlushFileChanges(std::string const &path);

/** \brief Check file permissions
 *  \param path  File path
 *  \return True if a process is allowed to read and write a file. False
 * otherwise
 */
bool IsReadWriteAllowed(std::string const &path);

int ClearDirectory(std::string const &path);

}  // namespace system
}  // namespace Tianmu

#endif  // TIANMU_SYSTEM_FILE_SYSTEM_H_
