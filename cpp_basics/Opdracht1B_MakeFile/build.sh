g++ -c src/main.cpp -o build/main.o
g++ -c src/classes.cpp -o build/classes.o

g++ build/main.o build/classes.o -o target/buildexe