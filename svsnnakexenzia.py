import numpy as np
import cv2
import random
import time

def collisionwithapple(appleposition,score):
    appleposition=[random.randrange(1,50)*10,random.randrange(1,50)*10]
    score+=1
    return appleposition,score

def collisionwithboundaries(snakehead):
    if snakehead[0]>=500 or snakehead[0]<=0 or snakehead[1]>=500 or snakehead[1]<=0:
        return 1
    else:
        return 0

def collisionwithself(snakeposition):
    snakehead=snakeposition[0]
    if snakehead in snakeposition[1:]:
        return 1
    else:
        return 0

img=np.zeros((500,500,3),dtype='uint8')

#Initial snake and apple position

snakeposition=[[250,250],[240,250],[230,250]]
appleposition=[random.randrange(1,50)*10,random.randrange(1,50)*10]
score=0
prevbuttondirection=1
buttondirection=1
snakehead=[250,250]
while True:
    cv2.imshow('a',img)
    cv2.waitKey(1)
    img=np.zeros((500,500,3),dtype='uint8')

    #Display Apple
    cv2.rectangle(img,(appleposition[0],appleposition[1]),(appleposition[0]+10,appleposition[1]+10),(0,0,255),3)
    #Display Snake
    for position in snakeposition:
        cv2.rectangle(img,(position[0],position[1]),(position[0]+10,position[1]+10),(0,255,0),3)

    #Takes step after fixed time
    t_end=time.time()+0.2
    k=-1
    while time.time()<t_end:
        if k==-1:
            k=cv2.waitKey(125)
        else:
            continue

    #0-left,1-right,3-up,2-down,q-break
    #a-left,d-right,w-up,s-down

    if k==ord('a') and prevbuttondirection!=1:
        buttondirection=0
    elif k==ord('d') and prevbuttondirection!=0:
        buttondirection=1
    elif k==ord('w') and prevbuttondirection!=2:
        buttondirection=3
    elif k==ord('s') and prevbuttondirection!=3:
        buttondirection=2
    elif k==ord('q'):
        break
    else:
        buttondirection=buttondirection
        prevbuttondirection=buttondirection

    # Change the head position based on the button direction
    if buttondirection==1:
        snakehead[0]+=10
    elif buttondirection==0:
        snakehead[0]-=10
    elif buttondirection==2:
        snakehead[1]+=10
    elif buttondirection==3:
        snakehead[1]-=10

    # Increase Snake length on eating apple
    if snakehead==appleposition:
        appleposition,score=collisionwithapple(appleposition,score)
        snakeposition.insert(0,list(snakehead))
    else:
        snakeposition.insert(0,list(snakehead))
        snakeposition.pop()

    #On collision kill the snake and print the score
    if collisionwithboundaries(snakehead)==1 or collisionwithself(snakeposition)==1:
        font=cv2.FONT_HERSHEY_SIMPLEX
        img=np.zeros((500,500,3),dtype='uint8')
        cv2.putText(img,'Your Score is{}'.format(score),(140,250),font,1,(255,255,255),2)
        cv2.imshow('a',img)
        cv2.waitKey(0)
        cv2.imwrite("C:/Python27/result.jpg",img)
        break

    cv2.destroyAllWindows()
        
            
        
        
