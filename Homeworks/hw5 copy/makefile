hw5: hw5.h hw5.c hw5_main.c 
	clang -Wall -o hw5 hw5.c hw5_main.c 

warmup5: warmup5.c warmup5_main.c warmup5.h warmup5_provided.c
	clang -c -Wall -o warmup5_provided.o warmup5_provided.c
	clang -Wall -lpng -o warmup5 warmup5_provided.o warmup5.c warmup5_main.c
	chmod +x testscript

warmup5_provided: warmup5_provided.h warmup5_provided.c
	clang -c -Wall -o warmup5_provided.o warmup5_provided.c
