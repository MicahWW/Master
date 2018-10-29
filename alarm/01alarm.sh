echo " "
echo "Time must be in Military time"
read -p "What time do you want to wake up? " wakeUp

min=$(expr $wakeUp % 100)
hour=$(expr $(expr $wakeUp - $min) / 100)

echo $hour":"$min
