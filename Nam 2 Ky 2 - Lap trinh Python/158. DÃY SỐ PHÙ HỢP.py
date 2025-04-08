from typing import Iterable

def is_value(array1: Iterable[int], array2: Iterable[int]) -> bool:
    for number1, number2 in zip(array1, array2):
        if number1 > number2:
            return False
    return True

def run_test() -> None:
    length = int(input())
    array1 = sorted(map(int, input().split()))
    array2 = sorted(map(int, input().split()))

    if is_value(array1, array2):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()