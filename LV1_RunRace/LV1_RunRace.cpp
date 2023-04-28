#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* 문제
*얀에서는 매년 달리기 경주가 열립니다. 해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다.
*예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때,
*해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다.
*즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.
*선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 players와 해설진이 부른 이름을 담은 문자열 배열 callings가 매개변수로 주어질 때,
*경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.
 */

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    //가장 쉽게는 벡터에서 순회로 찾고, 순서를 바꾸는 방법도 있겟지만,
    //만약 49999번째 선수를 계속 부른다면?
    //주어진 데이터를 처리하기위해 초기 데이터가공 처리하는 것은 나쁘지 않다.
    unordered_map<string, int> racingRunners;
    for(auto& player : players)
    {
        racingRunners.insert(std::make_pair(player, racingRunners.size()));
    }
    
    for(auto& caller: callings)
    {
       auto iterCalledRunner = racingRunners.find(caller);
       int rank = (iterCalledRunner->second);
        string loser = players[rank-1];
        string winner =  players[rank];

        players[rank-1] = winner;
        players[rank] = loser;

        racingRunners[loser] = rank;
        racingRunners[winner] = rank-1;
    }

    
    answer.assign(players.begin(),players.end());
    return answer;
}


int main(int argc, char* argv[])
{
    //Input
    vector<string> players = {"mumu", "soe", "poe", "kai", "mine"};
    vector<string> callings = {"kai", "kai", "mine", "mine"};
    vector<string> results = solution(players, callings);
    for(auto& result : results)
    {
        cout<<result;
    }
    //Output
    //["mumu", "kai", "mine", "soe", "poe"]
    return 0;
}




/**
 * 다른 풀이들을 보니 대부분 map을 사용하여 풀이를 하였다.
 *
 * 아쉬운점
 * 1. std::swap 사용안한 것.
 * 2. 처음부터 answer에 player대입하고 answer를 정렬해서 반환하면 됬던 것.
 */