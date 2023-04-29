/**
* 고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있습니다.
* 약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다.
* 당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다.
* 수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.
예를 들어, A라는 약관의 유효기간이 12 달이고,
2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면 해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.
당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.
 */

#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//오늘날짜 YYYY.MM.DD
//약관의 유효기관 //"M P ..." 
//수집된개인정보//"YYYY.MM.DD M ..."
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> todayParse;
    unordered_map<string, int> termByPrivacyType;
    
    //오늘 날짜
    while (true)
    {
        int daySptr = today.find('.');
        todayParse.push_back(stoi(today.substr(0,daySptr)));
        daySptr = today.find('.');
        if(daySptr != string::npos)
        {
            today = today.substr(daySptr+1);
        }
        else
        {
            break;
        }
    }
    
    //개인정보유형별 유효기간
    for(auto& term : terms)
    {
        int sptr = term.find(' ');
        string privacyType = term.substr(0, sptr);
        string period = term.substr(sptr+1);
        termByPrivacyType[privacyType] = stoi(period); 
    }
    
    int id = 1;
    //개인정보별 분류
    for(auto& privacy : privacies)
    {
        int sptr = privacy.find(' ');
        string collectedDate = privacy.substr(0,sptr);
        string privacyType = privacy.substr(sptr+1);

        vector<int> privacyParse;
        while(true)
        {
            int dateSptr = collectedDate.find('.');
             privacyParse.push_back(stoi(collectedDate.substr(0,dateSptr)));
            
            dateSptr = collectedDate.find('.');
            if(dateSptr != string::npos)
            {
                collectedDate = collectedDate.substr(dateSptr+1);
            }
            else
            {
                break;
            }
        }

        //요 부분이 마음에 안듬.
        //오늘날짜 - 수집한기간 = 보유 기간
        int term =  (todayParse[0] - privacyParse[0]) * 12;
        term += todayParse[1] - privacyParse[1];
        int dayEvaluator =  todayParse[2] - privacyParse[2];
        if(dayEvaluator < 0)
        {
            term -= 1;
        }

        //보유기간 >= 타입별기간
        if(term >= termByPrivacyType[privacyType])
        {
            answer.push_back(id);
        }
        id++;
    }
    
    return answer;
}

int main(int argc, char* argv[])
{
    string today = "2022.05.19";
    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};
    auto result = solution(today,terms,privacies);

    int count = 1;
    for(int& output : result)
    {
        if(count < result.size())
        {
            cout<< output<<",";
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
 * 분류할 기준은 파싱한 내용으로 저장해놓고
 * 분류할 정보는 더 사용할 이유가 없다면 해당 스코프에서 가공해서 저장해도 된다.
 * 다만 깔끔한걸로 따지면 가공한 단위별로 자료구조를 가지는게 깔끔해 보이는 것 같다.
 *
 * 다른 사람 풀이
 * 1. 이미 구분선?이 정해진 정보라면 상수로 스트링을 잘라도 된다.
 * 2. 년월일짜를 일자로 만들어서 계산하면 편하다.
 * 3. 
 */