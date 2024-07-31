# Author: Jack Robbins
# Simple runner script for this C++ project

#!/bin/bash

if [[ ! -d out ]]; then
	mkdir out
fi

#Clean out the compiled directory
rm -r out/*

g++ -Wall -Wextra ./src/Jack_Robbins_jmr226_3.cpp -o ./out/Jack_Robbins_jmr226_3

./out/Jack_Robbins_jmr226_3
