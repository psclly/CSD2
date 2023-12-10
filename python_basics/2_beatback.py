#Importing the simpleaudio library for use, and saving it as "SA" to refer to it
import simpleaudio as SA
import time as TIME

#Take the amount into a function
def enterRhythm(amount):
    #Load the wood audio
    wood_audioobject = SA.WaveObject.from_wave_file('wood.wav')
    beats = []
    for i in range(amount):
        tempvar_2 = input('Enter the length of note ' + str(i+1) + ': ')
        print(float(tempvar_2))
        beats.append(float(tempvar_2))



    bpm = int(input('Enter a BPM:'))
    print(' ' + str(bpm))  
    sleepTime = 60 / bpm

    for i in range(amount):
        print('Hit!')
        play = wood_audioobject.play()
        TIME.sleep(beats[i]*sleepTime)
        play.stop()

#--USER INTERFACE STARTS HERE--

tempvar_1 = input('How many notes would you like to input?\n')
numPlayBackTimes = int(tempvar_1)

#Start the magic. Play the inputted audio and perform it the requested amount of times.
enterRhythm(numPlayBackTimes)







