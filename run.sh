#!/bin/bash
make clean 
make grammar 
make 
for file in "$@"
	do
		./parser < $file 
	done