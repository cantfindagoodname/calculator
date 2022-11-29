#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokens.h"
#include "def.h"
#include "scanner.h"

/* Input buffer */
static char buf[BUF_SIZE + 1];

int main()
{
        TokenNode *token_list = NULL;
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

                scanner(&token_list, buf);

                free(token_list);
                token_list = NULL;
        }
        return 0;
}
