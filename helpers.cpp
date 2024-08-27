#include <cmath>



float gen_rand_no(float lb, float ub){
return lb + (float) rand() / ( (float) (RAND_MAX/(ub - lb)) );
}

float cart2bary_lamda1(float a_x, float a_y, float b_x,float b_y, float c_x, float c_y, float p_x, float p_y){
    return ((b_y - c_y)*(p_x-c_x) + (c_x - b_x)*(p_y - c_y))/((b_y - c_y)*(a_x - c_x) + (c_x - b_x)*(a_y - c_y));
}

float cart2bary_lamda2(float a_x, float a_y, float b_x,float b_y, float c_x, float c_y, float p_x, float p_y){
    return ((c_y - a_y)*(p_x - c_x) + (a_x - c_x)*(p_y - c_y))/((b_y - c_y)*(a_x - c_x) + (c_x - b_x)*(a_y - c_y));
}

float get_x(float r, float theta){
    return r*cos(theta);
}
float get_y(float r, float theta){
    return r*sin(theta);
}

int check_if_stands(float p[]){
    float r1,t1,r2,t2,r3,t3;
    float Lam1, Lam2, Lam3;
    int res = 0;

    r1 = p[0];
    t1 = p[1];

    r2 = p[2];
    t2 = p[3];

    r3 = p[4];
    t3 = p[5];
   
    Lam1 = cart2bary_lamda1(get_x(r1,t1),get_y(r1,t1),get_x(r2,t2),get_y(r2,t2),get_x(r3,t3),get_y(r3,t3),0.0,0.0);
    Lam2 = cart2bary_lamda2(get_x(r1,t1),get_y(r1,t1),get_x(r2,t2),get_y(r2,t2),get_x(r3,t3),get_y(r3,t3),0.0,0.0);
    Lam3 = 1. - Lam1 - Lam2;
    
    if (Lam1 < 0.0){
        res = 0;
    }
    else if(Lam2 < 0.0){
        res = 0;
    }
    else if(Lam3 < 0.0){
        res = 0;
    }
    else{
        res = 1;
    }
    return res;
}