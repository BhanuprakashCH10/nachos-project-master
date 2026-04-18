#include <syscall.h>

int main() {
    PrintString("before sleeping for 5 \n");

    Sleep(500);

    PrintString("after sleeping");
}
