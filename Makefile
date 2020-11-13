CXXFLAGS=-Wall --std=c++17 -O2 -I ./include
HEADERS=./include/Player.h \
./include/Pair.h \
./include/Points.h \
./include/Cell.h \
./include/Reverse.h \
./include/Element.h \
./include/Teleport.h \
./include/Field.h
SOURCES=./src/Reverse.cpp \
./src/Pair.cpp \
./src/Cell.cpp \
./src/Points.cpp \
./src/Player.cpp \
./src/test.cpp \
./src/test1.cpp \
./src/Teleport.cpp \
./src/Field.cpp
LDFLAGS+=

.PHONY: all
all: $(SOURCES:.cpp=.o) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(SOURCES:.cpp=.o) a.out
