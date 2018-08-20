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
	exit()

try:
        upTime = int(upTime)
except ValueError:
        print "\nInvalid number, not a number"
	exit()

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

upTime      = datetime.time(hours, minutes)
currentDT   = datetime.datetime.now()
currentTime = datetime.time(currentDT.hour, currentDT.minute, currentDT.second)

####################################################################################################
## these dates are dummy dates, they don't really matter what the day is
## they are used for if the the alarm will take place the next day or during the same day
# today = datetime.date(year = 2018, month = 01, day = 01)
# tomorrow = datetime.date(year = 2018, month = 01, day = 02)
today    = datetime.date(year = currentDT.year, month = currentDT.month, day = currentDT.day)
tomorrow = datetime.date(year = currentDT.year, month = currentDT.month, day = (currentDT.day+1))

if currentTime.hour > hours:
        currentTime = datetime.datetime.combine(today, currentTime)
        upTime = datetime.datetime.combine(tomorrow, upTime)
else:
        currentTime = datetime.datetime.combine(today, currentTime)
        upTime = datetime.datetime.combine(today, upTime)

delta = upTime - currentTime
deltaSeconds = delta.seconds

####################################################################################################
print upTime
print currentTime
print delta
print deltaSeconds

month = str(tomorrow.month)
if(len(month) != 2):
	month = "0" + month

day = str(tomorrow.day)
if(len(day) != 2):
	day = "0" + day

hours = str(hours)
if(len(hours) != 2):
	hours = "0" + hours

minutes = str(minutes)
if(len(minutes) != 2):
	minutes = "0" + minutes


wakeUpTime = month + day + hours + minutes

subprocess.call(["at", "-t", wakeUpTime, "/AlarmSounds/playRandom.py"])
