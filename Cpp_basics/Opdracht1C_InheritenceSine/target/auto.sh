#!/bin/bash
cd ..
./build.sh
cd target/
./buildexe
python3 graph.py
