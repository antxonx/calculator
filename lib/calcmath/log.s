section .data
section .bss
operand: resq 1
tmp: resq 1
section .text
global log:function
log:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fldlg2
    fld qword[rel operand]
    fyl2x
    fstp qword[rel tmp]
    movsd xmm0, [rel tmp]
    leave
    ret