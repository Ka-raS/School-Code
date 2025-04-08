import typing

g_pretty_numbers: typing.List[int]

def is_pretty(string: str) -> bool:
    n: int = len(string)
    if n & 1:
        return False
    for i in range(n >> 1):
        if string[i] != string[n - 1 - i]:
            return False
    return True

def find_pretty_numbers() -> None:
    even_strings: typing.List[str] = ['2', '4', '6', '8']
    DIGITS: typing.Tuple[str, str, str, str, str] = ('0', '2', '4', '6', '8')

    for string in even_strings:
        if len(string) >= 6:
            break
        for digit in DIGITS:
            even_strings.append(string + digit)
    
    global g_pretty_numbers
    g_pretty_numbers = []

    for string in even_strings:
        if is_pretty(string):
            g_pretty_numbers.append(int(string))

def main() -> None:
    global g_pretty_numbers
    find_pretty_numbers()

    tests: int = int(input())
    for test in range(tests):
        upper_bound: int = int(input())

        for number in g_pretty_numbers:
            if number >= upper_bound:
                break
            print(number, end=' ')
        print()

if __name__ == '__main__':
    main()