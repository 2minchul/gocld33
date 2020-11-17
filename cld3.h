//
// Created by 이민철 on 2020/11/17.
//
#include <stdbool.h>
#include <stdlib.h>

#ifndef CLD3_CLD3_H
#define CLD3_CLD3_H

#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
    char *language;
    int len_language;
} Result;

Result lang_detect(const char *text);

#ifdef __cplusplus
}
#endif

#endif //CLD3_CLD3_H
