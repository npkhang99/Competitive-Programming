n = int(input())

def isLeapYear(a):
	return a%400==0 or (a%4==0 and a%100!=0)

a = n

if isLeapYear(n): days=366
else: days=365

a+=1

while not (days%7==0 and (isLeapYear(a)==isLeapYear(n))):
	if isLeapYear(a): days+=366
	else: days+=365
	a+=1

print(a)