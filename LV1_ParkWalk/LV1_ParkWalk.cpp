#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
* 지나다니는 길을 'O', 장애물을 'X'로 나타낸 직사각형 격자 모양의 공원에서 로봇 강아지가 산책을 하려합니다.
* 산책은 로봇 강아지에 미리 입력된 명령에 따라 진행하며, 명령은 다음과 같은 형식으로 주어집니다.
* ["방향 거리", "방향 거리" … ]
* 예를 들어 "E 5"는 로봇 강아지가 현재 위치에서 동쪽으로 5칸 이동했다는 의미입니다. 로봇 강아지는 명령을 수행하기 전에 다음 두 가지를 먼저 확인합니다.
* 
* 주어진 방향으로 이동할 때 공원을 벗어나는지 확인합니다.
* 주어진 방향으로 이동 중 장애물을 만나는지 확인합니다.
* 
* 위 두 가지중 어느 하나라도 해당된다면, 로봇 강아지는 해당 명령을 무시하고 다음 명령을 수행합니다.
* 공원의 가로 길이가 W, 세로 길이가 H라고 할 때, 공원의 좌측 상단의 좌표는 (0, 0), 우측 하단의 좌표는 (H - 1, W - 1) 입니다.
* 공원을 나타내는 문자열 배열 park, 로봇 강아지가 수행할 명령이 담긴 문자열 배열 routes가 매개변수로 주어질 때,
* 로봇 강아지가 모든 명령을 수행 후 놓인 위치를 [세로 방향 좌표, 가로 방향 좌표] 순으로 배열에 담아 return 하도록 solution 함수를 완성해주세요.
 */

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    unordered_map<int, unordered_map<int, bool>> parkCoordMap;//Y, X
    int currentDogPositionX = 0;
    int currentDogPositionY = 0;
    int parkMaxX = 0;
    int parkMaxY = 0;
    
#pragma region //자료구조로 만들기
    for(auto& parkCoord : park)
    {
        parkMaxX = 0;
        for(auto& coord: parkCoord)
        {
            switch(coord)
            {
            case 'S':
                currentDogPositionY = parkMaxY;
                currentDogPositionX = parkMaxX;
                parkCoordMap[parkMaxY][parkMaxX] = true;
                break;
            case 'O':
                parkCoordMap[parkMaxY][parkMaxX] = true;
                break;
            case 'X':
                parkCoordMap[parkMaxY][parkMaxX] = false;
                break;
            }
            parkMaxX++;
        }
        parkMaxY++;
    }
    parkMaxY--;
    parkMaxX--;
#pragma endregion 
    
    for(auto& route : routes)
    {
        char opDir = route[0];
        int nLength = ((int)route[2] -48);
        
        int futureX, futureY;//미래좌표
        bool isValidPath = true;
        
        switch (opDir)
        {
        case 'N'://y-
            futureY = currentDogPositionY - nLength;
            if(parkMaxY >= futureY && futureY >= 0)//맵을 벗어나는 체크
            {
                for(int y = futureY; y < currentDogPositionY; y++)
                {
                    if(parkCoordMap[y][currentDogPositionX]==false)
                    {
                        isValidPath = false;
                        break;
                    }
                }
                if(isValidPath)
                {
                    currentDogPositionY = futureY;
                }
            }
            break;
        case 'W'://x-
            futureX= currentDogPositionX - nLength;
            if(parkMaxX >= futureX && futureX >= 0 )//맵을 벗어나는 체크
            {
                for(int x = futureX; x < currentDogPositionX; x++)
                {
                    if(parkCoordMap[currentDogPositionY][x]==false)
                    {
                        isValidPath = false;
                        break;
                    }
                }
                if(isValidPath)
                {
                    currentDogPositionX = futureX;
                }
            }
            break;
        case 'S'://y+
            futureY = currentDogPositionY + nLength;
            if(parkMaxY >= futureY && futureY >= 0)//맵을 벗어나는 체크
            {
                for(int y = futureY; y > currentDogPositionY; y--)
                {
                    if(parkCoordMap[y][currentDogPositionX]==false)
                    {
                        isValidPath = false;
                        break;
                    }
                }
                if(isValidPath)
                {
                    currentDogPositionY = futureY;
                }
            }
            break;
        case 'E'://x+
            futureX = currentDogPositionX + nLength;
            if(parkMaxX >= futureX && futureX >= 0 )//맵을 벗어나는 체크
            {
                for(int x = futureX; x > currentDogPositionX; x--)
                {
                    if(parkCoordMap[currentDogPositionY][x]==false)
                    {
                        isValidPath = false;
                        break;
                    }
                }
                if(isValidPath)
                {
                    currentDogPositionX = futureX;
                }
            }
            break;
        }
    }
    
    answer.push_back(currentDogPositionY);
    answer.push_back(currentDogPositionX);
    return answer;
}

int main(int argc, char* argv[])
{
    vector<string> park = {"XXX","XSX","XXX"};
    vector<string> routes ={"E 1"};

    vector<int> result = solution(park,routes);

    std::cout << result[0] << result[1];
    return 0;
}

/**
 * 해당문제는 테스트케이스는 모두 맞는데,
 * 아닌 테스트케이스를 벗어난 특수한 케이스를 알 수가 없어서
 * 이미 짜여진 로직에 잡하먹혀서 오래 걸렸다.
 *
 * 오래걸린 원인은 제자리를 검사하던 것이 문제엿다.
 * 반대로 미래의 위치부터 검사하게 하여 해결.
 * 다른사람의 풀이를 보니 기본적인 c 구조로도 잘짜는 거 같다.
 */