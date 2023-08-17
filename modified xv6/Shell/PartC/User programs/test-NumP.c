#include "types.h"
#include "stat.h"
#include "user.h"


int main(void) {
	printf(1, "Total no of process at beginning: %d\n", getNumProc());
	int ret = fork() ;
	
	if( ret == 0 ) {
	  printf(1, "Total no of process after 1st fork: %d\n", getNumProc());
	
	  int ret1 = fork() ;
	
	  if( ret1 == 0) {
	    printf(1, "Total no of process after 2nd fork: %d\n", getNumProc());
	    exit();
	  }
	  else if( ret1 > 0) {
	    wait();
	    printf(1, "Total no of process after 1st exit: %d\n", getNumProc());
	    exit();
	  }
	}
	
	else if( ret > 0) {
	  
	  wait();
	  printf(1, "Total no of process after 2nd exit: %d\n", getNumProc());
	}
	exit();
}

