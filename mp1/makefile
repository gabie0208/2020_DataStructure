all: $(target)
all: hw1_kmp hw1_naive

objects = hw1_kmp.o hw1_naive.o

hw1_kmp.o: hw1_kmp.c
	gcc -c hw1_kmp.c -o hw1_kmp.o
hw1_naive.o: hw1_naive.c
	gcc -c hw1_naive.c -o hw1_naive.o

clean:
	rm -f $(objects)
	rm -f *.o hw1_kmp hw1_naive
