CXX=g++

all: stream setcount

debug: CXX += -DDEBUG -g
debug: CC += -DDEBUG -g
debug: stream setcount

stream : stream.o  siphash24.o hash.o
	$(CXX) stream.o siphash24.o hash.o -o stream

setcount : setcount.o
	$(CXX) setcount.o -o setcount

siphash24.o : siphash24.c
	$(CXX) -c siphash24.c -o siphash24.o
stream.o: stream.cc
	$(CXX) -c stream.cc -o stream.o
hash.o: hash.cc
	$(CXX) -c hash.cc -o hash.o
setcount.o: setcount.cc
	$(CXX) -c setcount.cc -o setcount.o

clean:
	-rm -f *.o
	-rm -f stream