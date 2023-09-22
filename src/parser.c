#include <stdlib.h>

#include "def.h"
#include "tokens.h"

typedef enum ParseType {
        PARSE_VALUE,
        PARSE_UNARY,
        PARSE_ARITH,
} ParseType;

typedef struct ParseTree {
        ParseType type;
        TokenNode token;
        int state;
        struct ParseTree *c0, *c1;
} ParseTree;

/* function pointer : shift reduce
 * input : stack, 1 from list at most (only when shifting)
 */
void parser(TokenNode *list)
{
        TokenNode stack[BUF_SIZE];
        int tail = 0;
}

ParseTree *parse_action_1(TokenNode *stack, int *tail, TokenNode **list_head_p)
{
        ParseTree *tn = malloc(sizeof(tn));
        tn->type = PARSE_VALUE;
        tn->c0 = tn->c1 = NULL;
        // state = lookup table

        tn->token.value = NULL;
        tn->token.type = TOKEN_NUM;

        tn->c0 = (*list_head_p)->token;
        *list_head_p = (*list_head_p)->next;
}
