#ifndef __TOKEN_H__
#define __TOKEN_H__

#define VALID_TOKENS "01234567890()+-*/"

typedef struct Token {
        enum {
                TOKEN_NUM,
                TOKEN_ADD,
                TOKEN_SUB,
                TOKEN_MUL,
                TOKEN_DIV,
        } type;
        char *value;
} Token;

typedef struct TokenList {
        Token token;
        struct TokenList *next;
} TokenList;

TokenList *token_list;

#endif /* __TOKEN_H__ */
