cd ~/Master/alarm

song=$(python playRandom.py)

echo $song
play $song
