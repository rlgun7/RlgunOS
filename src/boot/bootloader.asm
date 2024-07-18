format binary
; preparation
org 0x7c00
use16

begin:
    xor ax, ax
    mov ds, ax
    mov es, ax

    mov [disk], dl ; save disk number for later

    mov si, loading16 ; print welcome string
pchar:
    .lp:
        mov al, [si]
        cmp al, 0
        je .exit
        mov ah, 0eh
        int 10h
        add si, 1
        jmp .lp
    .exit:

    ; Delay for 1 second
    mov ax, 0x8600 ; AH = 86h (Wait), AL = 00h (milliseconds)
    int 15h        ; BIOS interrupt to wait

    mov ah, 0  ;reset disk
    int 13h

    ; load kernel_entry and kernel from disk
    mov ah, 2h     ;read sectors
    mov al, 1      ;sectors to read
    mov ch, 0      ;cylinder idx
    mov dh, 0      ;head idx
    mov cl, 2      ;sector idx
    mov dl, [disk] ;disk idx
    mov bx, 0x1000 ;target pointer
    int 13h

    ; get into pm and jump to KERNEL label
    jmp switch_to_pm

    jmp $ ; never executed

use32
KERNEL:
    jmp 0x1000 ; jump to the actual kernel

    jmp $ ; never executed

include '/includes/gdt.asm'        ; gdt for protected mode
include '/includes/switch32.asm'   ; code for entering protected mode
include '/includes/strout32.asm'   ; protected mode print

;; data

disk: rb 1

use16
wc32: db "__switch_32", 0
loading16: db "__switch_16"
osver: db "231064", 0

;bootloader fill
times 510-($-$$) db 0
;magic number
dw 0xaa55

;;;;;;;;;;;;;
