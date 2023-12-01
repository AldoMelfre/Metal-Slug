bin/main : src/main.cpp include/*.hpp
	c++ src/main.cpp -I include -o bin/main -lcurses

run : bin/main
	./bin/main

