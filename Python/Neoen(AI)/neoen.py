# /*/ Author: ShAiDSk /*/
# Here is my Personal Assistant.
import speech_recognition as sr
import datetime
import pyttsx3


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)

# print(voices[1].id)
# ----------------------------Functions--------------------------------
def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Good Morning! Shaid.")
    elif hour >= 12 and hour < 18:
        speak("Good Afernoon! Shaid.")
    else:
        speak("Good Evening! Shaid.")
    speak("I'm Neoen Shaid. I'm in your service Shaid. it's my honor to meet you Shaid.")

def takeCommand():
    # It takes microphone input from the user ans return string output
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        # r.pause_threshold = 1
        r.energy_threshold = 400
        audio = r.listen(source)
    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")
    except Exception as e:
        print (e)
        print("Say that again please...")
        return "None"
    return query

if __name__ =="__main__":
    wishMe()
    takeCommand()
    # while True:
    #     query = takeCommand().lower()
        

