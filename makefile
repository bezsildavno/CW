CFLAGS =-I thirdparty -Wall -Werror -std=c99

.PHONY : clean running all prog test


all : prog test running

prog : 
	make bin/skob

build/main.o : src/main.c
	gcc $(CFLAGS) -c src/main.c -o build/main.o 

build/skob.o : src/skob.c
	gcc $(CFLAGS) -c src/skob.c -o build/skob.o 
    
bin/skob : build/main.o build/skob.o
	gcc build/main.o build/skob.o -o bin/skob
	

test : 
	make bin/skobt

bin/skobt : build/test/main.o build/test/skob_test.o build/test/skob.o
	gcc build/test/main.o build/test/skob_test.o build/test/skob.o -o bin/skobt

build/test/main.o : test/main.c 
	gcc $(CFLAGS) -c test/main.c -o build/test/main.o 

build/test/skob_test.o : test/skob_test.c
	gcc $(CFLAGS) -c test/skob_test.c -o build/test/skob_test.o 

build/test/skob.o : src/skob.c
	gcc $(CFLAGS) -c src/skob.c -o build/test/skob.o 


running :
	./bin/skobt

clean :
	rm -rf build/*.d build/test/*.d 
	rm -rf build/*.o build/test/*.o
	rm -rf bin/skobt bin/skob
