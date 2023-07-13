#ifndef IO_H
#define IO_H

unsigned char insb(unsigned short port);   // Read one byte from the given port
unsigned short insw(unsigned short port); // Read word from given port 

void outb(unsigned short port, unsigned char val);   // Output byte
void outw(unsigned short port, unsigned short val); // Output word

#endif // !IO_H

