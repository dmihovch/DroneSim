SRC = src/main.cpp src/drone.cpp
FLAGS = -lraylib -lm -ldl -pthread 

all: $(SRC)
	g++ -o dronesim -Wall -Wextra $(SRC) $(FLAGS) 

clean: dronesim
	rm dronesim

run: dronesim
	./dronesim
