def minion_game(string):
    # your code goes here
    x=len(string)
    kevin=stuart=0
    for i in range(x):
        if string[i].lower() in 'aouie':
            kevin+=x-i
        else:
            stuart+=x-i

    if kevin > stuart :
        print("Kevin",kevin)
    elif kevin < stuart :
        print("Stuart",stuart)
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)