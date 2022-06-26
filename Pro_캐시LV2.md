# 프로그래머스 LV2 캐시

## 문제

[https://programmers.co.kr/learn/courses/30/lessons/17680](https://programmers.co.kr/learn/courses/30/lessons/17680)

## 코드

```python
def solution(cacheSize, cities):
  ans = 0
  cache = []
  for city in list(map(lambda ele: ele.lower(), cities)):
    if city in cache:
      ans += 1
      cache.remove(city)
      cache.append(city)
    else:
      ans += 5
      if len(cache) >= cacheSize and len(cache) > 0:
        cache.pop(0)
      cache.append(city)
      
  return len(cities) * 5 if cacheSize == 0 else ans
```

## 풀이

입력으로 다음과 같이 주어졌을 때 

5, [1,2,3,2]

1: [1]
2: [1,2]
3: [1,2,3]
4: [1,3,2]

위와 같이 저장되어야 한다.