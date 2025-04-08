def character_limit(string: str, limit: int) -> str:
    if len(string) <= limit:
        return string
    
    end = string.rfind(' ', 0, limit - 1)
    return string[:end]

def run_test() -> None:
    notification = input()
    print(character_limit(notification, 100))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()