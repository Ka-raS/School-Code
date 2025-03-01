def main() -> None:
    a, k, n = map(int, input().split())
    lst = [number for number in range(k - a % k, n - a + 1, k)]
    if not lst:
        lst = [-1]
    print(*lst)

if __name__ == '__main__':
    main()