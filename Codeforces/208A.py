st = input()

ans, skip, temp = [], 0, ""

for i in range(len(st)):
    if skip:
        skip -= 1
        continue
    if st[i : i + 3] == "WUB":
        if temp != "":
            ans.append(temp)
        temp = ""
        skip = 2
        continue
    temp += st[i]

for i in ans:
    print(i, end=" ")

if temp != "":
    print(temp)
