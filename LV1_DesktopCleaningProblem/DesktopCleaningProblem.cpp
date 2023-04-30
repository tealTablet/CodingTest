#include <iostream>

/**
* 코딩테스트를 준비하는 머쓱이는 프로그래머스에서 문제를 풀고 나중에 다시 코드를 보면서 공부하려고 작성한 코드를 컴퓨터 바탕화면에 아무 위치에나 저장해 둡니다.
저장한 코드가 많아지면서 머쓱이는 본인의 컴퓨터 바탕화면이 너무 지저분하다고 생각했습니다. 
프로그래머스에서 작성했던 코드는 그 문제에 가서 다시 볼 수 있기 때문에 저장해 둔 파일들을 전부 삭제하기로 했습니다.
컴퓨터 바탕화면은 각 칸이 정사각형인 격자판입니다. 이때 컴퓨터 바탕화면의 상태를 나타낸 문자열 배열 wallpaper가 주어집니다. 
파일들은 바탕화면의 격자칸에 위치하고 바탕화면의 격자점들은 바탕화면의 가장 왼쪽 위를 (0, 0)으로 시작해 (세로 좌표, 가로 좌표)로 표현합니다. 
빈칸은 ".", 파일이 있는 칸은 "#"의 값을 가집니다. 드래그를 하면 파일들을 선택할 수 있고, 선택된 파일들을 삭제할 수 있습니다. 
머쓱이는 최소한의 이동거리를 갖는 한 번의 드래그로 모든 파일을 선택해서 한 번에 지우려고 하며 드래그로 파일들을 선택하는 방법은 다음과 같습니다.
* 머쓱이의 컴퓨터 바탕화면의 상태를 나타내는 문자열 배열 wallpaper가 매개변수로 주어질 때 
바탕화면의 파일들을 한 번에 삭제하기 위해 최소한의 이동거리를 갖는 드래그의 시작점과 끝점을 담은 정수 배열을 return하는 solution 함수를 작성해 주세요.
드래그의 시작점이 (lux, luy), 끝점이 (rdx, rdy)라면 정수 배열 [lux, luy, rdx, rdy]를 return하면 됩니다.
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    set<int> filePositionX;
    set<int> filePositionY;

    int line = 0;
    for (string& lineFile : wallpaper)
    {
        int foundFileX = lineFile.find('#');
        int foundFileRX = lineFile.rfind('#');
        if (foundFileX != string::npos)
        {
            filePositionX.insert(foundFileX);
            filePositionX.insert(foundFileRX);
            filePositionY.insert(line);
        }
        line++;
    }

    answer.push_back(*filePositionY.begin());
    answer.push_back(*filePositionX.begin());
    answer.push_back((*filePositionY.rbegin()) + 1);
    answer.push_back((*filePositionX.rbegin()) + 1);
    return answer;
}

int main(int argc, char* argv[])
{
    //vector<string> wallpaper = { ".#...", "..#..", "...#." };
    vector<string> wallpaper = { ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...." };
    vector<int> results = solution(wallpaper);

    int count = 1;
    for (int& output : results)
    {
        if (count < results.size())
        {
            cout << output << ",";
        }
        else
        {
            cout << output;
        }
        count++;
    }

    //Output[0, 1, 3, 4]
    return 0;
}

/**
* 문제에선 (x,y)를 구하라 했는데 실제로 요구하는 답은 (y,x)를 구하라고 해서 좀 그런게 있엇다.
* 
* 최소 최대만 구하는 것이 요구엿기 때문에 자동으로 minmax를 적용하여 노드를 만드는 셋을사용햇는데
* 다른 사람들을 보니 min max 사용해 푸는 방식으로 정보를 분류후 
* 저장하지 않고 즉시 저장하는 방법이 있엇다.
* 
* LV1은 이제 익숙해져서 내일부터는 LV 2에 도전해봐야겟다.
*/