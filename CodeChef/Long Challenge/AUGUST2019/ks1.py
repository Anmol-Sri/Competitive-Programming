def func(arr):
    pxor_to_ending = {0: [0]}
    pxor = 0
    for j in range(0,len(arr)):
        x=arr[j]
        pxor ^= x
        #print("prefix xor : ",pxor)
        #print("Prefix xor to ending: ",pxor_to_ending)
        ending = pxor_to_ending.setdefault(pxor, [])
        #print("ending ",ending)
        for i in ending:
            #print("inner for : ",i,j+1)
            yield (j-i)
        ending.append(j+1)
    #print("outer for",ending)
    #print("outer for : ",pxor_to_ending)

t=int(input())
while t>0:
    n=int(input())
    a=list(map(int,input().strip().split()))[:n]
    count=0
    for value in func(a):
        count=count+value
    print(count)    
    t=t-1
