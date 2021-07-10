# 프로그래머스 레벨3 추석트래픽

## 문제

이번 추석에도 시스템 장애가 없는 명절을 보내고 싶은 어피치는 서버를 증설해야 할지 고민이다.</br> 
장애 대비용 서버 증설 여부를 결정하기 위해 작년 추석 기간인 9월 15일 로그 데이터를 분석한 후 초당 </br>
최대 처리량을 계산해보기로 했다. 초당 최대 처리량은 요청의 응답 완료 여부에 관계없이 임의 시간부터 1초(=1,000밀리초)간 처리하는 요청의 최대 개수를 의미한다.</br>
</br>

## 입력 형식
solution 함수에 전달되는 lines 배열은 N(1 ≦ N ≦ 2,000)개의 로그 문자열로 되어 있으며, </br>
각 로그 문자열마다 요청에 대한 응답완료시간 S와 처리시간 T가 공백으로 구분되어 있다.</br>
응답완료시간 S는 작년 추석인 2016년 9월 15일만 포함하여 고정 길이 2016-09-15 hh:mm:ss.sss 형식으로 되어 있다.</br>
처리시간 T는 0.1s, 0.312s, 2s 와 같이 최대 소수점 셋째 자리까지 기록하며 뒤에는 초 단위를 의미하는 s로 끝난다.</br>
예를 들어, 로그 문자열 2016-09-15 03:10:33.020 0.011s은 "2016년 9월 15일 오전 3시 10분 33.010초"부터</br>
"2016년 9월 15일 오전 3시 10분 33.020초"까지 "0.011초" 동안 처리된 요청을 의미한다. (처리시간은 시작시간과 끝시간을 포함)</br>
서버에는 타임아웃이 3초로 적용되어 있기 때문에 처리시간은 0.001 ≦ T ≦ 3.000이다.</br>
lines 배열은 응답완료시간 S를 기준으로 오름차순 정렬되어 있다.</br>

## 코드 
```javascript
let record = [];
function calcul(date, processed) {
  const d = date.split(':').map(ele => Number(ele));
  let h = d[0] * 3600;
  let m = d[1] * 60;
  let s = d[2];

  const outi = Number((h + m + s).toFixed(3));
  const inti = Number(((h + m + s) - Number(processed) + 0.001).toFixed(3));
  record.push({ begin: inti, end: outi });
}

function solution(lines) {
  let answer = 0;

  lines.map((element, index) => {
    const [_, date, processed] = element.slice(0, -1).split(" ");
    calcul(date, processed);
  });

  for (let i = 0; i < record.length; i++) {
    let cnt = 1;
    const fir = record[i];
    for (let j = i + 1; j < record.length; j++) {
      const sec = record[j];
      if(fir.begin + 1 >= sec.begin || fir.end + 1 > sec.begin){
        cnt++;
      }
    }
    answer = Math.max(answer, cnt);
  }
  return answer;
}

```

## 풀이

문자열 처리문제 + 탐욕문제이다.  </br>
문자열은 받아서 00:00:00 시부터 흐른 시간을 초단위로 환산해준다. </br>
시간을 파싱해서 나온 값을 배열에 담아주고 현재 처리로그부터 반복문을 돌아 계산해준다 </br>

> 현재 처리로그 시작시간 + 1초가 다음 로그 시작시간보다 크다면 count up!</br>
  현재 처리로그 끝시간 + 1초가 다음 로그 시작시간보다 크다면 count up!</br>
