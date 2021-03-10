n, st = int(input()), input()

cnt1, cnt2 = st.count("A"), st.count("D")

if cnt1 > cnt2:
    print("Anton")
elif cnt1 < cnt2:
    print("Danik")
else:
    print("Friendship")
