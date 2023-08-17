#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
	hello();
	helloYou("This text is printed by helloYou system call");

	printf(1, "%d\n", getNumProc());
	
	int ret = fork();
	if( ret == 0) {
	  helloYou("This is child process after fork");
	  showAncestry();
	  exit();
	}
	
	wait();
	exit();	
}
