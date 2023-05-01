/**
*준호는 요즘 디펜스 게임에 푹 빠져 있습니다. 디펜스 게임은 준호가 보유한 병사 n명으로 연속되는 적의 공격을 순서대로 막는 게임입니다. 디펜스 게임은 다음과 같은 규칙으로 진행됩니다.

준호는 처음에 병사 n명을 가지고 있습니다.
매 라운드마다 enemy[i]마리의 적이 등장합니다.
남은 병사 중 enemy[i]명 만큼 소모하여 enemy[i]마리의 적을 막을 수 있습니다.
예를 들어 남은 병사가 7명이고, 적의 수가 2마리인 경우, 현재 라운드를 막으면 7 - 2 = 5명의 병사가 남습니다.
남은 병사의 수보다 현재 라운드의 적의 수가 더 많으면 게임이 종료됩니다.
게임에는 무적권이라는 스킬이 있으며, 무적권을 사용하면 병사의 소모없이 한 라운드의 공격을 막을 수 있습니다.
무적권은 최대 k번 사용할 수 있습니다.
준호는 무적권을 적절한 시기에 사용하여 최대한 많은 라운드를 진행하고 싶습니다.

준호가 처음 가지고 있는 병사의 수 n, 사용 가능한 무적권의 횟수 k, 매 라운드마다 공격해오는 적의 수가 순서대로 담긴 정수 배열 enemy가 매개변수로 주어집니다.
준호가 몇 라운드까지 막을 수 있는지 return 하도록 solution 함수를 완성해주세요.
 */
#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;

    multiset<int> enemyWave;
    multiset<int> barrierWave;
    
    int enemyTotalCount = 0;
    for(const auto& enemyCount : enemy)//웨이브를 하나씩 꺼낸후
    {
        if(barrierWave.size() < k)//일단 무적권을 모두 사용한다.
        {
            barrierWave.insert(enemyCount);   
        }
        else//무적권을 다 사용했는데도 웨이브가 남아있다면
        {
            enemyWave.insert(enemyCount);
            
            int maxWEnemy = *enemyWave.rbegin();//이전 라운드의 최대 적수
            int minBEnemy = *barrierWave.begin();//무적권 사용의 최소 적수
            
            if(maxWEnemy > minBEnemy)//비교하고 교환
            {
                barrierWave.erase(barrierWave.lower_bound(minBEnemy));
                enemyWave.insert(minBEnemy);
                enemyWave.erase(enemyWave.lower_bound(maxWEnemy));
                barrierWave.insert(maxWEnemy);
                
                enemyTotalCount += minBEnemy;
            }
            else
            {
                enemyTotalCount += enemyCount;
            }
            
            //처리 총 적수
            if(n == enemyTotalCount)
            {
                break;
            }
            else if(n < enemyTotalCount)
            {
                enemyWave.erase(enemyWave.lower_bound(*enemyWave.rbegin()));
                break;
            }
        }
    }
    answer = enemyWave.size() + barrierWave.size();
    return answer;
}

int main(int argc, char* argv[])
{
    int n = 7;
    int k =3;
    vector<int> enemy = {5, 5, 5, 5, 2, 3, 1};
    int result = solution(n,k,enemy);

    cout<<result;
    return 0;
}

/**
 * 한문제에 20분씩 연습한다고 치면, LV2에 오고나서부터는 완전 실격수준의 속도를 보였다.
 * 푸는 방법에 대한 고민시간을 완전히 줄이고, 유형별로 습득하는 방법밖에 없을 것 같다.
 *
 * 그리고 테스트 케이스가 아닌 경우에 대한 문제를 어떻게 해결해야할지 모르겠다..
 * 예외처리에 대한 감을 어떻게 채워야 할까?
 * 
 * 무작정 푸는 것보다 공부하면서 풀어야 할텐데
 *
 * 동시성 Multi
 * 정렬을 Set
 * 인덱싱정렬을 Map
 * 빠른검색 USet
 * 빠른인덱싱 UMap
 * 순서보장 Vector
 */