from typing import List

def max_prod_of_3s_or_2s(numbers: List[int]) -> int:
    numbers.sort()
    products = (
        numbers[-1] * numbers[-2] * numbers[-3],
        numbers[-1] * numbers[0] * numbers[1],
        numbers[-1] * numbers[-2],
        numbers[0] * numbers[1]
    )
    return max(products)

def main() -> None:
    length = int(input())
    numbers = list(map(int, input().split()))
    print(max_prod_of_3s_or_2s(numbers))

if __name__ == '__main__':
    main()