#include<iostream>
#include<string>
using namespace std;

int main(){
    char letter[26][7][5];
    char s;
    string temp;
    
    int n, m, i, j, k, l, cnt = 0;
    for(i = 0; i < 26; i++){
        for(j = 0; j < 7; j++){
            for(k = 0; k < 5; k++){
                cin >> letter[i][j][k];
            }
        }
    }
    getchar();
    while(1){
        s = getchar();
        if(!(s >= 'A' && s <= 'Z')){
            if(temp.length()!=0){
                if(cnt != 0) cout << endl;
                else cnt = 1;
                
                for(j = 0; j < 7; j++){
                    for(k = 0; k < temp.length(); k++){
                        int u = temp[k] - 'A';
                        if(k != 0) cout << " ";
                        for(l = 0; l < 5; l++){
                            cout << letter[u][j][l];
                        }
                    }
                    cout << endl;
                }
            }
            temp.clear();
        }
        else temp.push_back(s);
        if(s == '\n') break;
    }
    return 0;
}
