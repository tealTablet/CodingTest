#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<vector<int>> colBoard; //세로로 정렬한 보드
    colBoard.resize(board[0].size()); //가로길이만큼 크기할당
    vector<int> basket;//바스켓

    for (int row = board.size() - 1; row >= 0; row--) //밑에서 부터
    {
        for (int col = 0; col < board[row].size(); col++)
        {
            if (board[row][col] != 0)
            {
                colBoard[col].push_back(board[row][col]);
            }
        }
    }

    for (const auto& grap : moves)
    {
        int grapCol = grap - 1;
        if (colBoard[grapCol].empty() == false) //해당 세로줄이 안비어 있다면
        {
            int catchCol = colBoard[grapCol].back();
            colBoard[grapCol].pop_back(); //세로줄에서 하나씩 꺼내서
            if (basket.size() > 0) //바스켓에 물건이 있다면
            {
                if (basket.back() == catchCol) //바스켓의 마지막이 잡은것과 같다면
                {
                    basket.pop_back(); //바스켓에서 꺼내기
                    answer += 2;//2개씩 제거하므로 2점추가!!
                }
                else //다르면 바스켓에 넣고 끝
                {
                    basket.push_back(catchCol);
                }
            }
            else
            {
                basket.push_back(catchCol);
            }
        }
    }
    return answer;
}

int main(int argc, char* argv[])
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    int result = solution(board, moves);
    cout << result; //output 4
    return 0;
}
/*
* 굳이 자료구조를 새로 생성할 필요가 없이, 있는 그대로에서 사용해도 되었던 문제.
* 이게 자료구조에 잡아먹힌상황이 아닐까?
*/