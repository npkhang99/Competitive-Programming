def main():
    for t in range(int(input())):
        n, m = map(int, input().split())
        a = []
        for i in range(n):
            a.append(list(map(int, input().split())))

        rows_left = [1] * n
        columns_left = [1] * m
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    rows_left[i] = 0
                    columns_left[j] = 0

        moves_left = min(sum(rows_left), sum(columns_left))

        print("Ashish" if moves_left % 2 == 1 else "Vivek")


if __name__ == "__main__":
    main()
