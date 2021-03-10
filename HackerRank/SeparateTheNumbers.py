# HackerRank - University CodeSprint 2 - Separate the Numbers
TC = int(input())

for TEST in range(TC):
    st, noAns = input(), True
    for length in range(1, len(st) // 2 + 1):
        if st[0] == "0":
            break
        f = int(st[:length])
        x = f
        currentLength, pos, isAns = length, length, True
        while pos < len(st):
            # print(f, end = ' ')
            if pos + currentLength > len(st):
                isAns = False
                break

            if (
                st[pos : pos + currentLength][0] != "0"
                and int(st[pos : pos + currentLength]) - f == 1
            ):
                f = int(st[pos : pos + currentLength])
                pos += currentLength
            elif (
                st[pos : pos + currentLength + 1][0] != "0"
                and int(st[pos : pos + currentLength + 1]) - f == 1
            ):
                f = int(st[pos : pos + currentLength + 1])
                pos += currentLength + 1
                currentLength += 1
            else:
                isAns = False
                break

        if isAns:
            print("YES", x)
            noAns = False
            break

    if noAns:
        print("NO")
