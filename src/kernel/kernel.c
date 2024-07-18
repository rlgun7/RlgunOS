/* ======================[ Инклуды ]=========================== */

#include <time.h>

#include            "headers/kernel.h"
#include            "../utils/headers/string.h"
#include            "../utils/headers/colors.h"

typedef             unsigned short          uint16_t;
typedef             unsigned char           uint8_t;

/* ============================================================ */

void loop();
void __main();

void print(int colour, const char *string) {
    volatile char *video = (volatile char*)0xb8000;
    while (*string != 0) {
        *video++ = *string++;
        *video++ = colour;
    }
}

/* ==================[ Основная функция ядра ]==================*/

void __main()
{
    clear_screen(BLACK_ON_BLACK, ' ');
    char str[] = "qwertyuiop[]asdfghjkl;'zxcvbnm,./`1234567890-=_+!@#$\\%^&*()0123";
    print(BLACK_ON_LIGHT_GREEN, str);
    loop();
}

void loop()
{
    for (;;);
}

/* ============================================================ */
