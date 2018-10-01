import sys
import string
from time import sleep
import datetime
import os
import random
import dircache
import subprocess

####################################################################################################
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

####################################################################################################
upTime = str(upTime)
upTimeReversed = upTime[::-1]

minutes = upTimeReversed[1]
minutes += upTimeReversed[0]
minutes = int(minutes)

try:
	hours = upTimeReversed[3]
	hours += upTimeReversed[2]
except:
	hours = upTimeReversed[2]
hours = int(hours)

upTime = datetime.time(hours, minutes)
currentDT = datetime.datetime.now()
currentTime = datetime.time(currentDT.hour, currentDT.minute, currentDT.second)

####################################################################################################
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

####################################################################################################
## it starts out in AlarmSounds and at random picks a folder, that folder is usually an artist name
## it then picks another random folder from within the artist folder, that folder is usually an album name
## lastly it randomly picks a file a random inside the album folder
dir = 'alarmSounds/'
artist = random.choice(dircache.listdir(dir))
# updates dir path to the artist
dir = os.path.join(dir, artist)
album = random.choice(dircache.listdir(dir))
# updates dir path to the album
dir = os.path.join(dir, album)
# picks a song
song = random.choice(dircache.listdir(dir))
song = os.path.join(dir, song)

####################################################################################################
print upTime
print currentTime
print delta
print deltaSeconds

sleep(deltaSeconds)
print "Wake up"

try:
	subprocess.call(["play", song])
except:
	exit()
