RUN:
	gcc -c add.c subt.c auxillaryFunc.c
	ar cr libbignum.a add.o subt.o auxillaryFunc.o
	gcc -g test.c -L. -lbignum
	./a.out