SHELL = /bin/sh
CC=g++

CFLAGS= -g -Wall -std=c++11 

BEHAVIORAL_PATTERN = DesignPattern/behavioral_pattern/
STRUCTURAL_PATTERN = DesignPattern/structural_pattern/
CREATIONAL_PATTERN = DesignPattern/creational_pattern/
	
ALL_FILES = DesignPattern/main.cpp $(CREATIONAL_PATTERN)factory_pattern.cpp $(CREATIONAL_PATTERN)singleton.cpp \
	$(CREATIONAL_PATTERN)prototype_pattern.cpp $(STRUCTURAL_PATTERN)adapter_pattern.cpp $(BEHAVIORAL_PATTERN)command_pattern.cpp 

design_pattern.exe: $(ALL_FILES)
	$(CC) $(CFLAGS) -o design_pattern.exe $(ALL_FILES)

clean:
	rm design_pattern.exe

