import requests
from colorama import Fore
r = requests.get("https://mail.google.com/mail")
print(r.status_code)

print(r.url)
htmlfile = open("html_requestUrl.html", "w+")
htmlfile.write(r.text)
htmlfile.close()

print(Fore.RED , r.content)