#!/bin/bash
cd src/
make clean
make
./buildexe
python3 graph.py
cd ..