; Everything that comes after a semicolon (;) is a comment

WEIGHT_OF_EMPTY_BOX equ 500
TRUCK_HEIGHT equ 300
PAY_PER_BOX equ 5
PAY_PER_TRUCK_TRIP equ 220

section .text

; You should implement functions in the .text section
; A skeleton is provided for the first function

; the global directive makes a function visible to the test files
global get_box_weight
get_box_weight:
    movzx r8d, di
    movzx r9d, si
    movzx r10d, dx
    movzx r11d, cx

    imul r8d, r9d
    imul r10d, r11d

    mov eax, WEIGHT_OF_EMPTY_BOX
    add eax, r8d
    add eax, r10d
    ret

global max_number_of_boxes
max_number_of_boxes:
    mov ax, TRUCK_HEIGHT
    div dil  
    ret

global items_to_be_moved
items_to_be_moved:
    ;first is in edi
    ;second is in esi
    sub edi, esi

    mov eax, edi
    ret

global calculate_payment
calculate_payment:
    ; received is in rdi
    ; boxes moved is in rsi
    ; number of trips in rdx
    ; missing items in rcx
    ; lost items in r8
    ; amnout of workers in r9

    mov rax, PAY_PER_BOX   
    imul rax, rsi
    
    mov r10, PAY_PER_TRUCK_TRIP
    imul r10, rdx
    add rax, r10

    sub rax, rdi
    imul rcx, r8
    sub rax, rcx

    movzx r11, r9b
    inc r11
    cqo
    idiv r11

    add rax, rdx
    
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
