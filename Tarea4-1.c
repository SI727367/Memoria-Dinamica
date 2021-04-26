#include <stdio.h>
#define R 3
#define C 3
int max(int mat[][C]){
    int *pmat = (int *) mat;
    int i, j, maxi;
    maxi = *pmat;
    for(i = 0; i < 9; i++){
        if(*pmat > maxi){
            maxi = *pmat;
        }
        pmat++;
    }
    return maxi;
}
int main(){
    int mat[R][C] = { { 1, 2, 3}, { -1, 9, 0 }, {2, 4, -3 }};
    int m = max(mat);
    printf("%d", m);
    return 0;
}
