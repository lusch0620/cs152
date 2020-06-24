warmup4: warmup4.c warmup4_main.c warmup4.h hw4_provided.c
	clang -c -Wall -o hw4_provided.o hw4_provided.c
	clang -Wall -lpng -o warmup4 hw4_provided.o warmup4.c warmup4_main.c

hw4_provided: hw4_provided.h hw4_provided.c
	clang -c -Wall -o hw4_provided.o hw4_provided.c

hw4: hw4.h hw4.c hw4_main.c hw4_provided.c hw4_provided.h
	clang -Wall -lpng -o hw4 hw4.c hw4_main.c hw4_provided.c
