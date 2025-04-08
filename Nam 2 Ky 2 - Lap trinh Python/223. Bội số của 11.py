def run_test(inputs: str) -> None:
    number = int(inputs)
    if number % 11 == 0:
        print('YES')
    else:
        print('NO')

def main() -> None:
    while True:
        inputs = input()
        if inputs == '-1':
            break
        run_test(inputs)

if __name__ == '__main__':
    main()