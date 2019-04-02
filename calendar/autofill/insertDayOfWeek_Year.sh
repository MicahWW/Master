echo "Which year needs the days filled in? "
read year

previousYear=$((year-1))

cd years/$previousYear/12december/

previousDay=$(head -n 1 31.day)

cd ../../$year/01january
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../02february
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../03march
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../04april
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../05may
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../06june
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../07july
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../08august
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../09september
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../10october
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../11november
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay

cd ../12december
bash ~/Master/calendar/autofill/zzindependantEXE/fillInDayOfWeek_Month.sh $previousDay
