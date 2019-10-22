#input should be given as yyyy mm dd

months=("01january"
	"02february"
	"03march"
	"04april"
	"05may"
	"06june"
	"07july"
	"08august"
	"09september"
	"10october"
	"11november"
	"12december")


year=$1
month=${months[$2-1]}
day=$3.day

cd years/$year/$month/

echo `cat $day`
