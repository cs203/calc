cc = clang++ -std=c++2b

calc: calc.o scan.o 
	$(cc) -o $@  $^

calc.o: calc.cpp scan.h
	$(cc) -c $<

scan.o: scan.cpp scan.h
	$(cc) -c $<
	
run: 
	./calc

clean: 
	rm -f *.o calc
