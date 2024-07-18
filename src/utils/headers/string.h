#ifndef STRING_H
#define STRING_H

#include <stddef.h>

// Прототипы функций из string.c
size_t strlen(const char* str);
void strcpy(char* dest, const char* src, size_t dest_size);
int strcmp(const char* str1, const char* str2);
char* strncpy(char* dest, const char* src, size_t n);
char* strcat(char *dest, const char *src);

#endif // STRING_H
