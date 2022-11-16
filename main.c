#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"
#include "scanner.h"

/* Input buffer */
static char buf[BUF_SIZE + 1];

int main()
{
        while (1) {
                /* Get Input */
                fprintf(stdout, "(calc) ");
                fscanf(stdin, "\n%" STR(BUF_SIZE) "[^\n]", buf);
                /* Input reach buffer limit */
                if (strlen(buf) == BUF_SIZE) {
                        fprintf(stdout, "warning: %d character limit\n",
                                BUF_SIZE);
                        fscanf(stdin, "%*[^\n]");
                }

                scanner(buf);
        }
        return 0;
}
