#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
		pid_t cpid;
        int i;

        close(0);

        int fd = open(argv[1], O_RDWR | O_CREAT ,S_IRWXU);
        if (fd < 0)
        {
         perror("r1");
         exit(1);
        }
        printf("Parent: File opened: fd=%d.\n", fd);

        i=fork();

        if(i==0)
        {

          //       printf("Child : My process ID is: %d\n", getpid());
        		// printf("Child : The parent process ID is: %d\n", getppid());
                char *args[]={"./mycat",NULL};
                execvp(args[0],args);
        }
        else
        {
        	//sleep(15);
        	cpid = wait(NULL);
            printf("Parent : The child has terminated.\n");
            close(fd);
			// printf("Parent : My process ID is: %d\n", getpid());
   //  		printf("Parent : The child process ID is: %d\n", i);
   //  		printf("Parent : The child with process ID %d has terminated.\n", i);
        }

        return 0;


}