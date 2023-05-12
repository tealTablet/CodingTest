#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    bool result = true;
    //순서보장

    for(auto keyword : goal)
    {
        auto first_card = cards1.begin();
        auto second_card = cards2.begin();

        if((*first_card) == keyword)
        {
            cards1.erase(first_card);
        }
        else if((*second_card) == keyword)
        {
            cards2.erase(second_card);
        }
        else
        {
            result =false;
        }
    }
    if(result)
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }
    return answer;
}

int main(int argc, char* argv[])
{
    
    return 0;
}
