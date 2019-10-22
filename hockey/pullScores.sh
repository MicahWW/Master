#create back up of scores
echo "Creating backup of old scores"

cd .scoresBackup
#bash ~/Master/tools/makeTree.sh

#gives the count of files within the backup dir
count=`ls -1 | wc -l`

move="scores"$count".txt"
mv ../scores.txt $move

cd ..

########################################
#start process to pull new scores
cd html
bash ~/Master/tools/makeTree.sh
#becuase I didn't realize some files were wrong premissions and was trying to debug for an hour
chmod 666 *

currentDir=`pwd`
cd ..

cat $currentDir"/.tree_FINAL.txt" | while read line
do
	currentFile=$currentDir
	currentFile+=$line

	echo $currentFile
#	echo -e "\treducing"
	./zzOutFiles/HTMLreduce $currentFile > .temp0.txt
#	echo -e "\tnew lines"
	./zzOutFiles/HTMLline .temp0.txt > .temp1.txt
#	echo -e "\textracting"
	./zzOutFiles/HTMLextract .temp1.txt >> scores.txt
	echo -n $currentFile
	echo " appended to scores.txt"
done

########################################
#clean up temp files
echo "clean up"
rm .temp0.txt
rm .temp1.txt
cd html
bash ~/Master/tools/cleanTreeFiles.sh
