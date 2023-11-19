#Importing the simpleaudio library for use, and saving it as "SA" to refer to it
import simpleaudio as SA


#function takes name of file and amount of playback times
def playAudio(name, amount):
    #create a variable storing the wave object
    audio_object = SA.WaveObject.from_wave_file(name)
    print('Playing ' + whichAudio + ' ' + str(howManyTimes) + ' times..')

    #create a variable that stores a playing version of the audio file
    for i in range(amount):
        play_object = audio_object.play()
        play_object.wait_done()
        print('Audio File played ' + str(i+1) + ' time(s)!')
    print('Played everything!')


#--USER INTERFACE STARTS HERE--

#input an audiofile and add .wav on it
whichAudio = input('Which file would you like to hear?')
whichAudio = whichAudio + '.wav'
tempvar_1 = input('How many times should I play this audio?')
howManyTimes = int(tempvar_1)


#Start the magic. Play the inputted audio and perform it the requested amount of times.
playAudio(whichAudio, howManyTimes)







