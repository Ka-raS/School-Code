def is_valid(equation: str) -> bool:
    a = int(equation[0])
    b = int(equation[4])
    c = int(equation[8])
    return a + b == c

def main() -> None:
    equation = input()  
    if is_valid(equation):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()