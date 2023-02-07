from datetime import datetime
import pywhatkit

now = datetime.now()

current_time = now.strftime("%H:%M:%S")
print("Current Time =", current_time)

pywhatkit.sendwhatmsg("+916297540992", "Shaid:)", 9, 34)