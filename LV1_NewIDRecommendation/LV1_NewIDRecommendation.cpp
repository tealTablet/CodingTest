#include <iostream>

/**
 * 3<= ID length <=15
 * 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표
 * 마침표는 처음과 끝에 사용불가, 연속사용불가
*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string new_id) {
    string answer = "";
    unordered_map<char, char> charMaps;
    string UpperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(const auto& A : UpperChars)
    {
        char lowerChar = (char)tolower(A);
        charMaps[A] = lowerChar;
        charMaps[lowerChar] = lowerChar;
    }
    string EnableChars = "01234567890_-.";
    for(const auto& A : EnableChars)
    {
        charMaps[A] = A;
    }

    //1번 2번 
    for(const auto& idChar : new_id)
    {
        if(charMaps.find(idChar) != charMaps.end())
        {
            char& result = charMaps[idChar];
            if(result != '\0')
            {
                answer += result;
            }
        }
    }
    //3번
    //for(answer)
    //반복되는 . 제거
    while(answer.find("..") != string::npos)
    {
        answer.replace(answer.find(".."),2,".");
    }
    //4번
    //처음과 끝.제거
    if (answer.front() == '.') {
        answer.erase(0, 1);
    }
    if (answer.back() == '.') {
        answer.pop_back();
    }
    //5번
    if(answer.empty())
    {
        answer = "a";
    }
    //6번
    //자리수 제한
    //처음과 끝.제거
    if(answer.size()>15)
    {
        answer=answer.substr(0,15);
        if(answer.back() == '.')
        {
            answer.pop_back();
        }
    }
    //7번
    while(answer.length() < 3)
    {
        answer += answer.back();
    }
    return answer;
}

int main(int argc, char* argv[])
{
    string new_id="123_.def";
    const auto result = solution(new_id);

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
 * regex를 배우면 좀더 편할까?
 * 이번 문제는 문자열처리의 여러가지 방법들을 할 수 있는지에 대한 문제였다. 
 * front, end, pop, push, 문자열 처리 함수.
 * STL 기본 함수들은 전부 능숙하게 알고 있어야 한다.
 */