def decode(code: str) -> str:
    result = ''
    for i in range(1, len(code), 2):
        count = int(code[i])
        letter = code[i - 1]
        result += letter * count
    return result

def run_test() -> None:
    code = input()
    print(decode(code))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()