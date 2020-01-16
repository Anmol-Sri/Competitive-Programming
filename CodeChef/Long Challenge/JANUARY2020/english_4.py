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

def calc2(l):
	visited=[]
	n=len(l)
	for q in range(n):
		visited.append(False)
	arr=[]
	c=0
	lenarr=0
	for q in range(n-1):
		lenq=len(l[q])
		for w in range(q+1,n):
			lenw=len(l[w])
			lmin=min(lenq,lenw)
			pref=calc_prefix(l[q],l[w])
			suf=calc_suffix(l[q],l[w])
			wt=min(pref,suf)
			if(wt>0):
				lenarr=lenarr+1
				arr.append((q,w,wt*wt))
	arr.sort(key = lambda x: x[2],reverse=True)
	#print(arr)
	count=0
	sum=0
	for q in arr:
		if(count>(n//2)):
			break
		if (not(visited[q[0]] or visited[q[1]])):
			count=count+1
			sum=sum+q[2]
			visited[q[0]]=True
			visited[q[1]]=True
	return sum	

def calc_advanced(l):
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
		'''while(len(l)>2):
			p1=min(calc_prefix(l[0],l[1]),calc_suffix(l[0],l[1]))
			p2=min(calc_prefix(l[1],l[2]),calc_suffix(l[1],l[2]))
			p#rint(p1," - ",p2)
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
			ans=ans+p1**2'''
		ans=calc2(l)
		return ans	

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
		'''while(len(l)>2):
			p1=min(calc_prefix(l[0],l[1]),calc_suffix(l[0],l[1]))
			p2=min(calc_prefix(l[1],l[2]),calc_suffix(l[1],l[2]))
			print(p1," - ",p2)
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
			ans=ans+p1**2'''
		alpha=[]
		n=len(l)
		for x in range(26):
			alpha.append([])
		for q in range(n):
			c=ord(l[q][-1])-97
			alpha[c].append(l[q])
		'''for q in range(26):
			if alpha[q]!=[]:
				alpha[q].sort()'''
		#print(alpha)	
		for q in range(26):
			if alpha[q]!=[]:
				#print(alpha[q])
				ans=ans+calc_advanced(alpha[q])
	return ans	

t=int(input())
for i in range(t):
	n=int(input())
	l=[]
	#visited=[]
	for q in range(n):
		x=input()
		l.append(x)
		#visited.append(False)
	'''arr=[]
	c=0
	lenarr=0
	for q in range(n-1):
		lenq=len(l[q])
		for w in range(q+1,n):
			lenw=len(l[w])
			lmin=min(lenq,lenw)
			pref=calc_prefix(l[q],l[w])
			suf=calc_suffix(l[q],l[w])
			wt=min(pref,suf)
			if(wt>0):
				lenarr=lenarr+1
				arr.append((q,w,wt*wt))
	arr.sort(key = lambda x: x[2],reverse=True)
	#print(arr)
	count=0
	sum=0
	for q in arr:
		if(count>(n//2)):
			break
		if (not(visited[q[0]] or visited[q[1]])):
			count=count+1
			sum=sum+q[2]
			visited[q[0]]=True
			visited[q[1]]=True
	print(sum)	'''	
		

	#l.sort()
	#print(l)	
	#=========================================================================================================
	'''ans=0
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
	print(ans)		
	'''
	#=========================================================================================================
	'''
	def order(pre):
    print(pre)
    pre.sort()
    print(pre)
    suf=[s[::-1] for s in pre]
    suf.sort()
    print(suf)
    
	print(order(['abcdefghijkl','abcdxyzijkl','abcdefgqwer','aqweqwebcdxyzijkl','abcdefghxyzijkl','abcjkl']))

	'''
	#============================================================================================================

	alpha=[]
	for q in range(26):
		alpha.append([])
	for q in range(n):
		c=ord(l[q][0])-97
		alpha[c].append(l[q])
	#print(alpha)	
	ans=0
	for q in range(26):
		ans=ans+calc(alpha[q])
	print(ans)	
