section .data
section .bss
operand: resq 1
result: resq 1
frac: resq 1
xpow: resq 1
div: resq 1
temp: resq 1
deg: resq 1
section .text
global sin:function
global cos:function
global tan:function
global arcsin:function
global degreesToRadians:function
global radiansToDegrees:function
sin:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    call sin_calc
    movsd xmm0, [rel result]
    leave
    ret
cos:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    call cos_calc
    movsd xmm0, [rel result]
    leave
    ret
tan:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    call sin_calc
    mov rbx, [rel result]
    mov [rel temp], rbx
    fld qword[rel operand]
    call cos_calc
    fld qword[rel temp]
    fld qword[rel result]
    fdiv
    fstp qword[rel result]
    movsd xmm0, [rel result]
    leave
    ret

sin_calc:
    fsin
    fstp qword[rel result]
    ret
cos_calc:
    fcos
    fstp qword[rel result]
    ret

degreesToRadians:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    mov qword[rel deg], 180
    fldpi
    fild qword[rel deg]
    fdiv
    fstp qword[rel result]
    fld qword[rel operand]
    fld qword[rel result]
    fmul
    fstp qword[rel result]
    movsd xmm0, [rel result]
    leave
    ret

radiansToDegrees:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    mov qword[rel deg], 180
    fild qword[rel deg]
    fldpi
    fdiv
    fstp qword[rel result]
    fld qword[rel operand]
    fld qword[rel result]
    fmul
    fstp qword[rel result]
    movsd xmm0, [rel result]
    leave
    ret

arcsin:
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0

    fld1
    fstp qword[rel frac]

    fld qword[rel operand]
    fstp qword[rel xpow]

    fld qword[rel operand]
    fstp qword[rel result]

    mov rcx, 3
arcsinLoop:
    mov qword[rel temp], rcx
    sub qword[rel temp], 2

    mov qword[rel div], rcx
    sub qword[rel div], 1

    fild qword[rel temp]
    fild qword[rel div]
    fdiv
    fstp qword[rel temp]

    fld qword[rel frac]
    fld qword[rel temp]
    fmul
    fstp qword[rel frac]

    fld qword[rel operand]
    fld qword[rel operand]
    fmul
    fstp qword[rel temp]

    fld qword[rel xpow]
    fld qword[rel temp]
    fmul
    fstp qword[rel xpow]

    fld qword[rel frac]
    fld qword[rel xpow]
    fmul
    fstp qword[rel temp]

    fld qword[rel temp]
    mov [rel temp], rcx
    fild qword[rel temp]
    fdiv
    fstp qword[rel temp]

    fld qword[rel result]
    fld qword[rel temp]
    fadd
    fstp qword[rel result]

    add rcx, 2
    cmp rcx, 1000000
    jnge arcsinLoop

    movsd xmm0, [rel result]
    leave
    ret