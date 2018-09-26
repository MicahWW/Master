echo " "
echo "Time must be in Military time"
read -p "What time do you want to wake up? " wakeUp

echo "python alarmSounds/playRandom.py" | at $wakeUp
