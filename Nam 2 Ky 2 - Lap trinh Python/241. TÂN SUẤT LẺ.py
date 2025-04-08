import collections
from typing import Iterable

def odd_count(numbers: Iterable[int]) -> int:
    counter = collections.Counter(numbers)
    for number, count in counter.items():
        if count % 2 != 0:
            return number

def run_test() -> None:
    length = int(input())
    numbers = map(int, input().split())
    print(odd_count(numbers))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()