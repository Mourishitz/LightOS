section .asm

extern int21_handler
extern no_interrupt_handler

global int21h
global idt_load
global no_interrupt
global enable_interrupts

enable_interrupts:
    sti
    ret

disable_interrupts:
    cli
    ret

idt_load:
    push ebp
    mov ebp, esp

    mov ebx, [ebp+8]
    lidt [ebx]
    pop ebp
    ret

int21h:
  ; faydoc.tripod.com/cpu/pushad.htm
  cli ; Clear interrupts
  pushad

  call int21_handler ; Call C handler

  popad
  sti
  iret

no_interrupt:
  cli
  pushad

  call no_interrupt_handler 
  
  popad
  sti
  iret
