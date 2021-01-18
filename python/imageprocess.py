import requests
from io import BytesIO
from PIL import Image

r = requests.get("https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.freepik.com%2Ffree-photos-vectors%2Fwallpaper&psig=AOvVaw2NKLhcC_UdTpRgOpOWGtvA&ust=1591868231160000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCMC69rX59ukCFQAAAAAdAAAAABAD")

image = Image.open(BytesIO(r.content))

path = './demo.' + image.format

try:
    image.save(path, image.format)

except:
    print("not working")
