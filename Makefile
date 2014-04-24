CC=g++
SRC=chromosome.cpp gene.cpp population.cpp main.cpp interface.cpp
OBJ=$(SRC:.cpp=.o)
CPPFLAGS=-Wall -Wextra -std=c++0x -O3
LDFLAGS=-lcng -lglut -lGLU -lGL -lX11 -lm
EXE=projet
LIB=.
INC=.
all: CPPFLAGS += -DNDEBUG
all: projet

debug: CPPFLAGS += -pg -g
debug: mrproper projet

demo: projet
	./projet

projet: $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(EXE) -L $(LIB) $(LDFLAGS)

.cpp.o:
	$(CC) -o $@ -c $< $(CPPFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXE) gmon.out
