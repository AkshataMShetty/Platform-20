.PHONY : clean

app : file_op.o validate.o alpha_numeric.o numeric.o
		gcc -o app *.o 

file_op.o : file_op.c header.h
		gcc -c file_op.c

validate.o : validate.c header.h
		gcc -c validate.c

alpha_numeric.o : alpha_numeric.c header.h
		gcc -c alpha_numeric.c

numeric.o : numeric.c header.h
		gcc -c numeric.c

clean :
	rm *.o
	rm app
