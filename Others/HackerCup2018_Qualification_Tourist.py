from queue import PriorityQueue

for test_case in range(int(input())):
    n, k, v = list(map(int, input().split()))
    name = []
    for i in range(n):
        name.append(input())

    a = PriorityQueue()

    for i in range(n):
        a.put((0, i, i))

    t = [[i for i in range(n)]]
    while True:
        for i in range(k):
            p = a.get()
            p = (p[0] + 1, p[1], p[2])
            a.put(p)
        t.append([i[2] for i in sorted(a.queue)])
        if t[-1] == [i for i in range(n)]:
            break

    t.pop()

    ans = 'Case #{}:'.format(test_case + 1)
    for i in sorted(t[(v - 1) % len(t)][:k]):
        ans += " " + name[i]
    print(ans)
