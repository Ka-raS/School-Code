string = ''
for i in range(24):
    string += chr(i + 65) + string

def run_test() -> None:
    steps, index = map(int, input().split())
    print(string[index - 1])

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()