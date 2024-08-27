#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


#include "helpers.h"

using namespace std;
const float  PI =3.14159265358979;



int main(){
    int no_tables = 1000;
    int legs_per_table = 3;    
    float legs[6]; // [(r,theta), (r,theta), (r,theta)]

    int no_can_stand = 0;

    float r_lb = 0.;
    float r_ub = 1.;

    float theta_lb = 0;
    float theta_ub = 2.*PI;
//-----------------------------------------------

    srand(time(0)); // initial random seed

    for(int t=0; t< no_tables; t++){

        // gen table with 3 random legs 
        for(int i=0; i< legs_per_table; i++){
            legs[2*i]   = gen_rand_no(r_lb,r_ub);        // random sampling (r,theta) on disk
            legs[2*i+1] = gen_rand_no(theta_lb, theta_ub);
        }

        no_can_stand += check_if_stands(legs);

    }

    cout << "prob of table standing =" << endl;
    cout << 100 * (float) no_can_stand/ (float) no_tables << "%" <<  endl;
    
    return 0;
}