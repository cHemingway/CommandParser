CC=clang
CCFLAGS= -g -Wall
RAGELFLAGS=
IMGTYPE=png
DOTFLAGS=

all: test_parse_assignment parse_assignment.o parse_assignment.$(IMGTYPE)

test_parse_assignment: parse_assignment.o
	$(CC) $(CCFLAGS) test_parse_assignment.c parse_assignment.o -o test_parse_assignment

parse_assignment.o: parse_assignment.c parse_assignment.h
	$(CC) $(CCFLAGS) -c parse_assignment.c -o parse_assignment.o

parse_assignment.c: parse_assignment.rl
	ragel $(RAGELFLAGS) -C parse_assignment.rl

parse_assignment.$(IMGTYPE): parse_assignment.rl
	ragel -V -p parse_assignment.rl | dot $(DOTFLAGS) -T$(IMGTYPE) -o parse_assignment.$(IMGTYPE)

clean:
	rm parse_assignment.c parse_assignment.png parse_assignment.o