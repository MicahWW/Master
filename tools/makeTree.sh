#!/usr/bin/bash

tree -fioQ .tree.txt
tree -fidoQ .dirTree.txt

#cleans up tree to make usable
~/Master/tools/treeFileClean .tree.txt > .tree_CLEAN.txt
~/Master/tools/treeFileClean .dirTree.txt > .dirTree_CLEAN.txt
~/Master/tools/removeUnwantedDirs > .tree_FINAL.txt
