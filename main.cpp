#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

float gen_rand_no(float lb, float ub){
return lb + (float) rand() / ( (float) (RAND_MAX/(ub - lb)) );
}



int main(){
    srand(time(0)); // initial random seed
    for (int i =0;i<100;i++){
        cout << gen_rand_no(0.1,.5) << endl;
    }
    
    return 0;
}