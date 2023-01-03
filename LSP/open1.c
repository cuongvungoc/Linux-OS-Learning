#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main(){
	int fd;
	fd = open("haha.txt", O_WRONLY);
	if (fd == -1) {
		printf("\nopen() was failed - errno = (%d)\n", errno);
		perror("ERROR:");
	}
	else {
		printf("\nopen() system call executed sucessfully\n");
	}
}
