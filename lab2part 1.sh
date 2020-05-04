/*
# Name: Moses Garcia
# Date: March 17, 2020
# Title: Lab2 C lang 
# Description: Uses fork(); and wait();
*/
#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */

int main(int argc, char *argv[]) {
pid_t pid;
int i;
int n;
n = atoi(argv[1]);
	printf("\n Before forking. \n");
	pid = fork();
	if ( pid == -1) {
fprintf(stderr, "can't fork, error %d\n",errno); 
}
else if (pid == 0)
{
execlp("/bin/ls", "ls", NULL); 

}
else
{
wait(NULL); 
printf("Child Ready"); 
exit(0); 
}
return(0); 
}
