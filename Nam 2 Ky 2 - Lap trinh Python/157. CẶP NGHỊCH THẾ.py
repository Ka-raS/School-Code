from typing import List

def opposites(array: List[int], length: int) -> int:
    count = 0
    for i in range(length - 1):
        for j in range(i + 1, length):
            count += array[i] > array[j]
    return count

def main() -> None:
    length = int(input())
    array = list(map(int, input().split()))
    print(opposites(array, length))

if __name__ == '__main__':
    main()