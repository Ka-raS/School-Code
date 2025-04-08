def is_balance(s: str) -> bool:
    n = len(s)
    for i in range(1, n):
        distance1 = abs(ord(s[i]) - ord(s[i - 1]))
        distance2 = abs(ord(s[n - i]) - ord(s[n - i - 1]))
        if distance1 != distance2:
            return False
    return True

def run_test() -> None:
    sequence = input()
    if is_balance(sequence):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()