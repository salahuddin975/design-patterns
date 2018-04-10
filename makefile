SHELL = /bin/sh
CC=g++

CFLAGS= -g -Wall -std=c++11 

BEHAVIORAL_PATTERN = DesignPattern/behavioral_pattern/
STRUCTURAL_PATTERN = DesignPattern/structural_pattern/
CREATIONAL_PATTERN = DesignPattern/creational_pattern/
	
ALL_FILES = DesignPattern/Main.cpp $(STRUCTURAL_PATTERN)adapter_pattern.cpp $(BEHAVIORAL_PATTERN)command_pattern.cpp $(CREATIONAL_PATTERN)factory_pattern.cpp \
	$(CREATIONAL_PATTERN)singleton.cpp

design_pattern.out: $(ALL_FILES)
	$(CC) $(CFLAGS) -o design_pattern.out $(ALL_FILES)

clean:
	rm design_pattern.out

