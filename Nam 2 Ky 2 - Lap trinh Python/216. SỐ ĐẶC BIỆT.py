MODULO = 1_000_000_007

def sum_exponentials(number: int, position: int) -> int:
    result = 0
    product = 1
    binary = bin(position)
    
    for digit in binary[2:][::-1]:
        if digit == '1':
            result = (result + product) % MODULO
        product = (product * number) % MODULO   
    
    return result

def run_test() -> None:
    number, position = map(int, input().split())
    print(sum_exponentials(number, position))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()