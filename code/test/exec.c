/* exec.c
 *	Simple program to test the exec system call.
 */

#include "syscall.h"
#define stdin 0
#define stdout 1

int main() {
    int pid;
    int i;

    pid = Exec("../test/add");

    for (i = 0; i < 10; i++) {
        Write("P\n", 2, stdout);
    }
    if (pid >= 0) {
        Join(pid);
    } else {
        Write("Exec failed\n", 12, stdout);
    }
    Exit(0);
    // Halt();
}
