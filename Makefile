CC: gcc
CFLAGS: -Wall -O0

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
five: bin
	@$(CC) -o bin/five-static $(CFLAGS) src/loopsstaticshell.c
	@$(CC) -o bin/five-dynamic $(CFLAGS) src/loopsdynamicshell.c
six: bin
	@$(CC) -o bin/six $(CFLAGS) src/6.c 
all: one two three four five six
results: all
	@mkdir -p results
	./bin/one Daniel > results/one.txt
	./bin/two > results/two.txt
	./bin/three > results/three.txt
	./bin/four > results/four.txt
	./bin/five-static > results/five-static.txt
	./bin/five-dynamic > results/five-dynamic.txt
	echo 'Daniel' | ./bin/six caesar > results/six.txt
	echo 'Daniel' | ./bin/six reverse >> results/six.txt
clean:
	@rm -rf ./bin
	@rm -rf ./results


