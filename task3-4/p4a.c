#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sz1;
    int sz2;
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
     perror("r1");
     exit(1);
    }
    printf("Parent: File opened. fd=%d.\n", fd);
    sz2 = write(fd, "hello world! I am the parent\n", strlen("hello world! I am the parent\n"));
    printf("Parent %d: writing to file %d\n", getpid, fd);

	pid_t cpid;
    int i;
    i=fork();

    if(i==0)
    {
        printf("Child %d: writing to file %d\n", getpid(), fd);
        sz1 = write(fd, "hello world! I am the child\n", strlen("hello world! I am the child\n"));
    }
    else
    {
    	//sleep(15);
    	cpid = wait(NULL);
        printf("Parent : The child has terminated.\n");
        close(fd);
    }

    return 0;


}