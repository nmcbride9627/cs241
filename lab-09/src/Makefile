all: huffencode huffdecode

clean:
	-rm huffencode huffdecode *.o

huffencode: huffencode.o hufftree.o huffman.o
	gcc -Wall -ansi -pedantic -o huffencode huffencode.o hufftree.o huffman.o

huffdecode: huffdecode.o hufftree.o huffman.o
	gcc -Wall -ansi -pedantic -o huffdecode huffdecode.o hufftree.o huffman.o

huffencode.o: huffman.h huffencode.c
	gcc -Wall -ansi -pedantic -g -c huffencode.c

huffdecode.o: huffman.h huffdecode.c
	gcc -Wall -ansi -pedantic -g -c huffdecode.c

hufftree.o: hufftree.h hufftree.c
	gcc -Wall -ansi -pedantic -g -c hufftree.c

huffman.o: huffman.h hufftree.h huffman.c
	gcc -Wall -ansi -pedantic -g -c huffman.c
