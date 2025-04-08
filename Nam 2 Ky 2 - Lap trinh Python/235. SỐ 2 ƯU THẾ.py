from typing import List

def two_dominant_ternaries(length: int) -> List[str]:
    ternaries = ['1', '2']
    result = ['2']

    for ternary in ternaries:
        for digit in '012':
            next = ternary + digit

            ternaries.append(next)
            if next.count('2') > len(next) // 2:
                result.append(next)
                
        if len(result) >= length:
            break
    
    return result

TERNARIES = two_dominant_ternaries(1000)

def run_test() -> None:
    count = int(input())
    print(*TERNARIES[:count])    

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()