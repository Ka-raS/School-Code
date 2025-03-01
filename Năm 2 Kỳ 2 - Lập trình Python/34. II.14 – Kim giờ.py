import datetime

def to_angle(time: datetime.time) -> float:
    return time.hour * 30 + time.minute / 2 + time.second / 120

def main() -> None:
    time = datetime.time(*map(int, input().split()))
    print(f'Angle: {to_angle(time)}')
              
if __name__ == '__main__':
    main()