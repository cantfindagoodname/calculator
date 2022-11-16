#ifndef __SCANNER_H__
#define __SCANNER_H__

#include "def.h"

typedef enum LexState {
        STATE_NUMBER,
        STATE_NEXT,
        STATE_END,
} LexState;

typedef enum CharType {
        CT_DIG,
        CT_OP,
        CT_END,
        CT_SPACE,
        CT_INVALID,
} CharType;

static char buf[BUF_SIZE + 1];

void scanner(char *input);

#endif
