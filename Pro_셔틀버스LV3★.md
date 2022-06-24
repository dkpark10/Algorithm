# 프로그래머서 LV3 셔틀버스

[https://programmers.co.kr/learn/courses/30/lessons/17678](https://programmers.co.kr/learn/courses/30/lessons/17678)

## 코드

```python
# 정수형으로 시간변환하는 함수
def transn(str):
  h,m = str.split(':')
  return int(h) * 3600 + int(m) * 60

# 시간 묹자열 반환함수
def transs(time):
  h = int(time / 3600)
  time -= h * 3600
  m = int(time / 60)
  if h < 10:
    h = '0' + str(h) 
  if m < 10:
    m = '0' + str(m) 
  return '{0}:{1}'.format(h,m)

def solution(n, t, m, timetable):
  sorttime = sorted(timetable)
  lastbus = transn('09:00') + ((n - 1)* t * 60)
  last, idx, full = 0,0, False

  for i in range(n):
    bus = transn('09:00') + (i * t * 60)  # 버스 출발시간
    cnt = 0                               # 버스탈 승차인원 변수
    for j in range(idx, len(sorttime)):
      wait = transn(sorttime[j])
      # 버스 초과인원 이거나 버스시간보다 대기시간이 더 늦을경우
      if bus < wait or cnt >= m:
        break

      idx += 1
      cnt += 1
      # 마지막 탄 사람 시간
      last = wait

    # 마지막 버스에서 인원 초과할 시
    if cnt >= m and i == n - 1:
      full = True

  # 버스 만석 아님
  if idx < m or full == False:
    return transs(lastbus)    
  # 만석이면 막차탄 놈보다 1분 빨리
  else:
    return transs(last -1)
```