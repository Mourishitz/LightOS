#ifndef IDT_H
#define IDT_H

#include <stdint.h>

struct idt_desc
{
    uint16_t offset_1; // Offset bits 0 -15
    uint16_t selector; // Selector thats in our GDT
    uint8_t zero;      // Does nothing, unused set to zero 
    uint8_t type_attr; // Decsriptor type and attributes
    uint16_t offset_2; // Offset bits 16-31

} __atribute__((packed));

struct idtr_dect
{
    uint16_t limit; // Size of descriptor table -15
    uint32_t base; // Base address of the start of the interrupt descriptor table
} __atribute__((packed));

#endif

