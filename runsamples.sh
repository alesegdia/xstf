#!/bin/bash

function build_and_run_sample {
	g++ --std=c++11 $1.cpp -o $1.bin && ./$1.bin
}

SAMPLE_FOLDER="sample/"
if [ -d "$SAMPLE_FOLDER" ]; then
	for filename in sample/*.cpp; do
		filename_noext=${filename%.*}
		build_and_run_sample ${filename_noext}
	done
else
	echo "Failed to start runnning tests"
fi