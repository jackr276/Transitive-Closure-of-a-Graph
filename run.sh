# Author: Jack Robbins
# Simple runner script for this C++ project

#!/bin/bash

if [[ ! -d out ]]; then
	mkdir out
fi

#Clean out the compiled directory
rm -r out/*

g++ -Wall -Wextra ./src/transitive_closure.cpp -o ./out/transitive_closure

./out/transitive_closure
