for _ in range(int(input())):
    input()
    li = list(map(int, input().split(" ")))
    st, i, t = [], 0, len(li) - 1
    j = 0
    while i < t:
        if len(st) == 0:
            if li[t] > li[i]:
                st.append(li[t])
                t -= 1
            else:
                st.append(li[i])
                i += 1
        else:
            if li[i] < li[t] <= st[-1]:
                st.append(li[t])
                t -= 1
            elif li[t] <= li[i] <= st[-1]:
                st.append(li[i])
                i += 1
            else:
                j = 1
                print("No")
                break
        # print(st)
    if j == 0:
        print("Yes")