import sys
import typing

def is_palindrome(sequence: str) -> bool:
    left = 0
    right = len(sequence) - 1
    while left < right:
        if sequence[left] != sequence[right]:
            return False
        left += 1
        right -= 1
    return True

def find_even_palindromes() -> typing.List[int]:
    result = []

    even_strings = ['2', '4', '6', '8']
    EVEN_DIGITS = ('0', '2', '4', '6', '8')

    for string in even_strings:
        length = len(string)
        if length >= 6:
            break

        for even in EVEN_DIGITS:
            even_strings.append(string + even)
            if length & 1 and is_palindrome(even_strings[-1]):
                result.append(int(even_strings[-1]))

    return result

def run_test(inputs: str, even_palindromes: typing.List[int]) -> None:
    upper_bound = int(inputs)
    for number in even_palindromes:
        if number >= upper_bound:
            break
        print(number, end=' ')
    print()

def main() -> None:
    even_palindromes = find_even_palindromes()
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs, even_palindromes)

if __name__ == '__main__':
    main()