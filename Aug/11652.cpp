#include <iostream>
#include <map>
using namespace std;

int main(void){
    map<long long, int> freq;
    int N;
    long long temp; // 입력 값 범위에 주의
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &temp);
        if(freq.find(temp) != freq.end())
            freq[temp]++;
        else 
            freq[temp] = 1;
    }

    long long answer = 0;
    int maxFreq = 0;
    for(auto iter = freq.begin(); iter != freq.end(); iter++){
        if(maxFreq < iter->second){
            answer = iter->first;
            maxFreq = iter->second;
        }
    }
    printf("%lld", answer);
    return 0;
}


/*
int main(void){
    map<long long, int> freq;
    int N;
    long long temp;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &temp);
        if(freq.find(temp) != freq.end())
            freq[temp] = 1;
        else 
            freq[temp]++;
    }

    long long answer = 0;
    int maxFreq = 0;
    for(auto iter = freq.begin(); iter != freq.end(); iter++){
        if(maxFreq < iter->second){
            answer = iter->first;
            maxFreq = iter->second;
        }
    }
    printf("%lld", answer);
    return 0;
}
*/