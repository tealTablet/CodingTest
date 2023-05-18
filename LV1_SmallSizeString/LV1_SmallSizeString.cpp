#include <string>
#include <vector>

using namespace std;

/*
*숫자로 이루어진 문자열 t와 p가 주어질 때, t에서 p와 길이가 같은 부분문자열 중에서,
*이 부분문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수를 return하는 함수 solution을 완성하세요.
예를 들어, t="3141592"이고 p="271" 인 경우, t의 길이가 3인 부분 문자열은 314, 141, 415, 159, 592입니다.
이 문자열이 나타내는 수 중 271보다 작거나 같은 수는 141, 159 2개 입니다.
 * 
 */


// int solution(string t, string p) {
//     int answer = 0;
//
//     vector<int> split_string;
//     for(int i = 0; i <= (t.size()-p.size()); i++)
//     {
//         for(int j = 0; j < p.size(); j++)
//         {
//             string ts, ps;
//             ts = t[i+j];
//             ps = p[j];
//             int tn = stoi(ts);
//             int pn = stoi(ps);
//             
//             if(tn > pn)
//             {
//                 break;
//             }
//             else if(tn < pn)
//             {
//                 answer++;
//                 break;
//             }
//              
//             if(j+1 == p.size()&&(tn == pn)) answer++;
//         }
//     }
//     return answer;
// }
int solution(string t, string p) {
    int answer = 0;

    vector<int> split_string;
    for(int i = 0; i <= (t.size()-p.size()); i++)
    {
        for(int j = 0; j < p.size(); j++)
        {
            if(t[i+j] > p[j])
            {
                break;
            }
            else if(t[i+j] < p[j])
            {
                answer++;
                break;
            }
             
            if(j+1 == p.size()&&(t[i+j] == p[j])) answer++;
        }
    }
    return answer;
}

int main(int argc, char* argv[])
{
    string t = "500220839878";
    string p = "7";
    int result = solution(t, p);
    return 0;
}

//숫자 문자열은 하나 하나씩 비교할 수 있다.(변환하지 않아도 된다.)