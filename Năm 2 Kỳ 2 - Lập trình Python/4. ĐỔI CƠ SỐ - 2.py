def convert_base(binary: str, to_base: int) -> str:
    if to_base == 2:
        return binary

    decimal: int = int(binary, 2)

    if to_base == 4:
        if decimal == 0:
            return '0'
        
        result: str = ''
        while decimal > 0:
            result += str(decimal % 4)
            decimal //= 4

        return result[::-1]
    
    elif to_base == 8:
        return format(decimal, 'o')
    elif to_base == 16:
        return format(decimal, 'X')
    
    return ''


def run_test() -> None:
    to_base: int = int(input())
    binary: str = input()
    print(convert_base(binary, to_base))

def main() -> None:
    testcases: int = int(input())
    for _ in range(testcases):
        run_test()

if __name__ == '__main__':
    main()