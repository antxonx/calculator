section .data
section .bss
operand: resq 1
result: resq 1
temp: resq 1
deg: resq 1
section .text
global sin:function
global cos:function
global tan:function
global arcsin:function
global arctan:function
global arccos:function
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
tan: ;sin(x)/cos(x)
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

degreesToRadians: ;x * (180/PI)
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

radiansToDegrees: ;x * (PI/180)
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

arcsin: ;arctan(x/sqrt(1-x^2))
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    fld qword[rel operand]
    fmul
    fstp qword[rel temp]
    fld1
    fld qword[rel temp]
    fsub
    fstp qword[rel temp]
    fld qword[rel temp]
    fsqrt 
    fstp qword[rel temp]
    fld qword[rel operand]
    fld qword[rel temp]
    fpatan
    fstp qword[rel result]
    movsd xmm0, [rel result]
    leave
    ret

arctan: ;arctan(x/1)
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    fld1
    fpatan
    fstp qword[rel result]
    movsd xmm0, [rel result]
    leave
    ret

arccos: ;arctan(sqrt(1-x^2))
    push rbp
    mov rbp, rsp
    movsd [rel operand], xmm0
    fld qword[rel operand]
    fld qword[rel operand]
    fmul 
    fstp qword[rel temp]
    fld1
    fld qword[rel temp]
    fsub
    fstp qword[rel temp]
    fld qword[rel temp]
    fsqrt
    fstp qword[rel result]
    movsd xmm0, [rel result]
    call arcsin
    leave
    ret