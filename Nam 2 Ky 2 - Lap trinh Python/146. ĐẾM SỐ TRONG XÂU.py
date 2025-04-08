def run_test() -> None:
    sequence = input()
    target = input()
    print(sequence.count(target))

def main() -> None:
    for test in range(int(input())):
        run_test()

if __name__ == '__main__':
    main()