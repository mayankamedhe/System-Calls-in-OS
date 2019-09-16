#include <stdio.h>

int main()
{

        int i;
        i=fork();

        if(i==0)
        {

                printf("Child : My process ID is : %d\n", getpid());
        		printf("Child : The parent process ID is : %d\n", getppid());
        }
        else
        {
        	printf("Parent : My process ID is : %d\n", getpid());
    		printf("Parent : The child process ID is : %d\n", i);
            sleep(5);
        }

        return 0;


}