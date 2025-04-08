import sys
from typing import Iterable

def first_duplicate(array: Iterable[int]) -> int:
    target = 1
    for num in array:
        if num != target:
            return num
        target += 1

def main() -> None: 
    bound = int(sys.stdin.readline()) 
    array = sorted(int(sys.stdin.readline()) for _ in range(bound - 1))
    print(first_duplicate(array))
    
if __name__ == '__main__': 
    main()