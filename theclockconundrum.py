"""There are many ways to implement the solution, but many involve a lot of casework. Below is the shortest solution we know of.
Walk around the clock in the order 1, 2, …, 12. If we pass by two red strings or two blue strings in a row, the strings don't intersect; otherwise, they do.
This is because if we don't have two red or blue in a row, then the red and blue strings alternate, so there must be an intersection."""
def solve():
    a, b, c, d = map(int, input().split())
    s = ''
    for i in range(1, 13):
        if i == a or i == b:
            s += 'a'
        if i == c or i == d:
            s += 'b'
    if s == 'abab' or s == 'baba':
        print('YES')
    else:
        print('NO')

def main():
    tt = int(input())
    for _ in range(tt):
        solve()

if __name__ == "__main__":
    main()
