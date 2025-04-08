import sys
from typing import List

def sorted_even_odd(numbers: List[int]) -> None:
    odds: List[int] = []
    evens: List[int] = []
    odd_pos: List[int] = []
    even_pos: List[int] = []

    for pos, number in enumerate(numbers):
        if number % 2 == 0:
            evens.append(number)
            even_pos.append(pos)
        else:
            odds.append(number)
            odd_pos.append(pos)
    
    evens.sort()
    odds.sort(reverse=True)

    for pos, even in zip(even_pos, evens):
        numbers[pos] = even
    for pos, odd in zip(odd_pos, odds):
        numbers[pos] = odd

def main() -> None:
    length = int(input())
    numbers = list(map(int, sys.stdin.read().split()))
    sorted_even_odd(numbers)
    print(*numbers)

if __name__ == '__main__':
    main()