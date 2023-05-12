#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    //절대적 최대 횟수는 n/m이다.
    //의미적 최대 횟수는 section의 (최대 - 최소)/m
    //최소에서 한번 덧칠하면 다음 번 덧칠은 현재 칠한 번호 + m번 이후에 하는게 적합하다.
    //1번구역부터 존재한다.
    //0~1 (1번)
    int next_section_number = 1;
    for(const auto& void_section: section)
    {
        if(void_section < next_section_number)//이미 칠해진 구간
        {
            continue;
        }
        next_section_number = void_section + m;
        answer++;
        if(next_section_number > n)//이미 다 칠햇을경우
        {
            break;
        }
    }
    return answer;
}



int main(int argc, char* argv[])
{
    int n = 8;
    int m = 4;
    vector<int> section = {2,3,6};
    auto result = solution(n,m,section);

    cout<<result;
    return 0;
}
