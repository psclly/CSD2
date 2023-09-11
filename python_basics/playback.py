#Importing the simpleaudio library for use, and saving it as "SA" to refer to it
import simpleaudio as SA
import time as TIME

#Define a function that takes a filename and amount to play the sound.
    #Create a wave object (from SA library) with the file inside
    #Let the user know whats about to happen
def playAudio(name, amount):
    audio_object = SA.WaveObject.from_wave_file(name)
    print('Playing ' + whichAudio + ' ' + str(numPlayBackTimes) + ' times..')

    #For loop with a "range" function. Range returns a number in sequence incrementing by 1 each time. As an argument it takes an integer.
        #Create an object that will be responsible for playing sound files.
        #play_object as a variable will automatically become an object that plays a sound due to the .play method from SA.
        #Start waiting for the play_object object to finish before continuing
        #After each file, give a print. Add 1 to the index to make sure it doesn't return 0-howManyTimes but 1-howManyTimes
    for i in range(amount):
        play_object = audio_object.play()
        play_object.wait_done()
        print('Audio File played ' + str(i+1) + ' time(s)!')
    print('Played everything!')

def enterRhythm(amount):
    wood_audioobject = SA.WaveObject.from_wave_file('wood.wav')
    beats = []
    for i in range(amount):
        beats[i] = input('Enter the length of note ' + i + 1 + ': ')
        print(beats[i])



        
    bpm = input('Enter a BPM: ')
    bps = bpm / 60
    input('Are you ready??')
    TIME.sleep(1)
    for i in range(amount):
        wood_audioobject.play
        TIME.sleep(beats[i]*bps)

    



#--USER INTERFACE STARTS HERE--

tempvar_1 = input('How many notes would you like to input?')
numPlayBackTimes = int(tempvar_1)

#Start the magic. Play the inputted audio and perform it the requested amount of times.
enterRhythm(numPlayBackTimes)







