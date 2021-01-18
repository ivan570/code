import requests
from io import BytesIO
from PIL import Image

r = requests.get("https://image.freepik.com/free-vector/triangular-dark-polygonal-background_23-2148261453.jpg")

image = Image.open(BytesIO(r.content))

path = './demo.' + image.format

try:
    image.save(path, image.format)

except:
    print("not working")
