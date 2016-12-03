all: huffencode huffdecode

clean:
	-rm huffencode huffdecode *.o

huffencode: huffencode.o hufftree.o huffman.o
	gcc -Wall -ansi -pedantic -o -g huffencode huffencode.o hufftree.o huffman.o

huffdecode: huffdecode.o hufftree.o huffman.o
	gcc -Wall -ansi -pedantic -o -g huffdecode huffdecode.o hufftree.o huffman.o

huffencode.o: huffman.h huffencode.c
	gcc -Wall -ansi -pedantic -c -g huffencode.o huffencode.c

huffdecode.o: huffman.h huffdecode.c
	gcc -Wall -ansi -pedantic -c -g huffdecode.o huffdecode.c

hufftree.o: hufftree.h huftree.c
	gcc -Wall -ansi -pedantic -c -g hufftree.o hufftree.c

huffman.o: huffman.h hufftree.h huffman.c
	gcc -Wall -ansi -pedantic -c -g huffman.o huffman.c
