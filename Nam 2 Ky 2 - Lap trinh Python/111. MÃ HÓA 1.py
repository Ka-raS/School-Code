def encode(code: str) -> str:
    result = ''
    count = 0
    for i in range(1, len(code)):
        count += 1
        if code[i] != code[i - 1]:
            result += f'{count}{code[i - 1]}'
            count = 0
    return f'{result}{count + 1}{code[-1]}'

def run_test() -> None:
    code = input()
    print(encode(code))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()