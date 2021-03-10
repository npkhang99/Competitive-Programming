def main():
    for t in range(int(input())):
        n = int(input())
        a = list(
            zip(
                list(map(int, input().split())), list(map(int, input().split()))
            )
        )

        cnt = [0, 0]
        for i in range(n):
            cnt[a[i][1]] += 1

        is_sorted = True
        for i in range(1, n):
            if a[i - 1][0] > a[i][0]:
                is_sorted = False
                break

        ans = (
            "Yes"
            if is_sorted or (not is_sorted and cnt[0] != 0 and cnt[1] != 0)
            else "No"
        )

        print(ans)


if __name__ == "__main__":
    main()
