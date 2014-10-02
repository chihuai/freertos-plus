#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include <stdint.h>
#include <hash-djb2.h>

#define MAX_FS 16
#define OPENFAIL (-1)

typedef int (*fs_open_t)(void * opaque, const char * fname, int flags, int mode);
typedef void (*fs_list_t)(void * opaque, char * filename);

/* Need to be called before using any other fs functions */
__attribute__((constructor)) void fs_init();

void list_fs(char * buf);
void list_fs_path(char * buf, const char *path);
int register_fs(const char * mountpoint, fs_open_t callback, fs_list_t list_callback, void * opaque);
int fs_open(const char * path, int flags, int mode);

#endif
