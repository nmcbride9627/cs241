all: huffencode huffdecode

clean:
	-rm huffencode huffdecode

huffencode: huffman.h huffman.c hufftree.h hufftree.c huffencode.c
	gcc -Wall -ansi -pedantic -o huffencode hufftree.c huffman.c huffencode.c

huffdecode: huffman.h huffman.c hufftree.h hufftree.c huffdecode.c
	gcc -Wall -ansi -pedantic -o huffdecode hufftree.c huffman.c huffdecode.c
