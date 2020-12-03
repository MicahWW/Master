import sys
import string
from time import sleep
import datetime
import os
from playsound import playsound

upTime = sys.argv[1]
test = len(sys.argv)
if test != 2:
	print "\nNot valid arguments"

try:
	upTime = int(upTime)
except ValueError:
	print "\nInvalid number, not a number"
	sys.exit(1)

if upTime < 0:
	print "\nInvalid number, number less than 0"

upTime = str(upTime)
upTimeReversed = upTime[::-1]

minutes = upTimeReversed[1]
minutes += upTimeReversed[0]
minutes = int(minutes)

try:
	hours = upTimeReversed[3]
	hours += upTimeReversed[2]
except:
	try:
		hours = upTimeReversed[2]
	except:
		hours = 0
hours = int(hours)

upTime = datetime.time(hours, minutes)
currentDT = datetime.datetime.now()
currentTime = datetime.time(currentDT.hour, currentDT.minute, currentDT.second)

## these dates are dummy dates, they don't really matter what the day is
## they are used for if the the alarm will take place the next day or during the same day
today = datetime.date(year = 2018, month = 01, day = 01)
tomorrow = datetime.date(year = 2018, month = 01, day = 02)

if currentTime.hour > hours:
	currentTime = datetime.datetime.combine(today, currentTime)
	upTime = datetime.datetime.combine(tomorrow, upTime)
else:
	currentTime = datetime.datetime.combine(today, currentTime)
	upTime = datetime.datetime.combine(today, upTime)

delta = upTime - currentTime
deltaSeconds = delta.seconds

print upTime
print currentTime
print delta
print deltaSeconds

sleep(deltaSeconds)
print "Wake up"

#playsound("/home/micah/Music/Dust.mp3")
playsound("/home/micah/Music/Closer.mp3")
print "Hello world"
