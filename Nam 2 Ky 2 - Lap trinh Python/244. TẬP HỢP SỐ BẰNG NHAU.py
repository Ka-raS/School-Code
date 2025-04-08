def main() -> None:
    length_a, length_b = map(int, input().split())
    set_a = set(map(int, input().split()))
    set_b = set(map(int, input().split()))

    if set_a == set_b:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()