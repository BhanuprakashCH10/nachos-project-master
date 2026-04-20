#include "syscall.h"

#define NULL 0

int main() {
    SpaceId newProc, newProc2;
    OpenFileId input = _ConsoleInput;
    OpenFileId output = _ConsoleOutput;

    char prompt[2], buffer[60];
    char buffer1[60], buffer2[60];

    int i, j, k, foundPipe;

    prompt[0] = '-';
    prompt[1] = '-';

    while (1) {
        Write(prompt, 2, output);

        i = 0;

        // Read input line
        do {
            Read(&buffer[i], 1, input);
        } while (buffer[i++] != '\n');

        buffer[--i] = '\0';

        if (i > 0) {

            //  Check for pipe '|'
            foundPipe = 0;
            for (j = 0; buffer[j] != '\0'; j++) {
                if (buffer[j] == '|') {
                    foundPipe = 1;
                    break;
                }
            }

            // ================= PIPE CASE =================
            if (foundPipe) {
                int p = 0, q = 0;

                // Left command
                for (k = 0; k < j; k++) {
                    buffer1[p++] = buffer[k];
                }
                buffer1[p] = '\0';

                // Right command
                for (k = j + 1; buffer[k] != '\0'; k++) {
                    buffer2[q++] = buffer[k];
                }
                buffer2[q] = '\0';

                // Create temp file (acts as pipe)
                Create("pipe.tmp");

                // Run producer
                newProc = Exec(buffer1);
                Join(newProc);

                // Run consumer
                newProc2 = Exec(buffer2);
                Join(newProc2);
            }

            // ================= NORMAL CASE =================
            else {
                newProc = Exec(buffer);
                Join(newProc);
            }
        }
    }
}
