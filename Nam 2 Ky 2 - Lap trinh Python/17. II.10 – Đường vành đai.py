def kilometer_stone(road_length: int, velocity: int, time: int, is_clockwise: bool) -> int:
    driven_length = velocity * time
    position = driven_length % road_length

    if is_clockwise:
        return position
    return road_length - position


def main() -> None:
    road_length = int(input())
    velocity = int(input())
    time = int(input())
    is_clockwise = True if input() == 'A' else False

    print(kilometer_stone(road_length, velocity, time, is_clockwise))

if __name__ == '__main__':
    main()