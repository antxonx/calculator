section .data
section .bss
operand: resq 1
result: resq 1
temp: resq 1
section .text
global sin:function
global cos:function
global tan:function
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