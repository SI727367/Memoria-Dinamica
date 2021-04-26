#include <stdio.h>
#include <math.h>
float f1(float x, float y, int t){
    int r = (4*x) - 2;
    int r2 =(4*y) - 2;
    if(t == 1){
        if( r2/r > 1.99 && r2/r < 2.01){
            return 1;
        }else{
            return 0;
        }
    }else{
        if( r2/r > 3.98 && r2/r < 4.02){
            return 1;
        }else{
            return 0;
        }
    }

}
float f2(float x, float y, int t){
    int r = ((3 * powf(x, 2)) - (2*x) + 4);
    int r2 = ((3 * powf(y, 2)) - (2*x) + 4);
    if(t == 1){
        if( r2/r > 1.99 && r2/r < 2.01){
            return 1;
        }else{
            return 0;
        }
    }else{
        if( r2/r > 3.98 && r2/r < 4.02){
            return 1;
        }else{
            return 0;
        }
    }
}
float f3(float x, float y, int t){
    int r = 6 * sqrtf(x) + 2;
    int r2 =6 * sqrtf(y) + 2;
    if(t == 1){
        if( r2/r > 1.99 && r2/r < 2.01){
            return 1;
        }else{
            return 0;
        }
    }else{
        if( r2/r > 3.98 && r2/r < 4.02){
            return 1;
        }else{
            return 0;
        }
    }
}
float islinear(float (* F2D) (float, float, int)){
    if(F2D(10000, 20000, 1)){
        return 1;
    }
    else{
        return 0;
    }

}

float isquadratic(float (* F2D)(float, float, int)){
    if(F2D(10000, 20000, 2)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    float (*funcs[])(float, float, int) = {f1, f2, f3};
    int i;
    for(i = 0; i < 3; i++){
        if(islinear(funcs[i])){
            printf("Es linear. ");
        }else{
            printf("No es linear. ");
        }
        if(isquadratic(funcs[i])){
            printf("Es cuadratica. ");
        }else{
            printf("No es cuadratica. ");
        }
        printf("\n");
    }
    return 0;
}
