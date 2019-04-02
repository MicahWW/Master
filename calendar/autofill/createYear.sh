echo "What year to create: "
read year

mkdir $year
cd $year

bash ~/Master/calendar/autofill/zzindependantEXE/fillYear.sh
bash ~/Master/calendar/autofill/zzindependantEXE/fillMonths.sh
