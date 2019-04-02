days=$(ls -l | wc -l)
days=$(($days-1))

#will need to remove Documents later one
~/Documents/Master/calendar/display/month $days
