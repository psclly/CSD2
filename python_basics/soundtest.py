import simpleaudio as SA
import time as TIME
wood_audio = SA.WaveObject.from_wav_file('wood.wav')
play = wood_audio.play()
TIME.sleep(2)
play.stop()
