#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void){
	double alpha_in_deg, alpha_in_rad, z1, z2;
	
	printf("Input the alpha in degrees:");
	scanf("%lf", &alpha_in_deg);
	alpha_in_rad = alpha_in_deg * PI / 180;;
	
	z1 = cos(PI*3/8 - alpha_in_rad/4) * cos(PI*3/8 - alpha_in_rad/4) - cos(PI*11/8 + alpha_in_rad/4) * cos(PI*11/8 + alpha_in_rad/4);
	z2 = (sqrt(2)/2) * sin(alpha_in_rad/2);
	
	printf("z1 = %lf.3, z2 = %lf.3", z1, z2);
	
	return 0;
}