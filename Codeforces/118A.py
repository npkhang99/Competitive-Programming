s = input().lower()
a = ["a", "e", "y", "o", "u", "i"]

for i in s:
    if not i in a:
        print("." + i, end="")
