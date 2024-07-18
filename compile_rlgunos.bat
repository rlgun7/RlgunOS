fasm\fasm.exe src/boot/bootloader.asm src/cache/bootloader.bin

gcc -m32 -ffreestanding -nostdlib -lgcc -Wall -c -o src\cache\kernel.o src\kernel\kernel.c -lc

gcc -m32 -ffreestanding -nostdlib -lgcc -Wall -c -o src\cache\string.o src\utils\string.c

fasm\fasm.exe src\boot\kernelentr.asm src\cache\kernelentr.o

fasm\fasm.exe src\boot\includes\functions.asm src\cache\functions.o

ld -T NUL -o src\cache\kernel.tmp -Ttext 0x1000 src\cache\kernelentr.o src\cache\kernel.o src\cache\functions.o src\cache\string.o
objcopy -O binary -j .text src/cache/kernel.tmp src/cache/kernel.bin

copy /b src\cache\bootloader.bin+src\cache\kernel.bin builds\os.bin

C:\Users\egr\Documents\qemu\qemu-system-x86_64.exe -drive format=raw,file=builds\os.bin -d int,cpu_reset,guest_errors,in_asm -D qemu_log.txt