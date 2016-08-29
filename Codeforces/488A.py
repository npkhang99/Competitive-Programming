n = int(raw_input())

def isLucky(s):
	for i in str(s):
		if i=='8': return True
	return False

i = 1
while not isLucky(n+i): i+=1

print(i)
