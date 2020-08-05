    global assembly_function

    section .text

assembly_function:
    finit

    fld qword [rdi]
    fld qword [rsi]
    fadd
    fst qword [rdx]

    ret
