#ifndef OBJECT_H
#define OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

#define OBJ_NAME_MAX 24

typedef struct {
    char     name[OBJ_NAME_MAX];
    uint32_t id;
} Object;

void     Object_Init(Object *obj, const char *name, uint32_t id);
Object  *Object_New(const char *name, uint32_t id);
void     Object_Delete(Object *obj);

#ifdef __cplusplus
}
#endif

#endif
