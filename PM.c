#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
void main(){
    pid_t pid;
    int ret = 1;
    int status;
    pid = fork();
    if (pid == -1){
        printf("Cannot fork, Error occured\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0){
        printf("Child process, pid = %u\n", getpid());
        printf("Parent of child process, pid = %u\n", getppid());
        char *argv_list[] = {"ls", "-lart", "/home", NULL};
        execv("ls", argv_list);
        exit(0);
    }
    else{
        printf("Parent Of parent process, pid = %u\n", getppid());
        printf("Parent process, pid = %u\n", getpid());
        if (waitpid(pid, &status, 0) > 0){
            if (WIFEXITED(status) && !WEXITSTATUS(status))
                printf("Program execution successful\n");
            else if (WIFEXITED(status) && WEXITSTATUS(status)){
                if (WEXITSTATUS(status) == 127){
                    printf("Execution failed\n");
                }
                else
                    printf("Program terminated normally, but returned a non-zero status\n");
            }
            else
                printf("Program didn't terminate normally\n");
        }
        else{
            printf("waitpid() failed\n");
        }
        exit(0);
    }
}