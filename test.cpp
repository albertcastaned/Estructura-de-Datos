#include <iostream>
#include "Timer.h"
using namespace std;

int main(){
    Timer time(1,59);
    time+=Timer(0,1);

    cout << time.toString();
    return 0;
}