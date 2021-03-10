day1, day2 = input(), input()

a = {
    "sunday": 0,
    "monday": 1,
    "tuesday": 2,
    "wednesday": 3,
    "thursday": 4,
    "friday": 5,
    "saturday": 6,
}

if a[day2] < a[day1]:
    a[day2] += 7

diff = abs(a[day2] - a[day1])

if diff == 0 or diff == 3 or diff == 2:
    print("YES")
else:
    print("NO")
