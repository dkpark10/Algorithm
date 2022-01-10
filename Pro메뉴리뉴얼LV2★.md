## 프로그래머스 메뉴리뉴얼 lv2

[https://programmers.co.kr/learn/courses/30/lessons/72411](https://programmers.co.kr/learn/courses/30/lessons/72411)

```python
from itertools import combinations, permutations
from collections import Counter

def solution(orders, course):
    answer = []
    for cnum in course:
        dict = {}
        comb = []
        for order in orders:
            comb += list(combinations(sorted(order), cnum))
        for c in comb:
            key = ''.join(c)
            if key in dict:
                dict[key] += 1
            else:
                dict[key] = 1

        for key in dict:
            if dict[key] == max([dict[key] for key in dict]):
                if dict[key] > 1:
                    answer.append(key)

    return sorted(answer)
```

조합을 사용하여 딕셔너리에 갯수를 카운팅 

딕셔너리 최대 값과 키값이 같다면 answer에 푸쉬

아 요즘 알고리즘 너무 못푸는데??
