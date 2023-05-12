#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    unordered_map<char, int> keyboard_map;
    
  
    for(auto keys: keymap)
    {
        int key_num = 0;
        
        for(auto key :keys)
        {
            key_num++;
            auto it_find_key =  keyboard_map.find(key);
            if(it_find_key != keyboard_map.end())
            {
                if(it_find_key->second > key_num)
                {
                    keyboard_map[key] = key_num;
                }
            }
            else{
                keyboard_map[key] = key_num;
            }
        }
    }

    for(auto keys: targets)
    {
        int result = 0;
        for(auto key : keys)
        {
            auto it_find_key =  keyboard_map.find(key);
            if(it_find_key != keyboard_map.end())
            {
                if(result >= 0){
                    result += keyboard_map[key];
                }
            }
            else
            {
                result = -1;
            }
            
        }
        answer.push_back(result);
    }
    return answer;
}



int main(int argc, char* argv[])
{
    //cout<<
    return 0;
}
