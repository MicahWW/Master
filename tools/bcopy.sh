#!/usr/bin/bash

tree -fioQ .tree.txt
tree -fidoQ .dirTree.txt

#cleans up tree to make usable
~/Master/tools/treeFileClean .tree.txt > .tree_CLEAN.txt
~/Master/tools/treeFileClean .dirTree.txt > .dirTree_CLEAN.txt
~/Master/tools/removeUnwantedDirs > .tree_FINAL.txt

#to know where we are at
current=`pwd`

cat .tree_FINAL.txt | while read name
do
	echo $current"ENCODED"$name".encode"

done



rm .tree.txt
rm .dirTree.txt
rm .tree_CLEAN.txt
rm .dirTree_CLEAN.txt
rm .tree_FINAL.txt
