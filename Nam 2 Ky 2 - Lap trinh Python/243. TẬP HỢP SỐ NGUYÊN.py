def main() -> None:
    length_a, length_b = map(int, input().split())
    set_a = set(map(int, input().split()))
    set_b = set(map(int, input().split()))

    print(*sorted(set_a & set_b))
    print(*sorted(set_a - set_b))
    print(*sorted(set_b - set_a))

if __name__ == '__main__':
    main()