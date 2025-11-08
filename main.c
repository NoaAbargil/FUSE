#define FUSE_USE_VERSION 26
#include <fuse.h>


static int getattr_callback(const char* ch, struct stat*) {
	return 0;
}


struct fuse_operations fs_operations = {
	.getattr = getattr_callback
};


int main(int argc, char *argv[]) {

	return fuse_main(argc, argv, &fs_operations, NULL);

}