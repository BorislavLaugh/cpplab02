CXX           = g++
CXXFLAGS      = -pipe -O2 -std=gnu++11 -w -fPIC
INCPATH       = -I. -I.. 

LINK          = g++
LFLAGS        = -Wl

DEL_FILE      = rm -f

####### Files

OBJECTS       = Worker.o CommandLine.o Database.o

TARGET        = libworker.so

first: all

libworker.so:  $(OBJECTS)
	$(LINK) $(LFLAGS) -shared -o $(TARGET) $(OBJECTS)
	rm *.o

all: libworker.so

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core
	-$(DEL_FILE) $(TARGET)

####### Compile

CommandLine.o: CommandLine.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CommandLine.o CommandLine.cpp

Worker.o: ./Worker.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Worker.o Worker.cpp

Database.o: ./Database.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Database.o Database.cpp
