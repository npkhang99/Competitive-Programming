fo = open("test.out","w")

inp = input().split()
n,m = int(inp[0]),int(inp[1])
n+=1

inf = int(10E8)

vector = [[] for _ in range(n)]
front = [[] for _ in range(n)]
cost = [[inf for _ in range(n)] for __ in range(n)]
b = [False for _ in range(n)]

for i in range(n): cost[i][i] = 0

def DFS(root, u):
	b[u]=True
	for v in vector[u]:
		cost[root][v] = min(cost[root][u]+1, cost[root][v])
		if not b[v]: DFS(root,v)
		
def BFS(root):
	q = []
	q.insert(0,root)
	while q!=[]:
		u = q.pop()
		if b[u]: continue
		b[u] = True
		for v in vector[u]:
			cost[root][v] = min(cost[root][v], cost[root][u]+1)
			q.insert(0,v)

for i in range(m):
	inp = input().split()
	u,v = int(inp[0]),int(inp[1])
	cost[u][v] = 1
	vector[u].append(v)

# for i in range(n):
	# for j in range(n): b[j]=False
	# # DFS(i,i)
	# BFS(i)
	
for k in range(1,n):
	for i in range(1,n):
		for j in range(1,n):
			cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

ans = -inf
path = []

def findPath(s):
	global ans
	global path
	q = []
	q.append([0,s,0,[s]])
	while q != []:
		for i in q: fo.write(str(i)+'\n')
		current = q.pop(0)
		verNum, u, du = current[0], current[1], current[2]
		cpath=[]
		if verNum < 3:
			for v in range(1,n):
				if not(v in current[3]) and (cost[u][v]<inf):
					cpath = list(current[3])
					cpath.append(v)
					q.append([verNum+1, v, du+cost[u][v], cpath])
		elif ans <= du:
			ans, path = du, current[3]
			# print(ans, path)

for i in range(1,n):
	fo.write(str(i)+'\n')
	findPath(i)

# print('--')

for i in path:
	print(i, end=' ')
