from itertools import combinations

def main() -> None:
    name_count, new_name_count = map(int, input().split())
    names = sorted(set(input().split()))
    for combination in combinations(names, new_name_count):
        print(*combination)

if __name__ == '__main__':
    main()