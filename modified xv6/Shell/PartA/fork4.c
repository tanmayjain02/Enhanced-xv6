#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(int argc, void *argv) {
  printf( "The main parent pid: %d\n" ,getpid());
  for(int i=0; i<4; i++) {

    int ret = fork();
    
    if(ret == 0) {
      printf("child %d\n", i);
    }

    else if ( ret > 0) {
      pid_t child_pid ;
    child_pid = wait( NULL) ;
    printf("child pid %d ,parent pid %d\n", child_pid ,getpid());
    } 

  }
}
