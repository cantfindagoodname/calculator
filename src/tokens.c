#include <stdlib.h>
#include <string.h>

#include "tokens.h"

TokenType tokenize(char *str)
{
        switch (*str) {
        case '+':
                return TOKEN_ADD;
        case '-':
                return TOKEN_SUB;
        case '*':
                return TOKEN_MUL;
        case '/':
                return TOKEN_DIV;
        case '(':
        case ')':
                return TOKEN_PAR;
        default:
                return TOKEN_NUM;
        }
}

void insert_token(TokenNode **list_pt, char *str)
{
        TokenNode *node = malloc(sizeof(TokenNode));
        node->token.value = strdup(str);
        node->token.type = tokenize(str);
        node->next = NULL;

        if (*list_pt == NULL) {
                *list_pt = node;
                return;
        }

        TokenNode *ref = *list_pt;
        while (ref->next != NULL)
                ref = ref->next;
        ref->next = node;
}

void free_list(TokenNode *list)
{
        for (TokenNode *pos = list, *tmp = pos->next; pos;
             pos = tmp, tmp = pos->next) {
                free(pos->token.value);
                free(pos);
        }
}
