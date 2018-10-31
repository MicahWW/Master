#!/usr/bin/bash

bash ~/Master/tools/makeTree.sh

#removes the ENCODED at the end of the dir
currentDir=`pwd`
decryptDir=${currentDir::-7}

mkdir $decryptDir
cat .dirTree_CLEAN.txt | while read folderName
do
	newDir=$decryptDir
	newDir+=$folderName
	mkdir $newDir
done

cat .tree_FINAL.txt | while read fileName
do
	currentFile=$decryptDir
	currentFile+=$fileName
	decryptFile=${currentFile::-7}

	touch $currentFile

	cat  $currentFile | while read fileLine
	do
		echo -n "$fileLine" > .fileLineSwap.txt
		~/Master/zzold/copy .fileLineSwap.txt >> $decryptFile
		~/Master/tools/toTab $decryptFile > $decryptFile
	done
done


#clean up
rm .tree.txt
rm .dirTree.txt
rm .tree_CLEAN.txt
rm .dirTree_CLEAN.txt
rm .tree_FINAL.txt
rm .fileLineSwap.txt
