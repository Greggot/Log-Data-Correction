CC = g++
CFLAGS = -c -Wall
SOURCES_MAIN = main.cpp dumpCorrection.cpp 
SOURCES_SUB = dumpCorrection.cpp mainTxtToBin.cpp
OBJECTS_MAIN = $(SOURCES_MAIN:.cpp=.o)
OBJECTS_SUB = $(SOURCES_SUB:.cpp=.o)
PROGRAM = main
SUBPROGRAM = txttobin

all: $(SOURCES_MAIN) $(SOURCES_SUB) $(PROGRAM) $(SUBROGRAM)
	
$(PROGRAM): $(OBJECTS_MAIN) 
	$(CC) $(OBJECTS_MAIN) -o $@

$(SUBPROGRAM): $(OBJECTS_SUB) 
	$(CC) $(OBJECTS_SUB) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@