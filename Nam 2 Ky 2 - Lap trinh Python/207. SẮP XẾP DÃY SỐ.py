from typing import List

def insert_before(numbers: List[int], insert_value: int, target_value: int) -> List[int]:
    negatives: List[int] = []
    positives: List[int] = []

    def insert(value: int) -> None:
        if value < 0:
            negatives.append(value)
        else:
            positives.append(value)

    for number in numbers:
        if number == target_value:
            insert(insert_value)
        insert(number)

    result = negatives
    result.extend(positives)
    return result

def run_test() -> None:
    length, value = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(*insert_before(numbers, value, max(numbers)))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()