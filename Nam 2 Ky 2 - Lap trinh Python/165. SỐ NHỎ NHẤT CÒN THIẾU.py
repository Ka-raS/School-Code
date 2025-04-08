from typing import Iterable

def absent(array: Iterable[int]) -> int:
    bound = 30_002
    visited = [False] * bound
    for number in array:
        visited[number] = True
    for number in range(1, bound):
        if not visited[number]:
            return number

def main() -> None:
    length = int(input())
    array = map(int, input().split())
    print(absent(array))

if __name__ == '__main__':
    main()