cc = clang++ -std=c++2b -g

calc: calc.o symtab.o store.o scan.o tree.o parser.o
	$(cc) -o $@  $^

calc.o: calc.cpp parser.h symtab.h scan.h store.h
	$(cc) -c $<

symtab.o: symtab.cpp symtab.h
	$(cc) -c $<
	
store.o: store.cpp store.h symtab.h
	$(cc) -c $<

tree.o: tree.cpp tree.h
	$(cc) -c $<

scan.o: scan.cpp scan.h
	$(cc) -c $<

parser.o: parser.cpp parser.h scan.h tree.h symtab.h store.h
	$(cc) -c $<
run: 
	./calc

clean: 
	rm -f *.o calc
