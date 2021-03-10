TC = int(input())


def readSnake():
    raw = [int(i) for i in input().split()]
    return [[raw[0], raw[1]], [raw[2], raw[3]]]


def ver(end):
    return end[0][0] == end[1][0]


def hor(end):
    return end[0][1] == end[1][1]


def ver_ver(s1, s2):
    if s1[0][0] != s2[0][0]:
        return False
    if s1[0][1] not in range(s2[0][1], s2[1][1] + 1) and s1[1][1] not in range(
        s2[0][1], s2[1][1] + 1
    ):
        return False
    return True


def ver_hor(s1, s2):
    if s1[0] in [s2[0], s2[1]] or s1[1] in [s2[0], s2[1]]:
        return True
    return False


def hor_hor(s1, s2):
    if s1[0][1] != s2[0][1]:
        return False
    if s1[0][0] not in range(s2[0][0], s2[1][0] + 1) and s1[1][0] not in range(
        s2[0][0], s2[1][0] + 1
    ):
        return False
    return True


def swap(raw):
    if ver(raw) and raw[0][1] > raw[1][1]:
        return [raw[1], raw[0]]
    if hor(raw) and raw[0][0] > raw[1][0]:
        return [raw[1], raw[0]]
    return raw


for _ in range(TC):
    snake1 = swap(readSnake())
    snake2 = swap(readSnake())

    if ver(snake1) and ver(snake2):
        if ver_ver(snake1, snake2):
            print("yes")
        else:
            print("no")

    if hor(snake1) and hor(snake2):
        if hor_hor(snake1, snake2):
            print("yes")
        else:
            print("no")

    if ver(snake1) and hor(snake2):
        if ver_hor(snake1, snake2):
            print("yes")
        else:
            print("no")

    if hor(snake1) and ver(snake2):
        if ver_hor(snake2, snake1):
            print("yes")
        else:
            print("no")
