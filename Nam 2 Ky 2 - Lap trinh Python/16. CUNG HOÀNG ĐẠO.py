import typing

ASTROLOGICAL_SIGNS = (
    'Ma Ket',
    'Bao Binh',
    'Song Ngu',
    'Bach Duong',
    'Kim Nguu',
    'Song Tu',
    'Cu Giai',
    'Su Tu',
    'Xu Nu',
    'Thien Binh',
    'Thien Yet',
    'Nhan Ma'
)

ASTROLOGICAL_SIGN_KEYS = (
    None, 20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 23, 22
)

def get_astrological_sign(day: int, month: int) -> str:
    index = month
    if day < ASTROLOGICAL_SIGN_KEYS[month]:
        index = month - 1
    elif month == 12:
        index = 0
    return ASTROLOGICAL_SIGNS[index]

def run_test() -> None:
    day, month = map(int, input().split())
    print(get_astrological_sign(day, month))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()