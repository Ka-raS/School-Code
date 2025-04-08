import itertools

def main() -> None:
    n, r = map(int, input().split())
    keys = sorted(set(map(int, input().split())))
    for combination in itertools.combinations(keys, r):
        print(*combination)

if __name__ == '__main__':
    main()