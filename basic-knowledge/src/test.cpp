#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;


int main(int argc, char** argv){
    vector<int> a(10,5);

    for(int i:a){
        cout <<i<<typeid(i).name()<<endl;
    }

}