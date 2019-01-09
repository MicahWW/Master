echo "What year to create: "
read year

mkdir $year
cd $year

bash ~/Master/calendar/autofill/fillYear.sh
bash ~/Master/calendar/autofill/fillMonths.sh
