all: huffencode huffdecode

clean:
	-rm huffencode huffdecode *.o

huffencode: huffencode.o hufftree.o huffman.o
	gcc -Wall -ansi -pedantic -o -g huffencode.o hufftree.o huffman.o

huffdecode: huffdecode.o hufftree.o huffman.o
	gcc -Wall -ansi -pedantic -o -g huffdecode.o hufftree.o huffman.o

huffencode.o: huffman.h huffencode.c
	gcc -Wall -ansi -pedantic -c -g huffencode.c

huffdecode.o: huffman.h huffdecode.c
	gcc -Wall -ansi -pedantic -c -g huffdecode.c

hufftree.o: hufftree.h hufftree.c
	gcc -Wall -ansi -pedantic -c -g hufftree.c

huffman.o: huffman.h hufftree.h huffman.c
	gcc -Wall -ansi -pedantic -c -g huffman.c
