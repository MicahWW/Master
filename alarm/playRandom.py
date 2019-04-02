import sys
import subprocess
import random
import dircache
import os

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


print song

#subprocess.call(["play", song])
