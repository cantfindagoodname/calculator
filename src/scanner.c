#include <stdio.h>
#include <stdlib.h>

#include "tokens.h"
#include "scanner.h"

static CharType char_type(int n)
{
        if (n >= '0' && n <= '9')
                return CT_DIG;
        if (n == '\0')
                return CT_END;
        if (n == '+' || n == '-' || n == '*' || n == '/')
                return CT_OP;
        else if (n == ' ' || n == '\t')
                return CT_SPACE;
        else
                return CT_INVALID;
}

void scanner(TokenNode **list, char *line)
{
        printf("You insert %s\n", line);
        LexState state = STATE_NEXT;
        while (state != STATE_END) {
                int c = 0, bidx;
                CharType ct = char_type(c);
                do {
                        c = *line++;
                        ct = char_type(c);
                } while (ct == CT_SPACE);

                if (ct == CT_END) {
                        switch (state) {
                        case STATE_NUMBER:
                                buf[bidx] = '\0';
                                insert_token(list, buf);
                        default:
                                state = STATE_END;
                                break;
                        }
                        break;
                } else if (ct == CT_INVALID) {
                        fprintf(stderr, "error: invalid input\n");
                        exit(1);
                }
                switch (state) {
                case STATE_NUMBER:
                        if (ct == CT_DIG) {
                                buf[bidx++] = c;
                        } else if (ct == CT_OP) {
                                buf[bidx] = '\0';
                                insert_token(list, buf);

                                bidx = 0;
                                buf[bidx++] = c;
                                buf[bidx++] = '\0';
                                insert_token(list, buf);
                                state = STATE_NEXT;
                        }
                        break;
                case STATE_NEXT:
                        if (ct == CT_DIG) {
                                bidx = 0;
                                buf[bidx++] = c;
                                state = STATE_NUMBER;
                        } else if (ct == CT_OP) {
                                bidx = 0;
                                buf[bidx++] = c;
                                buf[bidx++] = '\0';
                                insert_token(list, buf);
                        }
                        break;
                default:
                        break;
                }
        }
}
