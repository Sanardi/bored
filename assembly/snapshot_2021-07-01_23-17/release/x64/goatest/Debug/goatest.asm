.Data
wcount DQ 0
hello     DB 'Danke Dir!'
.Code
start:
    arg - 11
	Invoke GetStdHandle
	arg 0, Addr wcount, 27
	arg Addr hello, rax
	Invoke WriteFile
	Xor rax, rax
	Ret

