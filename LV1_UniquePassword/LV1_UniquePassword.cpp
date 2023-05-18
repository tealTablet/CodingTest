#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<int, char> alpha_map;
    unordered_map<char, int> num_map;
    unordered_set<char> skip_set;
    for(char ch : skip){
        skip_set.insert(ch);
    }
    
    for(char ch :alphabet)
    {
        if(skip_set.count(ch) == 0)
        {
            alpha_map[alpha_map.size()+1] = ch;
            num_map[ch] = alpha_map.size();
        }
    }
    
    for(char ch : s)
    {
        int my_index = num_map[ch];//1~26
        int next_index = (my_index + index);//2~45
        int max_index = alpha_map.size();//16~25

        if(next_index > max_index)
        {
            next_index = (next_index % max_index);
            if(next_index == 0)
            {
                next_index = max_index;
            }
        }
        answer+=alpha_map[next_index];
    }
    return answer;
}


/**
s="z"
skip="abcdefghij"
index=20
정답 = n

입력값 〉 "zzzzzz", "abcdefghijklmnopqrstuvwxy", 6
기댓값 〉 "zzzzzz"

s= "ybcde"
skip = "az"
index =1
정답 : "bcdef"
 */

int main(int argc, char* argv[])
{
 ///auto result = solution("z","abcdefghij" ,20);
 auto result = solution("aukks", "wbqd", 5);
    return 0;
}
