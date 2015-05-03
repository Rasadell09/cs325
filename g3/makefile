myproc: myproc.c
	gcc -g -std=c99 -o $@ $<

clean:
	rm -f myproc.c~ myproc myproc.o makefile~ junk time.txt

test:
	( time for((a=1; a<=10; a++)); do ./myproc >> junk; done) 2>> time.txt
