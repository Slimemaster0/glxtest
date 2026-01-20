ExternalLibs=-lGL -lglfw -lGLEW -lglut
Flags=-O2 -flto

srcDir=src/

VPATH = src/

output: main.o files.o
	g++ $(ExternalLibs) $(Flags) $(srcDir)main.o $(srcDir)files.o -o gltest


main.o: main.cpp
	g++ $(Flags) -c $(srcDir)main.cpp -o $(srcDir)/main.o
	
files.o: files.cpp
	g++ $(Flags) -c $(srcDir)files.cpp -o $(srcDir)/files.o

run: output
	./gltest
