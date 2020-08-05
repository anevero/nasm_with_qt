    global assembly_function

    section .text

assembly_function:
    finit

    fld qword [rcx]
    fld qword [rdx]
    fadd
    fst qword [r8]

    ret
