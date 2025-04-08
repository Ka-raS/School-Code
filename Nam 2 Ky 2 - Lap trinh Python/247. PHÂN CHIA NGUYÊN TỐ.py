from typing import Iterable

def is_prime(number: int) -> bool:
    if number <= 1:
        return False
    if number <= 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False
    
    for divisor in range(5, int(number** 0.5) + 1, 6):
        if number % divisor == 0 or number % (divisor + 2) == 0:
            return False
    return True

def prime_pos(numbers: Iterable[int]) -> int:
    visited: dict[int, None] = {}
    for number in numbers:
        visited[number] = None
    numbers = visited.keys()

    sum_left = 0
    sum_right = sum(numbers)

    for pos, number in enumerate(numbers):
        sum_left += number
        sum_right -= number
        if is_prime(sum_left) and is_prime(sum_right):
            return pos
        
    return -1

def main() -> None:
    length = int(input())
    numbers = map(int, input().split())
    pos = prime_pos(numbers)
    if pos != -1:
        print(pos)
    else:
        print('NOT FOUND')

if __name__ == '__main__':
    main()