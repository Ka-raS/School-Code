import typing

def ABC_strings(length: int) -> typing.List[str]:
    counts = [0] * 3
    strings = []

    def find_recursion(current_length: int, string: str) -> None:
        if current_length >= 3 and 0 < counts[0] <= counts[1] <= counts[2]:
            strings.append(string)

        if current_length == length:
            return

        for i in range(3):
            counts[i] += 1
            find_recursion(current_length + 1, string + chr(65 + i))
            counts[i] -= 1

    find_recursion(0, '')
    return sorted(strings, key=lambda string: len(string))

def main() -> None:
    length = int(input())
    for string in ABC_strings(length):
        print(string)

if __name__ == '__main__':
    main()