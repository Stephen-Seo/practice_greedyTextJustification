COMMON_FLAGS = -Wall -Wextra -Wpedantic
ifdef DEBUG
	CXXFLAGS = $(COMMON_FLAGS) -O0 -g
else
	CXXFLAGS = $(COMMON_FLAGS) -O3 -DNDEBUG
endif

OBJECTS = \
		src/main.o \
		src/helpers.o

all: GreedyTextJustification

GreedyTextJustification: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o GreedyTextJustification $^

.PHONY:

clean:
	rm -f GreedyTextJustification
	rm -f src/*.o
