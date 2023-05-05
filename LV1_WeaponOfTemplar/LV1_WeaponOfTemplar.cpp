#include <string>
#include <vector>
#include <math.h>

using namespace std;

int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrtf(n); i++)
    {
        if (n % i == 0) 
        {
            if (n / i == i)
            {   
                cnt++;
            }
            else 
            {  
                cnt += 2;
            }  
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for(int i = 1; i<= number; i++)
    {
        int npower = countDivisors(i);
        if(npower > limit)
        {
            answer += power;
        }
        else
        {
            answer += npower;
        }
    }
    
    return answer;
}

int main(int argc, char* argv[])
{
    
    return 0;
}

/**
 * 약수 구하는 공식을 생각하지 못해서 시간초과
 * 제곱근이 중간 약수라는 사실을 알고 있자.
 */