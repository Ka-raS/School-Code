import bisect
from typing import List

def find_hamming() -> List[int]:
    hamming = [1]
    visited = {1}

    for number in hamming:
        for value in (number * 2, number * 3, number * 5):
            if value > 1_000_000_000_000_000_000:
                break
            if value not in visited:
                hamming.append(value)
                visited.add(value)
    
    hamming.sort()
    return hamming

def run_test(hamming: List[int]) -> None:
    number = int(input())
    position = bisect.bisect_left(hamming, number)

    if position != len(hamming) and hamming[position] == number:
        print(position + 1)
    else:
        print('Not in sequence')

def main() -> None:
    hamming = find_hamming()

    tests = int(input())
    for test in range(tests):
        run_test(hamming)

if __name__ == '__main__':
    main()