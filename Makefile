CC = gcc
CFLAGS = -Wall -O0 -g

FIVE_SIZES = 128 256 512 1024 2048 4096 

bin:
	@mkdir -p bin
one: bin
	@$(CC) -o bin/one $(CFLAGS) src/1.c 
two: bin
	@$(CC) -o bin/two $(CFLAGS) -lm src/2.c
three: bin
	@$(CC) -o bin/three $(CFLAGS) src/3.c 
four: bin
	@$(CC) -o bin/four $(CFLAGS) -lm src/4.c 
six: bin
	@$(CC) -o bin/six $(CFLAGS) src/6.c 
all: one two three four five_test six
results: all 
	@mkdir -p results
	echo 'Daniel' | ./bin/one 
	./bin/two > results/two.txt
	./bin/three > results/three.txt
	./bin/four > results/four.txt
	echo 'Daniel' | ./bin/six caesar > results/six.txt
	echo 'Daniel' | ./bin/six reverse >> results/six.txt
clean:
	@rm -rf ./bin
	@rm -rf ./results

five_test: bin 
	@mkdir -p results
	@for size in $(FIVE_SIZES); do \
		echo "Testing static size $$size..."; \
		$(CC) -o bin/five-static-$$size $(CFLAGS) src/loopsstaticshell.c -DN=$$size; \
		valgrind --tool=cachegrind --cache-sim=yes --main-stacksize=167772160 --cachegrind-out-file=results/five-static-$$size.cachegrind.out --log-file=results/five-static-$$size.cachegrind ./bin/five-static-$$size > results/five-static-$$size.txt; \
		cg_annotate --show=Dr,D1mr,DLmr results/five-static-$$size.cachegrind.out > results/five-static-$$size.cachegrind.annotated; \
		echo "Testing dynamic size $$size..."; \
		$(CC) -o bin/five-dynamic-$$size $(CFLAGS) src/loopsdynamicshell.c -DN=$$size; \
		valgrind --tool=cachegrind --cache-sim=yes --main-stacksize=167772160 --cachegrind-out-file=results/five-dynamic-$$size.cachegrind.out --log-file=results/five-dynamic-$$size.cachegrind ./bin/five-dynamic-$$size > results/five-dynamic-$$size.txt; \
		cg_annotate --show=Dr,D1mr,DLmr results/five-dynamic-$$size.cachegrind.out > results/five-dynamic-$$size.cachegrind.annotated; \
	done


