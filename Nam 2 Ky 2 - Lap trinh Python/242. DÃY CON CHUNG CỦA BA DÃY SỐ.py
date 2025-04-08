from collections import Counter
from typing import Iterable, List

def intersection(array_a: Iterable[int], array_b: Iterable[int], array_c: Iterable[int]) -> List[int]:
    intersect = Counter(array_a) & Counter(array_b) & Counter(array_c)
    return list(intersect.elements())

def run_test() -> None:
    length_a, length_b, length_c = map(int, input().split())
    array_a = map(int, input().split())
    array_c = map(int, input().split())
    array_b = map(int, input().split())

    intersect = intersection(array_a, array_b, array_c)
    if intersect:
        print(*intersect)
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()