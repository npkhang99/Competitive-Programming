import math
import sys


class point:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __str__(self):
        return "x = {}, y = {}".format(self.x, self.y)


def distance(p):
    return p.x ** 2 + p.y ** 2


def solve_normal(a):
    angles = dict()
    for p in a:
        angle = math.atan2(p.x, p.y)
        # print(str(p) + ' angle: {}'.format(angle), file = sys.stderr)
        if angle not in angles:
            angles[angle] = [p]
        else:
            angles[angle].append(p)

    not_visible = []
    for angle, points in angles.items():
        # print('Angle: {:5.2f} | Points: {}'.format(angle, ''.join('(' + str(p) + ', z = {}); '.format(p.z) for p in points)), file = sys.stderr)
        highest_z = -1
        for p in sorted(
            points, key=lambda k: k.x if k.x > 0 else -k.x if k.x < 0 else k.y
        ):
            if p.z <= highest_z:
                not_visible.append(p)
            else:
                highest_z = p.z

    return not_visible


def solve_ox(a):
    a = sorted(a, key=lambda k: k.x)

    k = 0
    while k < len(a) and a[k].x < 0:
        k += 1

    not_visible = []
    highest_z = -1
    for i in range(k - 1, -1, -1):
        if a[i].z <= highest_z:
            not_visible.append(a[i])
        else:
            highest_z = a[i].z

    highest_z = -1
    for i in range(k, len(a)):
        if a[i].z <= highest_z:
            not_visible.append(a[i])
        else:
            highest_z = a[i].z

    return not_visible


def main():
    data_set = 0
    while True:
        n = int(input())
        if n == 0:
            break

        a = []
        for i in range(n):
            x, y, z = map(int, input().split())
            a.append(point(x, y, z))

        a = sorted(a, key=lambda k: (-k.y, k.x, k.z))

        not_visible = []
        l, r = 0, 0
        while r < n and a[r].y > 0:
            r += 1

        not_visible += solve_normal(a[l:r])

        l = r
        while r < n and a[r].y == 0:
            r += 1

        not_visible += solve_ox(a[l:r])

        l = r
        for i in range(l, n):
            a[i].x *= -1

        not_visible += solve_normal(a[l:n])

        data_set += 1
        print("Data set {}:".format(data_set))
        if len(not_visible) == 0:
            print("All the lights are visible.")
        else:
            print("Some lights are not visible:")
            print(
                *sorted(not_visible, key=lambda k: (k.x, k.y)),
                sep=";\n",
                end=".\n"
            )


if __name__ == "__main__":
    main()
