all: clean RunTests.exe
	

RunTests.exe: Polygone.o testPolygone.o main.o
	gcc -o SetTest Polygone.o testPolygone.o main.o

Polygone.o:
	gcc Polygone.c Predicat.c -c

testPolygone.o:
	gcc testsPolygone.c Predicat.c -c

main.o:
	gcc testsPolygone.c main.c -c  

clean:
	rm -f *.o SetTest 




