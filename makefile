CC=g++
CFLAGS= -std=c++11 -Wall -ggdb


main: $(OBJS) main.cpp
	$(CC) $(CFLAGS) main.cpp -o main
LList.h.gch: LList.h
	$(CC) $(CFLAGS) -c LList.h
clean:
	rm -f LList.h.gch main
