RUN:
	gcc -c ./src/add.c -o ./obj/add.o
	gcc -c ./src/subt.c -o ./obj/subt.o
	gcc -c ./src/auxillaryFunc.c -o ./obj/auxillaryFunc.o
	ar cr ./lib/libbignum.a ./obj/add.o ./obj/subt.o ./obj/auxillaryFunc.o
	gcc -g ./src/test.c ./lib/libbignum.a -o ./bin/test
	./bin/test