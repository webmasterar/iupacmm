
CC=     g++

CFLAGS= -g -D_USE_64 -msse4.2 -O3 -fomit-frame-pointer -funroll-loops

LFLAGS= -std=c++11 -DNDEBUG -I .

EXE=    iupacmm

SRC=    main.cpp iupacmm.cpp

#
# No need to edit below this line
#

.SUFFIXES:
.SUFFIXES: .cpp .o

OBJ=    $(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $(LFLAGS) $< 

all:    $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS)

$(OBJ): $(MF) $(HD)

clean:
	rm -f $(OBJ) $(EXE) *~

clean-all:
	rm -f $(OBJ) $(EXE) *~
