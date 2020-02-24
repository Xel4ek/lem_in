#!/bin/zsh
for file in `find /home/xel/projects/lem_in/checker/lemin-tools/maps/ -type f -name "map*"`
do
  printf "---------------%s---------------\n" ${file}
  ./cmake-build-release/lem_in < ${file} | grep "steps\|number of lines\|total\|calc\|Error"
#  neato -Tpng $file -o ${file%".gv"}_neato.jpg
done