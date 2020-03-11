#!/bin/bash
map="$1"
args="${@:1}"
if [ "$map" != "" ]; then
	./lem-in < $map 1>visual/map.out
	./visual/venv/bin/python visual/vis.py visual/map.out
fi;
