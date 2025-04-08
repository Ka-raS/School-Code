BOUNDS = (4, 6, 9, 12, 15, 19, 22, 26, 29, 32, 34, 36, 38, 40)

def convert_answers(answers: int) -> float:
    grade = 25
    for bound in BOUNDS:
        if answers <= bound:
            break
        grade += 5
    return grade / 10

def ielts(reading: int, listening: int, speaking: int, writing: int) -> int:
    reading = convert_answers(reading)
    listening = convert_answers(listening)

    average = (reading + listening + speaking + writing) / 4
    whole = int(average)
    floating = average - whole
    
    if floating >= 0.75:
        floating = 1
    elif floating >= 0.25:
        floating = 0.5
    else:
        floating = 0
    return whole + floating

def run_test() -> None:
    reading, listening, speaking, writing = map(float, input().split())
    print(f'{ielts(reading, listening, speaking, writing):.1f}')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()