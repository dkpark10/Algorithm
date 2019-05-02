def Baek__1931(conflist):

    result = 1
    cur = conflist[0]

    for i in range(0,len(conflist)-1):
        if cur[1] <= conflist[i+1][0]:
            result += 1
            cur = conflist[i + 1]

    return result

if __name__ == "__main__":
    num = int(input())
    conflist = []

    for i in range(num):
        conf = []
        conf = list(map(int, input().split(' ')))
        conflist.append(conf)

    conflist= sorted(conflist,key=lambda finish:finish[1])
    print(Baek__1931(conflist))

# 왜틀린지 모르겠음 ㅜㅜ 
