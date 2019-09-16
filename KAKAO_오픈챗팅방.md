# 카카오 코딩테스트 오픈채팅방

## 문제
카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데,</br>
본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.</br>
신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이</br>
들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. </br>
채팅방에 누군가 들어오면 다음 메시지가 출력된다.</br>
</br>
> [닉네임]님이 들어왔습니다.</br>
</br>
채팅방에서 누군가 나가면 다음 메시지가 출력된다.</br>

</br>
> [닉네임]님이 나갔습니다.</br>
</br>

채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.</br>
채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.</br>
채팅방에서 닉네임을 변경한다.</br>
닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다.</br>
예를 들어, 채팅방에 Muzi와 Prodo라는 닉네임을 사용하는 사람이 순서대로</br>
들어오면 채팅방에는 다음과 같이 메시지가 출력된다.</br>
</br>
> Muzi님이 들어왔습니다.</br>
Prodo님이 들어왔습니다.</br>
</br>
채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.</br>
</br>

> Muzi님이 들어왔습니다.</br>
Prodo님이 들어왔습니다.</br>
Muzi님이 나갔습니다.</br>
</br>
Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에</br>
채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.</br>
</br>
> Prodo님이 들어왔습니다.</br>
Prodo님이 들어왔습니다.</br>
Prodo님이 나갔습니다.</br>
Prodo님이 들어왔습니다.</br>
</br>
채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 </br>
사용하는 사람이 두 명이 있다. 이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 </br>
닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.</br>

> Prodo님이 들어왔습니다.</br>
Ryan님이 들어왔습니다.</br>
Prodo님이 나갔습니다.</br>
Prodo님이 들어왔습니다.</br>
</br>
채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로</br>
주어질 때, 모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를</br>
문자열 배열 형태로 return 하도록 solution 함수를 완성하라.

## 입력
> "Enter uid1234 Muzi",</br>
"Enter uid4567 Prodo",</br>
"Leave uid1234",</br>
"Enter uid1234 Prodo",</br>
"Change uid4567 Ryan"

## 출력
> "Prodo님이 들어왔습니다.",</br>
"Ryan님이 들어왔습니다.", </br>
"Prodo님이 나갔습니다.", </br>
"Prodo님이 들어왔습니다."

```python
def solution(record):

    answer = []
    nickname = {}
    event = []

    for s in record:

        s = s.split(" ")
        temp = []

        if s[0][0] == 'E':
            temp.append("E")
            temp.append(s[1])
            nickname[s[1]] = s[2]
            event.append(temp)

        elif s[0][0] == 'L':
            temp.append("L")
            temp.append(s[1])
            event.append(temp)
        else:
            nickname[s[1]] = s[2]

    for e in event:
        if e[0] == 'E':
            answer.append(nickname[e[1]] + "님이 들어왔습니다.")
        else:
            answer.append(nickname[e[1]] + "님이 나갔습니다.")

    return answer
```

## 풀이
c로 푸니까 매우 어렵다 그래서 파이썬으로 풀어봤다 split함수 짱짱 </br>
뭐 물론 c에도 split 비스무리한게 있지만 ... </br>
record를 전부 돌면서 event와 uid를 넣어준다 </br>
enter와 change면 닉네임을 전부 nickname딕셔너리에 최신화 시켜준다 </br>
그리고 event를 돌면서 uid key값에 맞는 value를 넣어주면서 출력해주면 끝...

