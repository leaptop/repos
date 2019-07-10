CFLAGS = -Wall -lm
SOURCES = src/MySimpleComputer.c src/MyTerm.c src/MyBigChar.c src/MyReadKeys.c src/Interface.c src/Source.c
OBJECTS = build/MySimpleComputer.o build/MyTerm.o build/MyBigChar.o build/MyReadKeys.o build/Interface.o build/Source.o

all :
	make bin/MySimpleComputer

bin/MySimpleComputer : $(OBJECTS)
	gcc build/MySimpleComputer.o build/MyTerm.o build/MyBigChar.o build/MyReadKeys.o build/Interface.o build/Source.o -o bin/MySimpleComputer $(CFLAGS)

build/MySimpleComputer.o : src/MySimpleComputer.c src/MySimpleComputer.h
	gcc -c src/MySimpleComputer.c -o build/MySimpleComputer.o $(CFLAGS)

build/MyTerm.o : src/MyTerm.c src/MyTerm.h
	gcc -c src/MyTerm.c -o build/MyTerm.o $(CFLAGS)

build/MyBigChar.o : src/MyBigChar.c src/MyBigChar.h
	gcc -c src/MyBigChar.c -o build/MyBigChar.o $(CFLAGS)

build/MyReadKeys.o : src/MyReadKeys.c src/MyReadKeys.h
	gcc -c src/MyReadKeys.c -o build/MyReadKeys.o $(CFLAGS)

build/Interface.o : src/Interface.c src/Interface.h
	gcc -c src/Interface.c -o build/Interface.o $(CFLAGS)

build/Source.o : src/Source.c 
	gcc -c src/Source.c -o build/Source.o $(CFLAGS)
	
clean : 
	@rm -rf build/*.o
	@rm bin/MySimpleComputer
	@echo "All files have been cleaned."
