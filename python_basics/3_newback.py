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
while (newNoteDuration != 0):
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

#DEBUG
print("Note durations: " + str(noteDurations))
print("Timestamps: " + str(durations_to_timestaps(noteDurations)))
#------

timeStamps = durations_to_timestaps(noteDurations)
tZero = TIME.time()

while True:
    tPassed = TIME.time() - tZero
    if(timeStamps):
        if(tPassed > timeStamps[0]):
            print(str(timeStamps[0]) + " is bigger than " + str(tPassed))
            woodSound.play()
            timeStamps.pop(0)
            print(timeStamps)
    else:
        print("Done!")
        break

    TIME.sleep(0.001)