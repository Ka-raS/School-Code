def is_iPv4(code: str) -> bool:
    try:
        octets = list(map(int, code.split('.')))
    except Exception:
        return False
    
    if len(octets) != 4:
        return False
    
    for octet in octets:
        if not 0 <= octet <= 255:
            return False
    
    return True

def run_test() -> None:
    code = input()
    if is_iPv4(code):
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main() 