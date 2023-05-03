
#include <iostream>

/***/
#include <string>
#include <vector>

using namespace std;

#define DISTANCE(x,y,a,b) (abs((x)-(a)))+abs(((y)-(b)))
string solution(vector<int> numbers, string hand) {
    string answer;
    answer.resize(numbers.size());
    int lineX_LH=1;
    int lineY_LH=4;
    int lineX_RH=3;
    int lineY_RH=4;
    for(int i = 0; i < numbers.size(); i++)
    {
        int distance_L = 0;
        int distance_R = 0;
        switch ( numbers[i])
        {
        case 1:
            lineX_LH = 1;
            lineY_LH = 1;
            answer[i] = 'L';
            break;
        case 4:
            lineX_LH = 1;
            lineY_LH = 2;
            answer[i] = 'L';
            break;
        case 7:
            lineX_LH = 1;
            lineY_LH = 3;
            answer[i] = 'L';
            break;
            
        case 3:
            lineX_RH = 3;
            lineY_RH = 1;
            answer[i] = 'R';
            break;
        case 6:
            lineX_RH = 3;
            lineY_RH = 2;
            answer[i] = 'R';
            break;
        case 9:
            lineX_RH = 3;
            lineY_RH = 3;
            answer[i] = 'R';
            break;
            
        case 2:
            distance_L = DISTANCE(lineX_LH,lineY_LH,2,1);
            distance_R = DISTANCE(lineX_RH,lineY_RH,2,1);
            if(distance_L == distance_R)
            {
                if(hand == "right")
                {
                    lineX_RH = 2;
                    lineY_RH = 1;
                    answer[i] = 'R';
                }
                else
                {
                    lineX_LH = 2;
                    lineY_LH = 1;
                    answer[i] = 'L';
                }
            }
            else if(distance_L>distance_R)
            {
                lineX_RH = 2;
                lineY_RH = 1;
                answer[i] = 'R';
            }
            else
            {
                lineX_LH = 2;
                lineY_LH = 1;
                answer[i] = 'L';
            }
            break;
        case 5:
            distance_L = DISTANCE(lineX_LH,lineY_LH,2,2);
            distance_R = DISTANCE(lineX_RH,lineY_RH,2,2);
            if(distance_L == distance_R)
            {
                if(hand == "right")
                {
                    lineX_RH = 2;
                    lineY_RH = 2;
                    answer[i] = 'R';
                }
                else
                {
                    lineX_LH = 2;
                    lineY_LH = 2;
                    answer[i] = 'L';
                }
            }
            else if(distance_L>distance_R)
            {
                lineX_RH = 2;
                lineY_RH = 2;
                answer[i] = 'R';
            }
            else
            {
                lineX_LH = 2;
                lineY_LH = 2;
                answer[i] = 'L';
            }
            break;
        case 8:
            distance_L = DISTANCE(lineX_LH,lineY_LH,2,3);
            distance_R = DISTANCE(lineX_RH,lineY_RH,2,3);
            if(distance_L == distance_R)
            {
                if(hand == "right")
                {
                    lineX_RH = 2;
                    lineY_RH = 3;
                    answer[i] = 'R';
                }
                else
                {
                    lineX_LH = 2;
                    lineY_LH = 3;
                    answer[i] = 'L';
                }
            }
            else if(distance_L>distance_R)
            {
                lineX_RH = 2;
                lineY_RH = 3;
                answer[i] = 'R';
            }
            else
            {
                lineX_LH = 2;
                lineY_LH = 3;
                answer[i] = 'L';
            }
            break;
        case 0:
            distance_L = DISTANCE(lineX_LH,lineY_LH,2,4);
            distance_R = DISTANCE(lineX_RH,lineY_RH,2,4);
            if(distance_L == distance_R)
            {
                if(hand == "right")
                {
                    lineX_RH = 2;
                    lineY_RH = 4;
                    answer[i] = 'R';
                }
                else
                {
                    lineX_LH = 2;
                    lineY_LH = 4;
                    answer[i] = 'L';
                }
            }
            else if(distance_L>distance_R)
            {
                lineX_RH = 2;
                lineY_RH = 4;
                answer[i] = 'R';
            }
            else
            {
                lineX_LH = 2;
                lineY_LH = 4;
                answer[i] = 'L';
            }
            break;
        default:
            break;
        }
    }
    return answer;
}

int main(int argc, char* argv[])
{
    
    vector<int> numbers={1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand="right";
    string result = solution(numbers,hand);
    //output ="LRLLLRLLRRL"
    cout<<result;
    
    return 0;
}

/**
 * 시간초과문제
 * 기존의 문제들은 따로 함수를 정의하지 않았엇는데
 * 이번 문제는 함수를 따로 정의해서 푸는 사람들이 보였다.
 * 함수를 굳이 정의하지 않을 필요가 없으니 함수를 정의해서 풀도록 해야겠다.
 *
 * pair의 사용도 눈에 많이 보였다.
 * 사실 좌표문제들은 X,Y를 짝지어서 푸는 경우가 많아서
 * 항상 클래스를 선언할지 고민을 많이하는 편인데, 간단히 페어를 사용하는 것도 좋아 보인다.
 * unordered_map<int,pair<int,int>> 이렇게 사용하면 좋게 느껴진다.
 */