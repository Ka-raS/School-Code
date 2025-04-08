def run_test() -> None:
    sequence = input()
    target = input()
    print(sequence.count(target))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()