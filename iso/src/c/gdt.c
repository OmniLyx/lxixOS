#include "gdt.h"

void InitializeGDT(void) {
    load_gdt();
    flush_segments();
}