section .data
section .bss
operand1: resq 1
operand2: resq 1
tmp: resq 1
section .text
global add:function
global sub:function
add:
    push rbp
    mov rbp, rsp

    movsd [rel operand1], xmm0
    movsd [rel operand2], xmm1
    fld qword[rel operand1]
    fld qword[rel operand2]

    fadd

    fstp qword[rel tmp]
    movsd xmm0, [rel tmp]

    leave
    ret

sub:
    push rbp
    mov rbp, rsp

    movsd [rel operand1], xmm0
    movsd [rel operand2], xmm1
    fld qword[rel operand1]
    fld qword[rel operand2]

    fsub

    fstp qword[rel tmp]
    movsd xmm0, [rel tmp]

    leave
    ret