#include <iostream>

/**
 * 1 R or T
 * 2 C or F
 * 3 J or M
 * 4 A or N
 *
 * 검사지엔 n개 질문
 * 답변은 -3 -2 -1 0 1 2 3 까지
 */
#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> score;
    
    for(int i = 0; i < survey.size(); i++)
    {
        switch (choices[i])
        {
        case 1:
            score[survey[i][0]] += 3;
            break;
        case 2:
            score[survey[i][0]] += 2;
            break;
        case 3:
            score[survey[i][0]] += 1;
            break;
        case 4:
            break;
        case 5:
            score[survey[i][1]] += 1;
            break;
        case 6:
            score[survey[i][1]] += 2;
            break;
        case 7:
            score[survey[i][1]] += 3;
            break;
        }
    }

    if(score['R'] >= score['T'])
    {
        answer+='R';
    }
    else
    {
        answer+='T';
    }
    if(score['C'] >= score['F'])
    {
        answer+='C';
    }
    else
    {
        answer+='F';
    }
    if(score['J'] >= score['M'])
    {
        answer+='J';
    }
    else
    {
        answer+='M';
    }
    if(score['A'] >= score['N'])
    {
        answer+='A';
    }
    else
    {
        answer+='N';
    }
    
    return answer;
}



int main(int argc, char* argv[])
{
    vector<string> survey ={"AN", "CF", "MJ", "RT", "NA"};
    vector<int> choices = {5, 3, 2, 7, 5};
    const auto result = solution(survey, choices);

    int count = 1;
    for(const auto& output : result)
    {
        if(count < result.size())
        {
            cout<< output;//<<",";
        }
        else
        {
            cout << output;
        }
        count++;
    }
    return 0;
}

/**
 * 어제 LV2를 풀어보니 부족한거같아서 LV1을 시간을 재서 풀어보는걸 좀 연습하고 해봐야겟다.
 * 10분정도 걸렸다.
 */