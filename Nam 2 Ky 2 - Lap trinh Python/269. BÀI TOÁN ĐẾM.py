import sys
from typing import List

def find_missing(numbers: List[int]) -> List[int]:
    limit = max(numbers) + 1
    visited = [False] * limit
    for number in numbers:
        visited[number] = True
    
    missing: List[int] = []
    for number in range(1, limit):
        if not visited[number]:
            missing.append(number)
    return missing

def main() -> None:
    length = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.read().split()))
    missing = find_missing(numbers)
    if missing:
        print(*missing, sep='\n')
    else:
        print('Excellent!')

if __name__ == '__main__':
    main()