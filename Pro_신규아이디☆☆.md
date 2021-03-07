# 프로그래머스 신규아이디

## 문제

카카오에 입사한 신입 개발자 네오는 "카카오계정개발팀"에 배치되어, 카카오 서비스에 가입하는 </br>
유저들의 아이디를 생성하는 업무를 담당하게 되었습니다. "네오"에게 주어진 첫 업무는 새로 가입하는</br>
유저들이 카카오 아이디 규칙에 맞지 않는 아이디를 입력했을 때, 입력된 아이디와 유사하면서 </br>
규칙에 맞는 아이디를 추천해주는 프로그램을 개발하는 것입니다. 다음은 카카오 아이디의 규칙입니다.</br>
</br>
아이디의 길이는 3자 이상 15자 이하여야 합니다.</br>
아이디는 알파벳 소문자, 숫자, 빼기(-), 밑줄(), 마침표(.) 문자만 사용할 수 있습니다.</br>
단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.</br>
"네오"는 다음과 같이 7단계의 순차적인 처리 과정을 통해 신규 유저가 입력한 아이디가 카카오 아이디 규칙에 </br>
맞는 지 검사하고 규칙에 맞지 않은 경우 규칙에 맞는 새로운 아이디를 추천해 주려고 합니다.</br>
신규 유저가 입력한 아이디가 new_id 라고 한다면,</br>

> 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.</br>
  2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(), 마침표(.)를 제외한 모든 문자를 제거합니다.</br>
  3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.</br>
  4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.</br>
  5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.</br>
  6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.</br>
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.</br>
  7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.</br>

</br>
예를 들어, new_id 값이 "...!@BaT#*..y.abcdefghijklm" 라면, 위 7단계를 거치고 나면 new_id는 아래와 같이 변경됩니다.</br>
</br>
1단계 대문자 'B'와 'T'가 소문자 'b'와 't'로 바뀌었습니다.</br>
"...!@BaT#*..y.abcdefghijklm" → "...!@bat#*..y.abcdefghijklm"</br>
</br>
2단계 '!', '@', '#', '*' 문자가 제거되었습니다.</br>
"...!@bat#*..y.abcdefghijklm" → "...bat..y.abcdefghijklm"</br>
</br>
3단계 '...'와 '..' 가 '.'로 바뀌었습니다.</br>
"...bat..y.abcdefghijklm" → ".bat.y.abcdefghijklm"</br>
</br>
4단계 아이디의 처음에 위치한 '.'가 제거되었습니다.</br>
".bat.y.abcdefghijklm" → "bat.y.abcdefghijklm"</br>
</br>
5단계 아이디가 빈 문자열이 아니므로 변화가 없습니다.</br>
"bat.y.abcdefghijklm" → "bat.y.abcdefghijklm"</br>
</br>
6단계 아이디의 길이가 16자 이상이므로, 처음 15자를 제외한 나머지 문자들이 제거되었습니다.</br>
"bat.y.abcdefghijklm" → "bat.y.abcdefghi"</br>
</br>
7단계 아이디의 길이가 2자 이하가 아니므로 변화가 없습니다.</br>
"bat.y.abcdefghi" → "bat.y.abcdefghi"</br>
</br>
따라서 신규 유저가 입력한 new_id가 "...!@BaT#*..y.abcdefghijklm"일 때,</br>
네오의 프로그램이 추천하는 새로운 아이디는 "bat.y.abcdefghi" 입니다.</br>

```c++
string solution(string new_id) {

	string answer = "";
	int size = new_id.size();
	for (char& c : new_id)  c = tolower(c);
	for (char& c : new_id) {
		if (c == '.' || c == '-' || c == '_' || 
			c >= 97 && c <= 122 || c <= 57 && c>= 48) {
			answer += c;
		}
	}
	while (1) {
		int idx = answer.find("..");

		if (idx == string::npos) {
			break;
		}
		answer.replace(idx, 2, ".");
	}
	if (answer[0] == '.') answer = answer.substr(1);
	if (answer.size() && answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);

	if (answer.size() == 0) answer += 'a';

	if (answer.size() >= 16) {
		answer = answer.substr(0, 15);
		if (answer[14] == '.') {
			answer = answer.substr(0, 14);
		}
	}

	if (answer.size() <= 2) {
		while (answer.size() < 3) {
			answer += answer[answer.size() - 1];
		}
	}
	return answer;
}
```

## 풀이

그냥 구현하면 됨 **너무 많은 생각은 오히려 해가 된다.** </br>
그리고 다양한 문자열 라이브러리 숙지는 필수다. 직접 구현은 할 수 있지만... </br>

> 나의 실력을 너무 믿지 말것 이미 날고 기는 개발자가 개발한 라이브러리나 함수를 적극 숙지 및 사용하기



