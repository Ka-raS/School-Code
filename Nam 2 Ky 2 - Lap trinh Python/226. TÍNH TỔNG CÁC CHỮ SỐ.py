def convert(sequence: str) -> str:
    counter = [0] * 91

    for char in sequence:
        counter[ord(char)] += 1

    letters = ''
    for letter in range(65, 91):
        letters += chr(letter) * counter[letter]
    
    sum_digit = 0
    for digit in range(1, 10):
        sum_digit += digit * counter[digit + 48]
    
    return f'{letters}{sum_digit}'

def run_test() -> None:
    sequence = input()
    print(convert(sequence))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()