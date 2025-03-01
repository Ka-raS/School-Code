import datetime

def count_seconds(time: datetime.time) -> int:
    return time.hour * 3600 + time.minute * 60 + time.second

def time_passed(time_begin: datetime.time, time_end: datetime.time) -> int:
    seconds_begin = count_seconds(time_begin)
    seconds_end = count_seconds(time_end)
    
    distance = seconds_end - seconds_begin
    if seconds_begin > seconds_end:
        distance += 86400
    return distance

def main() -> None:
    time_begin = datetime.time(*map(int, input().split()))
    time_end = datetime.time(*map(int, input().split()))
    print(time_passed(time_begin, time_end))

if __name__ == '__main__':
    main()