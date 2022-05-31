testcase = int(input())
for i in range(testcase):
    measure_num = int(input())
    left=[]
    right=[]
    res = 0
    l2r = 0
    # for j in range(measure_num):
    #     left = list(map(int, input().split()))
    left = list(map(int, input().split()))

    # for j in range(measure_num):
    #     right = list(map(int, input().split()))
    right = list(map(int, input().split()))
        
    while left:
        leftone = left.pop()
        if leftone + 1000 in right:
            res += 1

        if res == 2:
            res = 0
            l2r += 1

    print(l2r)