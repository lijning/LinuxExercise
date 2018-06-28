#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pid, qid;
    printf("I am main process!\n");
    char p1p2[] = {"Child process p1 is sending a message!"};
    char p2p1[] = {"Child process p2 is sending a message!"};
    char buf[128];
    int fd12[2], fd21[2];
    if (pipe(fd12) == -1 || pipe(fd21) == -1)
        exit(-1);
    pid = fork(); // new process.
    if (pid == 0)
    {
        close(fd12[0]);
        close(fd21[1]);
        /*pid = fork();
        if (pid == 0)
        { //p3
            printf("I am child process p3 \n");
            execl("ls", "-Rl", NULL);
            printf("p3 process PID %d \n", getpid());
            close(fd12[1]);
            close(fd21[0]);
			return 0;
        }
        else*/
        { //子进程p1执行代码
            printf("p1 process PID %d \n", getpid());
            write(fd12[1], p1p2, sizeof(p1p2));
            read(fd21[0], buf, sizeof(buf));
            printf("%s \n", buf);
            close(fd12[1]);
			close(fd21[0]);
			exit(0);
		}
    }
    else
    {
        //父进程执行代码
        printf("main process PID %d \n", getpid());
        pid = fork();
        if (pid == 0)
        { //p2
            printf("p2 process PID %d \n", getpid());
            close(fd12[1]);
            close(fd21[0]);

            read(fd12[0], buf, sizeof(buf));
            printf("%s \n", buf);
            write(fd21[1], p2p1, sizeof(p2p1));
            close(fd12[0]);
			close(fd21[1]);
			exit(0);
		}
        else
        {
            close(fd12[0]);
            close(fd21[1]);
            close(fd12[1]);
			close(fd21[0]);
			exit(0);
		}
    }
}
