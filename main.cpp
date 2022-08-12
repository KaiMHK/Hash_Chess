#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

map<pair<int,int>,pair<bool,bool>> mp;
bool player= false;

void display(int a,int b){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==1||i==3||j==1||j==3)cout<<"* ";

            else if(j==a&&i==b) {
                if(!player)cout << "X ";
                else cout<<"Y ";
                mp[{a,b}]= {true,player};
            }

            else{
                if(mp[{j,i}].first&&!mp[{j,i}].second){
                    cout << "X ";
                }
                else if(mp[{j,i}].first&&mp[{j,i}].second){
                    cout << "Y ";
                }
                else cout<<"  ";
            }
        }
        cout<<endl;
    }
}

int main() {
    display(-1,-1);

    for(int i=0;i<9;i++){
        int x=0,y=0;
        string input;
        if(!player)cout<<"player1 Plz Input(row col without space)"<<endl;
        else cout<<"player2 Plz Input(row col without space)"<<endl;
        cin>>input;
        y = input[0] - '0'-1;
        x = input[1] - '0'-1;
        display(2*x,2*y);

        if(player)player= false;
        else player= true;

    }
    return 0;
}
