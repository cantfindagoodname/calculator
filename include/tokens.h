#ifndef __TOKEN_H__
#define __TOKEN_H__

#define VALID_TOKENS "01234567890()+-*/"

typedef enum type {
        TOKEN_NUM,
        TOKEN_ADD,
        TOKEN_SUB,
        TOKEN_MUL,
        TOKEN_DIV,
        TOKEN_PAR, /* parentheses */
} TokenType;

typedef struct Token {
        TokenType type;
        char *value;
} Token;

typedef struct TokenNode {
        Token token;
        struct TokenNode *next;
} TokenNode;

TokenType tokenize(char *str);
void insert_token(TokenNode **list_pt, char *str);
void cleanup_list(TokenNode **list_pt);
void free_list(TokenNode *list);

#endif /* __TOKEN_H__ */
