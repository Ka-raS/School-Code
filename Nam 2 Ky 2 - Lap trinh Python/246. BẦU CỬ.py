from typing import Iterable

def winner(votes: Iterable[int], candidate_count: int) -> int:
    counter = [0] * (candidate_count + 1)
    for vote in votes:
        counter[vote] += 1

    elected = None
    second_vote = 0
    most_vote = max(counter)

    for candidate in range(1, candidate_count + 1):
        vote = counter[candidate]
        if second_vote < vote < most_vote:
            second_vote = vote
            elected = candidate

    if elected:
        return elected
    return -1

def main() -> None:
    vote_count, candidate_count = map(int, input().split())
    votes = map(int, input().split())    
    
    elected = winner(votes, candidate_count)
    if elected != -1:
        print(elected)
    else:
        print('NONE')

if __name__ == '__main__':
    main()