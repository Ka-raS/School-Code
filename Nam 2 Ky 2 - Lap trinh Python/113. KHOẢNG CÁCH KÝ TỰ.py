def is_reverse_equal_distance(string: str) -> bool:
    reverse = string[::-1]
    for i in range(1, len(string)):
        distance1 = abs(ord(string[i]) - ord(string[i - 1]))
        distance2 = abs(ord(reverse[i]) - ord(reverse[i - 1]))
        if distance1 != distance2:
            return False
    return True

def run_test() -> None:
    string = input()
    if is_reverse_equal_distance(string):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()