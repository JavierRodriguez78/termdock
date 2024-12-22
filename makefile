CCXX = g++
CXXFLAGS = -std=gnu++17 -lncurses -lpanel

SRCS = main.cpp graphical/src/panel.cpp graphical/src/terminal.cpp graphical/src/window.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = graphical/include/panel.hpp graphical/include/terminal.hpp graphical/include/window.hpp

MAIN = termdock

all: $(MAIN)
	@echo "Compiling project..."

$(MAIN): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(MAIN)



clean:
	rm -f $(OBJS) $(MAIN)
	rm -f termdock