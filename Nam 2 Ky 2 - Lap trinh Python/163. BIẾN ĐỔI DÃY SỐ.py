from typing import List

def count_steps(array: List[int]) -> int:
    count = 0
    while array.count(array[0]) != 4:
        count += 1
        copy = array.copy()
        for i in range(-1, 3):
            array[i] = abs(array[i] - copy[i + 1])
    return count

def main() -> None:
    while True:
        array = list(map(int, input().split()))
        if array == [0] * 4:
            break
        print(count_steps(array))    

if __name__ == '__main__':
    main()