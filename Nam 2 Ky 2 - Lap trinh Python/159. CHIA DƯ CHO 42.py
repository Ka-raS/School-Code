import sys

def main() -> None:
    array = map(int, sys.stdin.read().split())
    keys = set(number % 42 for number in array)
    print(len(keys))

if __name__ == '__main__':
    main()