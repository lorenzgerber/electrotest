#Burleigh, Lab6, LinSomU, H16
#steves algo to identify the e12 resistors needed when the user
#supplies a resistance value
#use: python3 Lib3.py <resistance value>

import math
import sys

def Count(resis):
    #find multiplier
    resis = str(resis)
    try:
        (inter, sigfigs) = resis.split(".")
        places = (len(inter)-1)
    except:
        places = (len(resis)-1)
    #convert to 10    
    places = math.pow(10, places)
    places = int(places)
    #print('power ' + str(places))
    return places

def closest(list, number):
    #first find multiplier for e12 list
    places = Count(number)   
    #adjust e12 list by power
    list = [(item * places) for item in list]
    #print(list) 
    #stop this crazyness if resistor number is < 1
    if number < 1:
        closestNr = 0
        resid = 0
        return closestNr, resid      
    #create diffs array, find lowest and its assd index, use index to find val
    diffs = []
    for item in list:
        if item <= number:
            diffs.append(number-item)
    indx = diffs.index(min(diffs))
    closestNr = list[indx]
    #print("closest " + str(closestNr))
    #find resid
    resid = number - closestNr
    resid = round(resid,1)   
    #print('resid ' + str(resid))  
    return closestNr, resid

            
#e12 series, x10 or x100 to scale
e12 = (1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2)

#bring in origres
origres = sys.argv[1]
init = round(float(origres),1)
#print("orig " + origres)

#convert to rounded int
origres = round(float(origres), 1)
#print("rounded orig " + str(origres))

#resisarray
resisarray = []

#find closest
while len(resisarray) < 3:
    closestNr, resid = closest(e12, origres)
    resisarray.append(closestNr)
    #now use resid
    origres = resid
#print
print('\nTo achieve a resistance of ' + str(init) + ' use the following resistors: ' + "\n")
for item in resisarray:
    print(str(item))
    
#calc precent:
sum = 0
count=0
for item in resisarray:
    sum += item
    if item > 0:
        count += 1

#print
percent = (100-(sum/(init)*100))
percent=str(round(percent, 1))
print("\nWith these resistors you deviate " + percent + '% from your original value.')
print("You will use a total of " + str(count) + ' resistors.')
