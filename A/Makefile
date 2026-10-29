CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = cipher

SRCS = main.cpp modeAlphaCipher.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = modeAlphaCipher.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

modeAlphaCipher.o: modeAlphaCipher.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)S

.PHONY: all clean run
