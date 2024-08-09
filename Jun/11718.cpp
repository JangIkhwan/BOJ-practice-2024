#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(void){
    // char a;
    // while(scanf("%c", &a) == 1){
    //     printf("%c", a);
    // }

    string s;
    while(true){
        getline(cin, s);
        if(s == "") break;
        cout << s << "\n";
    }
    return 0;
}