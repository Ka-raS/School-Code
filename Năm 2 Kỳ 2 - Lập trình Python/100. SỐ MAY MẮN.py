def is_lucky(number: str) -> bool:
    count4 = count7 = 0
    for digit in number:
        if digit == '4':
            count4 += 1
        elif digit == '7':
            count7 += 1
    sum = count4 + count7
    return sum == 4 or sum == 7

def main() -> None:
    number = input()
    if is_lucky(number):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()