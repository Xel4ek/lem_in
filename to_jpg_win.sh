for file in `find ./ -type f -name "*.gv"`
do
  "d:Program Files (x86)\Graphviz2.38\bin\dot.exe" -Tpng $file -o ${file%".gv"}.jpg
#  neato -Tpng $file -o ${file%".gv"}_neato.jpg
done