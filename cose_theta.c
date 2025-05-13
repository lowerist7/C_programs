#include<stdio.h>
#include <math.h>

int main(){
    double xy=15;
    double theta=0.00000001;
    double theta_radiance = theta * (M_PI/180.0);
    double xz,zy;
    zy = xy / cos(theta_radiance);
    xz = (zy*zy) - (xy*xy) ;

    if (fabs(cos(theta_radiance))< 1e-10) {
        printf("Error: Angle makes cosine near zero!\n");
        return 1;
    }
    printf("the height of the tree is %.2f\n",sqrt(xz));
    return 0;

}
