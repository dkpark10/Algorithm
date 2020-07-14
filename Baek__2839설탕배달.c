// 굉장히 쉬운 문제지만 오래걸렸다 ㅡㅡ 하나 고치면 하나 에러나오고 
// 10 이하의 설탕을 가져갈 경우의 수를 하나 하나 따지는데 엄청 힘들었다.
// 코드가 많이 더럽다 제어문이 많기 때문에 보기가 힘들다 코드를 줄일 수 있을듯

#include <stdio.h>
int SugarDelivery(int sugar)
{
    int result=0;
    int five,max;
    max=sugar;

    if (sugar % 5 == 0){ //5의 배수일 때
        result= sugar /5;
    }
    else if(sugar == 3) // 3일 때
        result = 1;
    else{

        five = sugar / 5; // 5킬로 봉지 수 
        sugar -= five * 5; // 5킬로로 담고 남은 설탕 양

        if(sugar == max) result = -1; // 5로 안나눠져 0인 경우 즉 0,1,2,3,4 
        else{
            while(1){
                if (sugar % 3 == 0){ // 5킬로봉지로 담고 남은 설탕양이 3의 배수인 경우
                    result = five + (sugar /3); // 다섯 봉지 수랑 3킬로봉지로 담은 수를 합친다
                    break;
                }
                else if (sugar == max && sugar % 3 !=0){ // 5킬로와 3킬로 봉지로 어떤 경우에도 담을 수 없는경우 즉 7kg 
                    result = -1;
                    break;
                }
                sugar += 5; // 남은 설탕양이 3의 배수로 안나눠질경우 계속 5킬로 더함 
                five--; // 5킬로 봉지는 하나 뺀다
            }
        }
    }
    return result;
}

int main(void)
{
    int sugar;
    scanf("%d", &sugar);
    printf("%d", SugarDelivery(sugar));

    return 0;
}
