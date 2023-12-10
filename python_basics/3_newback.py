import time as TIME
import simpleaudio as AUDIO

#List of allowed inputs
possibleNoteDurations = [0.25, 0.5, 1]

newNoteDuration = 1
noteDurations = []

woodSound = AUDIO.WaveObject.from_wave_file("wood.wav")

#Convert durations to timestamps in a sequence
def durations_to_timestaps(array):
    timeIndex = 0
    timeStamps = []
    for duration in noteDurations:
        timeStamps.append(duration + timeIndex)
        timeIndex += duration
    return timeStamps

#Take note durations from input, and handle any bad inputs
#Put all inputs in an array.
print("-----------------------------------\nSyntax: 0.25 for 16th, 0.5 for 8th, 1 for 4th \n-----------------------------------")
while(newNoteDuration != 0):
    try:
        newNoteDuration = float(input("Enter a note duration (input 0 to finish)"))
    except:
        print("Wildly invalid input detected, you know what numbers are right?")

    if(newNoteDuration == 0):
        break

    if newNoteDuration in possibleNoteDurations:
        noteDurations.append(newNoteDuration)

    else:
        print("That's not a valid note duration, refer to the syntax")

#Asking for BPM and making sure the user doesnt throw in any shenanigans
correctlyNotated = False
while(correctlyNotated == False):
    try:
        speedBPM = int(input("Enter a BPM: "))
    except:
        print("Wildly invalid input detected, BPM is a positive integer that isn't 0, yes?")
    if(speedBPM > 0):
        correctlyNotated = True

#Put the note durations into "oldstamps", then convert it according to the BPM into the new finished timeStamps list
timeStamps = []
speedQuotient = speedBPM / 120

oldStamps = durations_to_timestaps(noteDurations)
for time in oldStamps:
    timeStamps.append(time / speedQuotient)


#Start time, everytime the difference between the starting time and current time passes a timestamp...
#... play the sample and remove the timestamp from the list to wait for the next one
tZero = TIME.time()
while True:
    tPassed = TIME.time() - tZero
    if(timeStamps):
        if(tPassed > timeStamps[0]):
            print(str(timeStamps[0]) + " is bigger than " + str(tPassed))
            woodSound.play()
            timeStamps.pop(0)
    else:
        print("Done!")
        break

    TIME.sleep(0.001)