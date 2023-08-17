#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
	printf(1,  "Ancestors of Current process:\n ");
	showAncestry();
	int ret = fork();
	
	if( ret == 0){
	  printf(1,  "Ancestors of Child process:\n ");
	  showAncestry();
	  
	  int ret1 = fork();
	  
	  if( ret1 ==0 ){
	    printf(1,  "Ancestors of Grand Child process:\n ");
	    showAncestry();
	    exit();
	  }
	  wait();
	  exit();
	}
	
	wait();
	exit();	    
}
