#!/usr/bin/bash

tree -fioQ .tree.txt
tree -fidoQ .dirTree.txt

#cleans up tree to make usable
~/Master/tools/treeFileClean .tree.txt > .tree_CLEAN.txt
~/Master/tools/treeFileClean .dirTree.txt > .dirTree_CLEAN.txt
~/Master/tools/removeUnwantedDirs > .tree_FINAL.txt

#to know where we are at
currentDir=`pwd`

mkdir $currentDir"ENCODED"
cat .dirTree_CLEAN.txt | while read folderName
do
	newDir=$currentDir"ENCODED"
	newDir+=$folderName
	mkdir $newDir
done

cat .tree_FINAL.txt | while read fileName
do
	#stores the file that it is currently working on
	currentFile=$currentDir
	currentFile+=$fileName

	touch $currentDir"ENCODED"$fileName".encode"

	#reads the current file line by line
	cat -T $currentFile | while read fileLine
	do
		echo -n "$fileLine" > .fileLineSwap.txt
		~/Master/zzold/copy .fileLineSwap.txt >> $currentDir"ENCODED"$fileName".encode"

	done
	echo $currentDir"ENCODED"$fileName".encode"

done


#clean up
#rm .tree.txt
#rm .dirTree.txt
#rm .tree_CLEAN.txt
#rm .dirTree_CLEAN.txt
#rm .tree_FINAL.txt
#rm .fileLineSwap.txt
