from collections import Counter

def test_result() -> str:
    string1 = input()
    string2 = input()
    if Counter(string1) == Counter(string2):
        return 'YES'
    else:
        return 'NO'
 
def main() -> None:
    tests = int(input())
    for test in range(1, tests + 1):
        print(f'Test {test}: {test_result()}')

if __name__ == '__main__':
    main()