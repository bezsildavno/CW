CFLAGS = -Wall -Werror -std=c99


.PHONY : clean running all prog


all : prog running


prog : 
	make bin/skob

build/main.o : src/main.c
	gcc $(CFLAGS) -c src/main.c -o build/main.o 

build/skob.o : src/skob.c
	gcc $(CFLAGS) -c src/skob.c -o build/skob.o 
    
bin/skob : build/main.o build/skob.o
	gcc build/main.o build/skob.o -o bin/skob


running :
	./bin/skob


clean :
	rm -rf build/*.d 
	rm -rf build/*.o
	rm -rf bin/skob
