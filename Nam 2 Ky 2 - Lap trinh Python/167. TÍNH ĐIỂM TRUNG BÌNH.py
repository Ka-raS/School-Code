from typing import List

def sum_without_min_max(array: List[float]) -> float:
    min_num = min(array)
    max_num = max(array)

    count = 0
    sum_num = 0
    for num in array:
        if num != min_num and num != max_num:
            sum_num += num
            count += 1
    
    return sum_num / count

def main() -> None:
    length = int(input())
    array = list(map(float, input().split()))
    print(f'{sum_without_min_max(array):.2f}')

if __name__ == '__main__':
    main()