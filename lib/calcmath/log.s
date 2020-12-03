section .data
section .bss
operand: resq 1
exp: resq 1
tmp: resq 1
section .text
global log:function
global antilog:function
log: ;log10(2)*log2(x)
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

antilog: ;2^(x*log2(10))
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    mov qword[rel tmp], 10
    fld qword[rel operand]
    fild qword[rel tmp]
    fyl2x
    fld st0
    frndint
    fsub st1, st0
    fld1
    fscale
    fxch
    fstp st0
    fxch
    f2xm1
    fld1
    faddp
    fmulp
    fstp qword[rel tmp]
    movsd xmm0, [rel tmp]
    leave
    ret