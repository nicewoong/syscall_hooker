#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
 
#define FD_PATH_SIZE 500

char* getPathByFd(int cur_pid, int fd) {

	char *link_of_fd_path = (char*)malloc(sizeof(char) * FD_PATH_SIZE); // text of symlink of fd  
	int read_size; // save string length of symlink path 

	char sympath[FD_PATH_SIZE] ; // will save path of fd -> ex) '/proc/1010(pid)/fd/00'

	snprintf(sympath, sizeof(sympath), "/proc/%d/fd/%d", cur_pid, fd ); // create path with pid, fd 
	
	read_size = readlink(sympath, link_of_fd_path, FD_PATH_SIZE); // read real file path with fd path

	link_of_fd_path[read_size] = '\0'; // set end of string

	return link_of_fd_path; // return real file path of fd 

}

int main(){ 



	int fd2 = open("test2.txt", O_WRONLY );
	int fd3 = open("test3.txt", O_WRONLY );

	char buf[100];
	char pid[100];
	int cur_pid;


	cur_pid = getpid();
	
	
	printf("fd2\'s path = %s\n", getPathByFd(cur_pid, fd2) );
	printf("fd3\'s path = %s\n", getPathByFd(cur_pid, fd3) );


	close(fd2);
	close(fd3);



	
	return 0;
}
