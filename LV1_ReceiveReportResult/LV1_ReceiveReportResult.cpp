/**
 * 신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.
 * 각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
 * 신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
 * 한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
 * k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
 * 유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.
 * 다음은 전체 유저 목록이 ["muzi", "frodo", "apeach", "neo"]이고, k = 2(즉, 2번 이상 신고당하면 이용 정지)인 경우의 예시입니다.
 */
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//전체 아이디 리스트와
//신고 아이디 리스트와
//정지기준수
vector<int> solution(vector<string> id_list, vector<string> reports, int k)
{
    vector<int> answer;
    answer.resize(id_list.size());
    //각각의 유저와, 신고자의 셋
    unordered_map<string, int> nickname_ID;
    unordered_map<string, unordered_set<string>> reportArchive;
    unordered_set<string> trollerList;

    //신고자정보함 만들기
    for(const string& id : id_list)
    {
        reportArchive[id] = unordered_set<string>();
        nickname_ID[id] = nickname_ID.size();
    }

    //신고내용 등록하기
    for(const string& report : reports)
    {
        int sprt = report.find(" ");
        string reporter = report.substr(0,sprt);
        string troller = report.substr(sprt+1);

        reportArchive[troller].insert(reporter);
    }

    //신고수와 제제강도 비교하여 트롤러로 등록하기
    for(auto& report : reportArchive)
    {
        if(report.second.size() >= k)
        {
            trollerList.insert(report.first);
        }
    }

    //트롤러들을 신고한 리포터들 구해서 카운트 올리기
    for(const string& troller : trollerList)
    {
        for(const string& reporter : reportArchive[troller])
        {
            int uid = nickname_ID[reporter];
            int receiveCount = answer[uid];
            answer[uid]= receiveCount+1;
        }
    }
    
    return answer;
}







int main(int argc, char* argv[])
{
    vector<string> id_list={"muzi", "frodo", "apeach", "neo"};
    vector<string> report={"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k=2;

    auto result = solution(id_list,report,k);
    for(auto output:result)
    {
        cout<< output <<",";
    }
    
    return 0;
}

/**
 * #include <bits/stdc++.h> stl 하나하나 넣기 힘든데, 대부분 이거 사용하는 거같다.
 *
 * 잘 풀은 사람것을 보니 어차피 처리되는 문자열값이 아닌 번호값으로 자료구조를 변경해 처리하는 부분이 인상적이였다.
 */