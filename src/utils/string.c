#include <stddef.h>

// Определяем цвета для текстового режима VGA
#define WHITE_COLOR 15

// Функция для вычисления длины строки
size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Функция для копирования строки с учетом размера целевой строки
void strcpy(char* dest, const char* src, size_t dest_size) {
    size_t i = 0;
    while (i < dest_size - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Добавляем завершающий нулевой символ
}

// Функция для сравнения строк
int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Функция для копирования строки с учетом размера целевой строки
char* strncpy(char* dest, const char* src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

char* strcat(char *dest, const char *src) {
    char *d = dest;

    // Перемещение указателя на конец строки dest
    while (*d) {
        d++;
    }

    // Копирование src в dest
    while (*src) {
        *d++ = *src++;
    }

    // Завершение строки
    *d = '\0';

    return dest;
}