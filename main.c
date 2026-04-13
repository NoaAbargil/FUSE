#define FUSE_USE_VERSION 30
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
test
test
test

static int getattr_callback(const char* file_path, struct stat* file_stat) {
	/* 
	The getattr callback is in charge of reading the metadata of a given path
	This callback is always called before any operation made on the filesystem.
	*/

	if (strcmp(file_path, "/")) {
		// Given path points to the root directory
		file_stat->st_mode = S_IFDIR | 755;
		file_stat->st_nlink = 2;
		return 0;
	}
	else {
		// Given path points to a file (can also be sub dir but lets ignore it for now	)
		file_stat->st_mode = S_IFREG | 775;
		file_stat->st_nlink = 1;
		return 0;
	}
	
	return -ENOENT; // No such file or dir
}


static int readdir_callback(struct fuse_fs* fs, const char* path, void* buf,
	fuse_fill_dir_t filler, off_t off,struct fuse_file_info* fi) {
	return 0;
}



struct fuse_operations fs_operations = {
	.getattr = getattr_callback,
	.readdir = readdir_callback
};


int main(int argc, char *argv[]) {
	return fuse_main(argc, argv, &fs_operations, NULL);

}
