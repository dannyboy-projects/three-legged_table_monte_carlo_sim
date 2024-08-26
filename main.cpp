#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
const float  PI =3.14159265358979;

float gen_rand_no(float lb, float ub){
return lb + (float) rand() / ( (float) (RAND_MAX/(ub - lb)) );
}

float sArea(float a_x, float a_y, float b_x,float b_y, float c_x, float c_y){
    return 0.5*(a_x*(b_y - c_y) - a_y*(b_x - c_x) + (b_x*c_y - c_x*b_y));
}

float get_x(float r, float theta){
    return r*cos(theta);
}
float get_y(float r, float theta){
    return r*sin(theta);
}

int check_if_stands(float p[], int table){
    float r1,t1,r2,t2,r3,t3;
    float sTotalArea, sP23, s1P3, s12P;
    int res;

    r1 = p[table];
    t1 = p[table+1];

    r2 = p[table+2];
    t2 = p[table+3];

    r3 = p[table+4];
    t3 = p[table+5];
    cout << r1 << "," << t1 << "::" << r2<< ","<< t2 << "::" << r3 << "," << t3 << endl;
    cout << get_x(r1,t1) << "," << get_y(r1,t1) << "::" << get_x(r2,t2) << "," << get_y(r2,t2) << "::" << get_x(r3,t3) << "," << get_y(r3,t3) << endl;

    sTotalArea = sArea(get_x(r1,t1),get_y(r1,t1),get_x(r2,t2),get_y(r2,t2),get_x(r3,t3),get_y(r3,t3));
    sP23 = sArea(0.0,0.0,get_x(r2,t2),get_y(r2,t2),get_x(r3,t3),get_y(r3,t3));
    s1P3 = sArea(get_x(r1,t1),get_y(r1,t1),0.0,0.0,get_x(r3,t3),get_y(r3,t3));
    s12P = sArea(get_x(r1,t1),get_y(r1,t1),get_x(r2,t2),get_y(r2,t2),0.0,0.0);

    cout << sTotalArea << ":: "<< sP23 << ":: "<< s1P3 << ":: " << s12P << endl;
    
    if (sP23/sTotalArea < 0.0){
        res = 0;
    }
    else if(s1P3/sTotalArea < 0.0){
        res = 0;
    }
    else if(s12P/sTotalArea < 0.0){
        res = 0;
    }
    else{
        res = 1;
    }

    return res;
}

int main(){
    int no_tables = 1000;
    int no_points = 3*no_tables;
    int no_can_stand = 0;
    
    float coords[2*no_points]; // r, theta for unit circle case, flat array (r,theta)i -> (2*i,2*i+1)

    float r_lb = 0.;
    float r_ub = 1.;

    float theta_lb = 0;
    float theta_ub = 2.*PI;

    srand(time(0)); // initial random seed

    for(int i=0; i<no_points; i++){
        coords[2*i]   = gen_rand_no(r_lb,r_ub);
        coords[2*i+1] = gen_rand_no(theta_lb, theta_ub);
        cout << coords[2*i] << ","<<coords[2*i+1]<< endl;
    }

    for(int i = 0; i < no_tables; i=i+6){
        no_can_stand += check_if_stands(coords,i);
        cout << no_can_stand << "," << i << endl;
    }

    cout <<  no_can_stand<< "/" << no_tables << endl;
    
    return 0;
}