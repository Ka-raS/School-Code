import re

def run_test() -> None:
    sequence = input()
    target = input()

    lst = re.split(target, sequence)
    print(len(lst))

def main() -> None:
    for test in range(int(input())):
        run_test()

if __name__ == '__main__':
    main()