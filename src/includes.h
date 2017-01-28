#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include <stdint.h>

#define DEBUG
/*
#undef DEBUG
*/

#ifdef DEBUG
#include <stdio.h>
#endif

typedef enum bool {
    FALSE,
    TRUE
} bool;

#define CRYPT_EXT ".sisyph"

#endif