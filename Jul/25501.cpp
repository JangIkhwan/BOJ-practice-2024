/*
printf 함수에서 인자의 호출 순서가 정해져 있지 않다. 그러므로 printf에서 함수호출을 하지 말고 호출이 끝난 후에 값을 출력하자. 
*/
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int T;
    vector<pair<int, int>> result;
    string s;
    
    cin >> T;
    for(int i = 0; i <T; i++){
        cin >> s;
        bool isPalindrom = true;
        int recursionCount = 0;
        for(int i = 0; i < s.length() / 2; i++){
            recursionCount += 1;
            if(s[0 + i] != s[s.length() - 1 - i]){
                isPalindrom = false;
                break;
            }
        }
        if(isPalindrom){
            result.push_back({1, recursionCount + 1});
        }
        else{
            result.push_back({0, recursionCount});
        }
    }
    for(int i = 0; i < T; i++){
        cout << result[i].first << " " << result[i].second << "\n";
    }
    return 0;
}