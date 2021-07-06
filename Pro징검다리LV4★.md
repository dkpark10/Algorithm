# 프로그래머스 징검다리 LV4

## 문제

[https://programmers.co.kr/learn/courses/30/lessons/43236](https://programmers.co.kr/learn/courses/30/lessons/43236)

## 코드

```c++
int solution(int distance, vector<int> rocks, int n) 
{
    int answer = 1;
    sort(rocks.begin(), rocks.end());
    int left = 1, right = distance;
    while(left <= right){
        int mid = (right + left) / 2;
        int prev = 0;
        int cnt = n;
        
        for(int& rock: rocks){
            int gap = rock - prev;
            if(gap < mid) cnt--;
            else prev = rock;
        }
        
        if(cnt < 0) {
            right = mid - 1;
        }
        else{
            left = mid + 1;
            answer = mid;
        }
    }
    return answer;
}
```

## 풀이

이분탐색으로 n개의 돌을 제거할 때 mid 거리만큼의 격차가 벌어지는지 확인하는 문제 
