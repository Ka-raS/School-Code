from typing import List
import math

def print_coprimes(array: List[int], length: int) -> None:
    for i in range(length - 1):
        num1 = array[i]
        for j in range(i + 1, length):
            num2 = array[j]

            if math.gcd(num1, num2) == 1:
                print(num1, num2)

def main() -> None:
    length = int(input())
    array = sorted(map(int, input().split()))
    print_coprimes(array, length)
if __name__ == '__main__':
    main()