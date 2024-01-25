PROG = main.exe 
SRC = main.cpp account.cpp my_program.cpp password_cracker.cpp
CFLAGS = -g -std=c++20 -Wall -Werror
LIBS = -lssl -lcrypto
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean