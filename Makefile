cc = clang++ -std=c++2b

test: test.o scan.o 
	$(cc) -o $@  $^

test.o: test.cpp  scan.h
	$(cc) -c $<

	
scan.o: scan.cpp scan.h 
	$(cc) -c $<
run: 
	./test

clean: 
	rm -f *.o calc
