#!/usr/bin/bash

tree -fioQ .tree.txt
tree -fidoQ .dirTree.txt

~/Master/tools/treeFileClean .tree.txt > .tree_CLEAN.txt
~/Master/tools/treeFileClean .dirTree.txt > .dirTree_CLEAN.txt





cat .tree.txt | while read name
do
#	echo $name
	echo encoded/$name.encode
#	./copy $name > encoded/$name.encode
done



#rm .tree.txt
#rm .dirTree.txt
#rm .tree_CLEAN.txt
#rm .dirTree_CLEAN.txt
