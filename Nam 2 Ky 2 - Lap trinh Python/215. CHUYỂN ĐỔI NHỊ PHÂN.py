import sys
from typing import List

keys: List[str] = []
keys.extend(map(chr, range(ord('0'), ord('9') + 1)))
keys.extend(map(chr, range(ord('A'), ord('Z') + 1)))

def convert(decimal: int, to_base: int) -> str:
    result = ''
    while decimal > 0:
        digit = decimal % to_base
        decimal //= to_base
        result += keys[digit]
    return result[::-1]

def run_test() -> None:
    to_base = int(sys.stdin.readline())
    binary = sys.stdin.readline()
    decimal = int(binary, 2)
    print(convert(decimal, to_base))

def main() -> None:
    with open('DATA.in', 'r') as infile:
        sys.stdin = infile

        tests = int(sys.stdin.readline())
        for test in range(tests):
            run_test()

if __name__ == '__main__':
    main()