#################################################
#        text segment                           #
#################################################

.text
.globl __start 
 __start:            # execution starts here
    la $a0,str       # put string address into a0
    li $v0,4         # system call to print
    syscall          # out a string
    li $v0,10
    syscall          # au revoir...

#################################################
#        data segment                           #
#################################################

.data
    str: .asciiz "hello world\n"

## end of file hello.asm