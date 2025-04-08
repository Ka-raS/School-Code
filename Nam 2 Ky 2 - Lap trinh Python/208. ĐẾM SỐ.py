from typing import Iterable

def count_number_not_in_range(numbers: Iterable[int], lowerbound: int, upperbound: int) -> int:
    not_visited = [True] * (upperbound + 1)
    for number in numbers:
        not_visited[number] = False
    return sum(not_visited[lowerbound:])

def run_test() -> None:
    length = int(input())
    numbers = list(map(int, input().split()))
    print(count_number_not_in_range(numbers, min(numbers), max(numbers)))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main() 