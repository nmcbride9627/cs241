all: huffencode huffdecode

clean:
	-rm huffencode huffdecode *.o

huffencode: huffman.h huffman.c huffencode.c
	gcc -Wall -ansi -pedantic -o -g huffencode hufftree.o huffman.o

huffdecode: huffman.h huffman.c huffdecode.c
	gcc -Wall -ansi -pedantic -o -g huffdecode hufftree.o huffman.o

hufftree.o: hufftree.h huftree.c
	gcc -Wall -ansi -pedantic -c -g hufftree.o hufftree.c

huffman.o: huffman.h hufftree.h huffman.c
	gcc -Wall -ansi -pedantic -c -g huffman.o huffman.c
