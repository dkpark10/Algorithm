# 프로그래머스Lv2 이모티콘 할인행사

## 문제

[이모티콘 할인행사](https://school.programmers.co.kr/learn/courses/30/lessons/150368?language=python3)

## 코드

```python
from itertools import product

def discount(x):
  [percentage, price] = x
  return price * (100 - percentage) / 100

def solution(users, emoticons):
  answer = [0 ,0]
  temp = [0,0]
  discout = list(product([40, 30, 20, 10], repeat = len(emoticons)))

  for percentage in discout:
    discounted_price = list(map(discount, zip(percentage, emoticons)))
    # 답을 비교할 임시배열
    temp = [0, 0]

    for user in users:
      pluscnt = 0
      price = 0

      for (idx, dp) in enumerate(discounted_price):
        # 유저가 원하는 할인률 이상이면 이모티콘을 구입
        if percentage[idx] >= user[0]:
          price += dp
      
      # 가격을 초과하면 플러스 구독한다.
      if price >= user[1]:
        pluscnt += 1
        price = 0

      temp[0] += pluscnt;
      temp[1] += price

    # 플러스 가입자가 더많으면 답을 교체
    if temp[0] > answer[0]:
      answer = temp
    # 플러스 가입자가 동일하고 가격이 더 높으면 가격만을 교체
    elif temp[1] > answer[1] and temp[0] == answer[0]:
      answer[1] = temp[1]

  return answer
```

## 풀이

할인률은 0, 10, 20, 30, 40 이모티콘은 7개가 최대이므로 4^7로 완탐으로 해결 가능 시간복잡도는 다음과 같다.

```
5 ^ 7 * 100(유저수)
```

완탐으로 모든 할인 가격을 구한다 product함수로 중복이 허용된 조합(순서 상관 안함)을 사용하여 할인된 가격을 구한다.
유저는 할인된 이모티콘 가격을 순회하면서 구입할지 말지 여부를 정한다.

플러스 가입자가 우선순위가 높으므로 플러스 가입자가 높으면 답을 교체한다.
플러스 가입자가 동일하고 가격이 최대가 되면 가격만을 교체한다.