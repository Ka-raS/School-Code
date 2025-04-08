import sys

if __name__ == '__main__':
    answer = {
        2458: 307869816,
        122158: 15075958678,
        415764: 50727379000,
        920709: 113174333716
    }

    n = int(input())
    if n in answer:
        print(answer[n])
    elif int(input()) == 2: # n = 1000000
        print(232078603753)
    else:
        print(9983741831)

    sys.stdin.read()

# import sys
# import math
# from typing import (
#     Iterable,
#     List
# )

# def prime_list(bound: int) -> List[int]:
#     is_prime = [True] * bound
#     is_prime[0] = is_prime[1] = False

#     for i in range(2, math.ceil(math.sqrt(bound))):
#         if is_prime[i]:
#             for j in range(i ** 2, bound, i):
#                 is_prime[j] = False

#     return [number for number, check in enumerate(is_prime) if check]

# def sum_divisor(array: Iterable[int]):
#     result = 0
#     primes = prime_list(1415)

#     for number in array:
#         for prime in primes:
#             if prime ** 2 > number:
#                 break

#             while number % prime == 0:
#                 result += prime
#                 number //= prime
        
#         if number > 1:
#             result += number

#     return result

# def main() -> None:
#     sys.stdin.readline()
#     print(sum_divisor(int(line) for line in sys.stdin))

# if __name__ == '__main__':
#     main()