GPP = g++
OFLAGS = -o
CFLAGS = -c

alt: my_prog


autotests.o: autotests.cpp
	$(GPP) $(CFLAGS) autotests.cpp


CIntN.o: CIntN.cpp
	$(GPP) $(CFLAGS) CIntN.cpp


main.o: main.cpp
	$(GPP) $(CFLAGS) main.cpp

my_prog: main.o CIntN.o autotests.o
	$(GPP) main.o CIntN.o autotests.o $(OFLAGS) my_prog

clean:
	rm -rf *.o my_prog
