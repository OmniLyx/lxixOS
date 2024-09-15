#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

void InitializeGDT(void);

void load_gdt(void);

void flush_segments(void);


#endif /* INCLUDE_GDT_H */