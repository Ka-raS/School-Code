import sys
import math
import typing

def i_ran_out_of_names(array: typing.List[int], begin: int, end: int, divisor_target: int) -> int:
    result = float('inf')

    for i in range(begin, end):
        divisor = 0
        for j in range(i, end):
            divisor = math.gcd(divisor, array[j])
            if divisor == divisor_target:
                result = min(result, j - i + 1)
                break

    return result

def shortest_gcd_sequence_length(array: typing.List[int], length: int, divisor_target: int) -> int:
    result = float('inf')

    i = 0
    while i < length:
        while i < length and array[i] % divisor_target != 0:
            i += 1
        begin = i
        while i < length and array[i] % divisor_target == 0:
            i += 1
        end = i
        result = min(result, i_ran_out_of_names(array, begin, end, divisor_target))

    if result != float('inf'):
        return result
    return -1

def main() -> None:
    i = 1
    inputs = sys.stdin.read().split()
    tests = int(inputs[0])

    for test in range(tests):
        length = int(inputs[i])
        divisor_target = int(inputs[i + 1])
        array = list(map(int, inputs[(i + 2):(i + length + 2)]))

        print(shortest_gcd_sequence_length(array, length, divisor_target))
        i += 2 + length

if __name__ == '__main__':
    main()