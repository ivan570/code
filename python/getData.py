import requests

r = requests.get("https://www.google.com")
print(r.status_code)

print(r.url)
htmlfile = open("html_requestUrl.html", "w+")
htmlfile.write(r.text)
htmlfile.close()

print(r.content)