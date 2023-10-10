import time as t
import simpleaudio as sa

from midiutil import MIDIFile
from tqdm import tqdm
import os
import sys 

response = "n"

def generateMIDI(events, _bpm):
    print("Generating MIDI..")
    t.sleep(1)

    #Essentials
    track = 0
    channel = 9
    bpm = int(_bpm)
    
    #Create MIDI File
    midifile = MIDIFile(1)

    #Modify MIDI File with track name and time, then BPM at time 0
    start_time = 0
    midifile.addTrackName(track, start_time, "Saved City Beat")
    bpm_time = 0
    midifile.addTempo(track, bpm_time, bpm)

    #Standard variable to convert a default duration of notes to precise time in a midi file based on the BPM
    note_dur = 60 / bpm

    #Set the midi pitches for each sample
    midi_pitches = {
        "kick": 60,
        "snare": 61,
        "crash": 62
    }

    #Start parsing events list
    for event in events:
        if event["type"] != "end":
            #Note timestamp divided by the BPM based note_dur to denote correct timing
            note_time = event["time"] / note_dur

            #Add note to the midifile with all necessary arguments
            midifile.addNote(track, channel, midi_pitches[event["type"]], note_time, event["duration"], event["velocity"])

    filename = str(input("How would you like to name this beat? \n"))
    #Fake as hell loading bar
    for i in tqdm(range(len(events))):
        t.sleep(0.1)  # sleep one second in each iteration

    exported = False
    #Export Midi file in a way I honestly don't really get but I'm sure it works
    #Also, if the filename inserted is invalid, try to catch it
    while exported == False:
        try:
            filename+= ".midi"
            print("attempting to export to " + filename)
            #wb indicates it should be written in binary form, not a text file
            with open(filename,'wb') as outf:
                midifile.writeFile(outf)
            exported = True
        except:
            print("####Error while writing file, perhaps you named it wrong?###")
            filename = input("Input a new (valid) filename, not ending in extension")
            for i in tqdm(range(len(events))):
                t.sleep(0.05)  # sleep one second in each iteration
            
    print("Done!")
    t.sleep(1)
    print("Exported MIDI to: " + filename)
    t.sleep(1)


#MAIN FUNCTION
def main():

    #Input system to check for valid input
    validBPM = False
    while validBPM == False:
        bpm = input("Enter a BPM or write quit to exit: ")
        if bpm.lower() == "quit":
            sys.exit()
        try:
            bpm = int(bpm)
            validBPM = True
        except:
            print("Invalid BPM or input, come on, I don't have all day..")

    #Create an event array and define a function within main() for easily adding new events in favour of readability
    events = []
    def newEvent(_time, _type, _velocity, _duration):
        events.append(dict(time = _time, type = _type, velocity = _velocity, duration = _duration, played = False))

    #Define wav objects for playback
    kick_sample = sa.WaveObject.from_wave_file("kick.wav")
    snare_sample = sa.WaveObject.from_wave_file("snare.wav")
    crash_sample = sa.WaveObject.from_wave_file("crash.wav")

    
    t0 = t.time()

    newEvent(0, "kick", 100, 100)
    newEvent(2, "kick", 80, 100)
    newEvent(1, "snare", 100, 100)
    newEvent(3, "snare", 100, 100)
    for i in range(4):
        newEvent(i, "crash", 100, 100)
        newEvent(i + 0.5, "crash", 50, 100)
    newEvent(4, "end", 0, 0)

    print(events)

    whileLoop = True
    while whileLoop == True:
        tCurrent = t.time() - t0
        print(tCurrent)
        for event in events:
            if event["time"] < tCurrent and event["played"] == False:
                match event["type"]:
                    case "kick":
                        kick_play = kick_sample.play()
                    case "snare":
                        snare_play = snare_sample.play()
                    case "crash":
                        crash_play = crash_sample.play()

                    case "dacapo": #dacapo event loops back to start and rearms all play events
                        t0 = t.time()
                        for event in events:
                            event["played"] = False #rearm all events
                        break #break so it doesnt play everything else if the dacapo is at the start of the events array

                    case "end":
                        whileLoop = False

                if event["type"] != "dacapo":
                    event["played"] = True #once an event has played, put them on "played"
                    
    judgement = input("How was that? Would you like to save it? Y/N/quit \n")

    if judgement == "Y":
        generateMIDI(events, bpm)

    return judgement
#-------------End of main()


while response != "quit":
    response = main()
    print("Returning to start..")
    t.sleep(2)

print("Thanks for using City-MIDI Generator")
t.sleep(3)