#include "../h/display.h"
#include "../h/serial.h"
#include "../h/gdt.h"
#include "../h/idt.h"



void Boot(void) {
    char buff[5] = "Hello";
    ClearScreen(0x00);
    FrameBufferWrite(buff, 5);
    SerialConfigureBaudRate(0x3F8, 1);
    SerialConfigureLine(0x3F8);
    SerialWrite(0x3F8, buff);

    // Initialize and load the GDT
    InitializeGDT();

    // Initialize and load the IDT
    InitializeIDT();

    // check if the GDT is loaded
    // asm volatile("hlt");

    char loadedMSG[10] = "Loaded GDT";
    FrameBufferWrite(loadedMSG, 10);

    asm volatile("hlt");
}