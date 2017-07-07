CC=g++
CFLAGS= -std=c++11 -Wall -ggdb

main: main.cpp LList.h.gch HashTable.h.gch
	$(CC) $(CFLAGS) main.cpp -o main
LList.h.gch: LList.h
	$(CC) $(CFLAGS) LList.h
HashTable.h.gch: HashTable.h
	$(CC) $(CFLAGS) HashTable.h
clean:
	rm -f LList.h.gch main HashTable.h.gch
