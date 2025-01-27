#include "idt.h"

/* Define the IDT with 256 entries */
struct IDTEntry idt[256];
struct IDTPointer idt_ptr;

/* External function to load the IDT, implemented in assembly */
extern void LoadIDT(uint32_t);

/* Function to set an entry in the IDT */
void SetIDTEntry(int num, uint32_t base, uint16_t selector, uint8_t flags) {
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].selector = selector;
    idt[num].zero = 0;
    idt[num].flags = flags;
}

/* Function to initialize the IDT */
void InitializeIDT(void) {
    idt_ptr.limit = sizeof(idt) - 1;
    idt_ptr.base = (uint32_t)&idt;

    /* Clear the IDT */
    for (int i = 0; i < 256; i++) {
        SetIDTEntry(i, 0, 0, 0);
    }

    /* Load the IDT */
    LoadIDT((uint32_t)&idt_ptr);
}
