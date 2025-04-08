from typing import Iterable

def groups(numbers: Iterable[int], distance: int, MAX: int) -> int:
    visited = [False] * MAX
    for number in numbers:
        visited[number] = True
    
    count = 0
    next_number = 0
    while True:
        number = next_number
        while number < MAX:
            if visited[number]:
                break
            number += 1

        if number == MAX:
            break

        next_number = number + 1
        while next_number < MAX:
            if visited[next_number]:
                break
            next_number += 1
        
        if next_number - number > distance:
            count += 1
    
    return count + 1

def main() -> None:
    length, distance = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(groups(numbers, distance, max(numbers) + 1))

if __name__ == '__main__':
    main()