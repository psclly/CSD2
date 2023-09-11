#Simpleaudio for audio playback, time for sleeping
import simpleaudio as SA
import time as TIME


def enterRhythm(amount):
    #create a list and append note lengths from input
    beats = []
    for i in range(amount):
        tempvar_2 = input('Enter the length of note ' + str(i+1) + ': ')
        print(float(tempvar_2))
        beats.append(float(tempvar_2))


    #input a bpm, then convert it to sleeptime per beat
    bpm = int(input('Enter a BPM:'))
    print(' ' + str(bpm))  
    sleepTime = 60 / bpm

    #play every beat in list and sleep accordingly based on length of beat
    for i in range(amount):
        print('Hit!')
        play = wood_audioobject.play()
        TIME.sleep(beats[i]*sleepTime)
        play.stop() #stop in case the audiofile is longer than the beat

#--USER INTERFACE STARTS HERE--

wood_audioobject = SA.WaveObject.from_wave_file('wood.wav')
tempvar_1 = input('How many notes would you like to input?\n')
numPlayBackTimes = int(tempvar_1) #convert to int
enterRhythm(numPlayBackTimes)







