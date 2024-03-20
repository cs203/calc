cc = clang++ -std=c++2b

calc: calc.o tree.o
	$(cc) -o $@  $^

calc.o: calc.cpp tree.h
	$(cc) -c $<

tree.o: tree.cpp tree.h store.h
	$(cc) -c $<
	
run: 
	./calc

clean: 
	rm -f *.o calc
