import numpy as np
from PIL import Image
import math

#print(arr.shape)
class MathUtil:
    def __init__(self):
        pass
    def sqr(self,x):
        return x*x
class ImageUtils:
    def __init__(self,imagePath):
        self.img=Image.open(imagePath).convert('RGB')
    def getRGBArray(self): 
        arr = np.array(self.img) # 640x480x4 array
        return arr
    def getWidth(self):
        return self.img.width
    def getHeight(self):
        return self.img.height
class ImageMeasure:
    def __init__(self):
        self.mathUtil=MathUtil()
    def approximate(self,data,x,y,width,height):
        redSum = 0
        greenSum = 0
        blueSum = 0
        i=x
        j=y
        while i<x+width:
            while j<y+height:
                redSum += (data[i][j])[0]#red
                greenSum +=(data[i][j])[1]#green
                blueSum +=(data[i][j])[2]#blue
                j+=1
            i+=1
        pixelCount =width * height
        return  [int(redSum / pixelCount),int(greenSum / pixelCount),int(blueSum / pixelCount)]			
    def measureDetail(self,data,x,y,width,height):
        redSum = 0
        greenSum = 0
        blueSum = 0
        i=x
        j=y
        while i<x+width:
            while j<y+height:
                redSum += int((data[i][j])[0])#red
                greenSum +=int((data[i][j])[1])#green
                blueSum +=int((data[i][j])[2])#blue
                j+=1
            i+=1
        pixelCount = width * height        
        redAvg = redSum / pixelCount
        greenAvg = greenSum / pixelCount
        blueAvg = blueSum / pixelCount        
        redSum = 0
        greenSum = 0
        blueSum = 0
        i=x
        j=y         
        while i<x+width:
            while j<y+height:
                red = int((data[i][j])[0])#red
                green = int((data[i][j])[1])#green
                blue = int((data[i][j])[2])#blue
                redSum +=int(self.mathUtil.sqr(red - redAvg))
                greenSum +=int(self.mathUtil.sqr(green - greenAvg))
                blueSum +=int(self.mathUtil.sqr(blue - blueAvg))					
                j+=1
            i+=1
        return redSum / (pixelCount *255*255) + greenSum / (pixelCount*255*255) + blueSum / (pixelCount*255*255)
class QuadTree:
    def __init__(self,data,measure,threshold,defaultValue):
        self.data=data
        self.measure=measure
        self.threshold=threshold
        self.defaultValue=defaultValue
        self.root=Node(data,0,0,data.shape[0],data.shape[1],defaultValue,threshold)
    def get(self,i,j):
        return self.root.get(i,j)    
class Node:
    measure=ImageMeasure() 
    value=[0]*3
    def __init__(self,data,x,y,width,height,defaultValue,threshold):
        self.data=data
        self.x=int(x)
        self.y=int(y)
        self.width=int(width)
        self.height=int(height)
        self.defaultValue=defaultValue
        #print(x,y,width,height)
        if ((self.width == 1) or (self.height == 1) or (self.measure.measureDetail(data, self.x, self.y, self.width,self.height) <= threshold)):	
            self.value = self.measure.approximate(data,self.x,self.y, self.width, self.height)
            #print("value is->",self.value)
            print("measure",self.measure.measureDetail(data, self.x, self.y, self.width,self.height) )
            #print("threshold",threshold)
        else:
            self.children=[None]*4		
            self.children[0] = Node(data,self.x,self.y,int(self.width/2),int(self.height/2),defaultValue,threshold)
            self.children[1] = Node(data,self.x + int(self.width/2),self.y,self.width-int(self.width/2),int(self.height/2),defaultValue,threshold)
            self.children[2] = Node(data,self.x,self.y +int(self.height/2),int(self.width/2),self.height -int(self.height/2),defaultValue,threshold)
            self.children[3] = Node(data,self.x +int(self.width/2),self.y +int(self.height/2),self.width -int(self.width/2), self.height-int(self.height/2),defaultValue,threshold)
    def get(self,i,j):
        if self.value ==[0]*3:
            if i < self.x + int(self.width/ 2):
                if j < self.y + int(self.height/2):
                    return (self.children[0]).get(i,j)					
                else:
                    return (self.children[2]).get(i, j)			
            else:
                if(j < self.y + int(self.height/2)):
                    return (self.children[1]).get(i, j)					
                else:
                    return (self.children[3]).get(i, j)
        else:			
            if ((i == self.x) or (j == self.y)) and (self.defaultValue != [0]*len(self.defaultValue)):
                return self.defaultValue				
            else:
                return self.value

class ImageCompresor:
    def __init__(self,imagePath=None):
        self.imagePath=imagePath
    def normalQuadtreeCompress(self,imageP):
        img=ImageUtils(imageP)
        arr=img.getRGBArray()
        width=img.getWidth()
        height=img.getHeight()
        measure=ImageMeasure()
       
       #print(qt)
        #for k in range(20):
        qt=QuadTree(arr,measure,1/300,[0]*3)
        out=np.zeros(shape=(img.getWidth(),img.getHeight(),3))
        print(out.shape)
        for i in range(width):
            for j in range(height):
                #print("after value-->",qt.get(i,j))
                out[i][j]=qt.get(i,j)
          #  outImage=[]
        #im = Image.fromarray(np.uint8(cm.gist_earth(out)*255))
        img = Image.fromarray((out * 255).astype(np.uint8))
        #img = Image.fromarray(out)
        img.save('Paisaje.png')

def main():
    img=ImageCompresor()
    img.normalQuadtreeCompress('paisaje.png')

if __name__=="__main__":
    main()
    #proofs()
