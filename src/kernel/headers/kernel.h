#ifndef KERNEL_H
#define KERNEL_H
#pragma once
#define             MEM                             753664
#define             VGA_WIDTH                       80
#define             VGA_HEIGHT                      25
#define             MAX_CHUNK_SIZE                  64
#define             SCREEN_WIDTH                    80
#include            "../../utils/headers/string.h"
#include <stdio.h>
typedef unsigned int uint32_t;

void printc(int colour, char c);
void clear_screen(int colour, char fill_char);
void print_str(char* string);


void write(uint32_t reg, uint32_t value, uint32_t DEVICE_BASE_ADDRESS) {
    volatile uint32_t* reg_address = (volatile uint32_t*)(DEVICE_BASE_ADDRESS + reg);
    *reg_address = value;
}


/* ===========[ Функция для вывода строки через VGA ]========== */


void printc(int colour, char c) {
    volatile char *video = (volatile char*)MEM;
    *video++ = c;
    *video++ = colour;
}


/* ============================================================ */

/* ==========[ Функция для очистки/заполнения экрана ]========= */
void clear_screen(int colour, char fill_char) {
    volatile char *video = (volatile char*)MEM; 
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        *video++ = fill_char;
        *video++ = colour;
    }
}

/* ============================================================ */

#endif