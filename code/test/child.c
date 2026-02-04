#include "syscall.h"

int main(){
	int i;
	for(i =0; i<10; i++){
		Write("Child is rinning\n", 17,1);
	}

	Halt();
}
