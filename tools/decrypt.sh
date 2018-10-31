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
	currentFile=$currentDir
	currentFile+=$fileName

	decryptFile=$decryptDir
	decryptFile+=$fileName
	decryptFile=${decryptFile::-7}

#	echo $decryptFile".test"
	touch $decryptFile".test"

	cat  $currentFile | while read fileLine
	do
		echo -n "$fileLine" > .fileLineSwap.txt
		~/Master/zzold/copy .fileLineSwap.txt >> $decryptFile".test"
		~/Master/tools/toTab $decryptFile > $decryptFile".test"
	done
done


#clean up
rm .tree.txt
rm .dirTree.txt
rm .tree_CLEAN.txt
rm .dirTree_CLEAN.txt
rm .tree_FINAL.txt
rm .fileLineSwap.txt
