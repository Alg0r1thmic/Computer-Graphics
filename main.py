import numpy as np
from PIL import Image

array = np.zeros([100, 200, 3], dtype=np.uint8)
array[:,:100] = [255, 128, 0] #Orange left side
array[:,100:] = [0, 0, 255]   #Blue right side

#print(array)
img = Image.fromarray(array)
img.save('testrgb.png')

class list:
    def __init__(self,list):
        self.list=list

l=list("asd")
print(l.list)