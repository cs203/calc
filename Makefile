cc = clang++ -std=c++2b

calc: calc.o symtab.o store.o vlist.o htab.o
	$(cc) -o $@  $^

calc.o: calc.cpp symtab.h
	$(cc) -c $<

symtab.o: symtab.cpp symtab.h
	$(cc) -c $<

store.o: store.cpp store.h symtab.h
	$(cc) -c $<

vlist.o: vlist.cpp vlist.h
	$(cc) -c $<

htab.o: htab.cpp htab.h vlist.h
	$(cc) -c $<
	
run: 
	./calc

clean: 
	rm -f *.o calc
