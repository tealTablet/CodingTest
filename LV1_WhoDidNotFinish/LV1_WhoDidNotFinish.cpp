#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> participant_set;
    for(auto& runner :participant)
    {
        participant_set.insert(runner);
    }
    for(auto& completionRunner :completion)
    {
        auto it_find = participant_set.find(completionRunner) ;
        if(it_find == participant_set.end()) return completionRunner;
        participant_set.erase(it_find);
    }
    return *participant_set.begin();
}

int main(int argc, char* argv[])
{
    
    return 0;
}

/**
 * 알고리즘 주어지는 집합을 문자열순 정렬후 순서대로 비교하는 방법도 있었다.
 * unordered_map<string, int>을 사용방법도 있지만 더 간편한 방법을 선택했다.
 * 
 */