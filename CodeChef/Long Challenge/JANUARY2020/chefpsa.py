t=int(input())
for i in range(t):
	n=int(input())
	len=2*n
	s=input()
	s=s.split()
	li=[int(x) for x in s]
	se=set(li)
	count=0
	if n==1:
		if li[0]==li[1]:
			print('1')
		else:
			print('0')
	else:			
		for x in se:
			if x>=n:
				count=count+1
		print(count)
