previousYear=$1

bash ~/Master/tools/makeTree.sh

echo `pwd`
echo $previousDay

~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Input $previousDay

bash ~/Master/tools/cleanTreeFiles.sh

