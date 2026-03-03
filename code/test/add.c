/* add.c
 *	Simple program to test whether the systemcall interface works.
 *
 *	Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int main() {
    int result, i;

    result = Add(40, 23);
    //PrintNum(result);
    for(i=0; i<10; i++){
	 Write("C\n", 2,1);
     }
    Exit(0);
    //Halt();
    /* not reached */
}
