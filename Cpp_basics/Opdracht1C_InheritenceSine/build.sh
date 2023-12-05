g++ -c src/main.cpp -o build/main.o
g++ -c src/square.cpp -o build/sine.o
g++ -c src/sine.cpp -o build/sine.o
g++ -c src/oscillator.cpp -o build/oscillator.o


g++ build/main.o build/oscillator.o build/sine.o build/square.o -o target/buildexe
