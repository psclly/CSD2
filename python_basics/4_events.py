import time as t
import simpleaudio as sa

events = []
def newEvent(_time, _type, _velocity, _duration):
    events.append(dict(time = _time, type = _type, velocity = _velocity, duration = _duration, played = False))

newEvent(4, "dacapo", 0, 0)

newEvent(0, "kick", 100, 100)
newEvent(1, "snare", 100,100)
newEvent(2, "kick", 100, 100)
newEvent(3, "snare", 100, 100)
newEvent(0, "crash", 100, 100)

newEvent(0.5, "kick", 70, 100)
newEvent(1.25, "kick", 80, 100)
newEvent(3.5, "snare", 90, 100)
newEvent(2.75, "kick", 60, 100)

newEvent(3.75, "snare", 100, 100)



kick_sample = sa.WaveObject.from_wave_file("kick.wav")
snare_sample = sa.WaveObject.from_wave_file("snare.wav")
crash_sample = sa.WaveObject.from_wave_file("crash.wav")

t0 = t.time()

while True:
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

            if event["type"] != "dacapo":
                event["played"] = True #once an event has played, put them on "played"