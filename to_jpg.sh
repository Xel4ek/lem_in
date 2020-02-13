for file in `find ./ -type f -name "*.gv"`
do
  dot -Tpng $file -o ${file%".gv"}.jpg
#  neato -Tpng $file -o ${file%".gv"}_neato.jpg
done