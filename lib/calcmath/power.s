section .data
section .bss
operand: resq 1
tmp: resq 1
section .text
global sqexp:function
global sqroot:function
sqexp: ;x*x
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    fld qword[rel operand]
    fmul
    fstp qword[rel tmp]
    movsd xmm0, [rel tmp]
    leave
    ret
sqroot: ;sqrt(x)
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    fsqrt
    fstp qword[rel tmp]
    movsd xmm0, [rel tmp]
    leave
    ret