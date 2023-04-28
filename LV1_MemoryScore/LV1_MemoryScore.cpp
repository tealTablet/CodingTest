#include <string>
#include <vector>
#include <unordered_map>

/**
* 사진들을 보며 추억에 젖어 있던 루는 사진별로 추억 점수를 매길려고 합니다.
* 사진 속에 나오는 인물의 그리움 점수를 모두 합산한 값이 해당 사진의 추억 점수가 됩니다.
* 예를 들어 사진 속 인물의 이름이 ["may", "kein", "kain"]이고 각 인물의 그리움 점수가 [5점, 10점, 1점]일 때
* 해당 사진의 추억 점수는 16(5 + 10 + 1)점이 됩니다.
* 다른 사진 속 인물의 이름이 ["kali", "mari", "don", "tony"]이고
* ["kali", "mari", "don"]의 그리움 점수가 각각 [11점, 1점, 55점]]이고,
* "tony"는 그리움 점수가 없을 때, 이 사진의 추억 점수는 3명의 그리움 점수를 합한 67(11 + 1 + 55)점입니다.
* 그리워하는 사람의 이름을 담은 문자열 배열 name,
* 각 사람별 그리움 점수를 담은 정수 배열 yearning,
* 각 사진에 찍힌 인물의 이름을 담은 이차원 문자열 배열 photo가 매개변수로 주어질 때,
* 사진들의 추억 점수를 photo에 주어진 순서대로 배열에 담아 return하는 solution 함수를 완성해주세요.
 */

using namespace std;

vector<int> solution(vector<string> names, vector<int> yearnings, vector<vector<string>> photos)
{
    vector<int> answer;
    unordered_map<string,int> peopleMemoryScore;
    for(int i = 0; i < names.size(); i++)
    {
        peopleMemoryScore.insert(make_pair(names[i],yearnings[i]));
    }
    
    for(auto& photo : photos)
    {
        int score = 0;
        for(auto& people : photo)
        {
            auto iterFind = peopleMemoryScore.find(people);
            if(iterFind != peopleMemoryScore.end())
            {
                score += iterFind->second;
            }
        }
        answer.push_back(score);
    }
    return answer;
}

int main(int argc, char* argv[])
{
    vector<string> names = {"may", "kein", "kain", "radi"};
    vector<int> yearnings = {5, 10, 1, 3};
    vector<vector<string>> photos = {{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}};
    vector<int> results = solution(names, yearnings,photos);
    //Output [19, 15, 6]
    return 0;
}


/**
 * LV1을 2개 풀어본결과 코테 알고리즘은 주어진 데이터를
 * 처리할 문제에 알맞은 자료구조형태로 변환후
 * 로직을 처리하는 방법으로 생각하는 방식으로 푸는 것같다.
 * 며칠 더 풀어보고 LV2로 넘어가야겟다.
 *
 * 그리고 대부분 Map의 insert(std::make_pair(key,value)) 이 함수는 안 쓰는거 같다.
 * 주어지는 자료가 중복되는게 아니라서 그런거 같기도 하다.
*/