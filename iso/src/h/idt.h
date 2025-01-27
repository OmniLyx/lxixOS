#ifndef INCLUDE_IDT_H
#define INCLUDE_IDT_H

#include "stdint.h"  // Include custom stdint.h

/* Define the structure of an IDT entry */
struct IDTEntry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t  zero;
    uint8_t  flags;
    uint16_t base_high;
} __attribute__((packed));

/* Define the structure of the IDT pointer */
struct IDTPointer {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

/* Declare functions to initialize and set up the IDT */
void InitializeIDT(void);
void SetIDTEntry(int num, uint32_t base, uint16_t selector, uint8_t flags);

#endif
