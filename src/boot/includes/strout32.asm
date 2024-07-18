use32

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f ; the color byte for each character

__print_string_label:
    mov edx, VIDEO_MEMORY

.print_string_pm_loop:
    mov al, [ebx] ; [ebx] is the address of our character
    mov ah, WHITE_ON_BLACK

    cmp al, 0 ; check if end of string
    je .print_string_pm_done

    mov [edx], ax ; store character + attribute in video memory
    add ebx, 1 ; next char
    add edx, 2 ; next video memory position

    jmp .print_string_pm_loop

.print_string_pm_done:
    ret

;PRINT MACRO
macro print _str* {
      mov ebx, _str
      call __print_string_label
}