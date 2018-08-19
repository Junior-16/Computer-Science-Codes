#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> pieces1;
vector<int> pieces2;
string bigNum1;
string bigNum2;

void print(){
    for (unsigned int i = 0; i < pieces1.size(); i++){
        cout << pieces1.at(i) << " ";
    }
    cout << endl;
    for (unsigned int i = 0; i < pieces2.size(); i++){
        cout << pieces2.at(i) << " ";
    }
    cout << endl;

}

void sum(){
    vector<int> output;


}

void cut(){
    char buffer1[9] = {'0','0','0','0','0','0','0','0', '\0'};
    char buffer2[9] = {'0','0','0','0','0','0','0','0', '\0'};
    int index1 = bigNum1.size() -1;
    int index2 = bigNum2.size() -1;
    int biggest = (index1 >= index2 ? index1 : index2);
    int bufferIndex = 7;

    for (unsigned int i = 0; i <= biggest; i++){
        try{
            buffer1[bufferIndex] = bigNum1.at(index1);
        }catch(const out_of_range& error1){
            buffer1[bufferIndex] = '0';
        }

        try{
            buffer2[bufferIndex] = bigNum2.at(index2);
        }catch(const out_of_range& error2){
            buffer2[bufferIndex] = '0';
        }

        if (bufferIndex == 0 | i == biggest){
            pieces1.push_back(stoi(buffer1));
            pieces2.push_back(stoi(buffer2));
            memset(buffer1, '0', 8);
            memset(buffer2, '0', 8);
            bufferIndex = 8;
        }
        bufferIndex--;
        index1--;
        index2--;
    }

}

int main(){

    cin >> bigNum1;
    cin >> bigNum2;

    cut();
    print();

    return 0;
}
