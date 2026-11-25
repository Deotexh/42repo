import sys

if __name__ == "__main__":
    i: int = 1
    score: list = []
    while (i < len(sys.argv)):
        try:
            score.append(int(sys.argv[i]))
        except Exception:
            print(f"Invalid parameter: '{sys.argv[i]}'")
        i += 1
    if (len(score) > 0):
        print(f"Total players: {len(score)}")
        print(f"Total score: {sum(score)}")
        print(f"Average score: {sum(score) / len(score)}")
        print(f"High score: {max(score)}")
        print(f"Low score: {min(score)}")
        print(f"Score range: {max(score) - min(score)}")
    else:
        print("No scores provided.", end='')
        print("Usage: python3 ft_score_analytics.py <score1> <score2> ...")
