def calc_prefix(s1,s2):
	l1=len(s1)
	l2=len(s2)
	small=''
	large=''
	if l1<l2:
		small=s1
		large=s2
	else:
		small=s2
		large=s1
	for i in range(len(small)):
		if small[i] != large[i]:
			return i
	return len(small)

def calc_suffix(s1,s2):
	l1=len(s1)
	l2=len(s2)
	small=''
	large=''
	if l1<l2:
		small=s1
		large=s2
	else:
		small=s2
		large=s1
	len1=len(small)-1
	len2=len(large)-1
	count=0
	while(len1>=0 and len2>=0):
		if small[len1]!=large[len2]:
			return count
		else:
			count=count+1
			len1=len1-1
			len2=len2-1	
	return len(small)

def calc(l):
	ans=0
	if len(l)==0:
		return 0
	elif len(l)==1:
		return 0
	elif len(l)==2:
		p1=min(calc_prefix(l[0],l[1]),calc_suffix(l[0],l[1]))
		ans=ans+p1**2
		return ans
	else:	
		while(len(l)>2):
			p1=min(calc_prefix(l[0],l[1]),calc_suffix(l[0],l[1]))
			p2=min(calc_prefix(l[1],l[2]),calc_suffix(l[1],l[2]))
			if p1>=p2:
				ans=ans+p1**2
				del l[0]
				del l[0]
			else:
				ans=ans+p2**2
				del l[1]
				del l[1]
		if len(l)==2:
			p1=min(calc_prefix(l[0],l[1]),calc_suffix(l[0],l[1]))
			ans=ans+p1**2
	return ans	


t=int(input())
for i in range(t):
	n=int(input())
	l=[]
	for q in range(n):
		x=input()
		l.append(x)
	ps=[[0 for y in range(n)] for x in range(n)]	
	for q in range(n):
		for w in range(n):
			ps[q][w]=min(calc_prefix(l[q],l[w]),calc_suffix(l[q],l[w]))

	for q in range(n):
		for w in range(n):
			print(ps[q][w],end=' ')
		print()			


'''
Test case:
4
6
abcdefghijkl
chef
world
code
abcxyzhijkl
word
4
problem
poem
problem
problem
3
contest
coolest
unused
5
abcdef
abcdeg
b
bab
aberef
'''