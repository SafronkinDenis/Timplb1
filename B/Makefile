CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = beta_cipher

SRCS = main.cpp modeBetaCipher.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = modeBetaCipher.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

modeBetaCipher.o: modeBetaCipher.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
