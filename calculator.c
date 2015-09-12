#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* atof */
#include <unistd.h>

char *addmode = "add";
char *submode = "sub";
char *divmode = "div";
char *multmode = "mult";


double add( double x, double y)
{
	double output = x + y;
	return output;
}

double sub( double x, double y) 
{

	double output = x - y;
	return output;

}

double divv( double x, double y)
{
	double output = x / y;
	return output;
}

double mult( double x, double y)
{
	double output = x * y;
	return output;
}

// Process has done i out of n rounds,
// and we want a bar of width w and resolution r.
static inline void loadBar(int x, int n, int r, int w)
{
    // Only update r times.
    if ( x % (n/r +1) != 0 ) return;
 
    // Calculuate the ratio of complete-to-incomplete.
    float ratio = x/(float)n;
    int   c     = ratio * w;
 
    // Show the percentage complete.
    printf("%3d%% [", (int)(ratio*100) );
 
    // Show the load bar.
    for (int x=0; x<c; x++)
       printf("=");
 
    for (int x=c; x<w; x++)
       printf(" ");
 
    // ANSI Control codes to go back to the
    // previous line and clear it.
    printf("]\n\033[F\033[J");
}


main (int argc, char *argv[]) {
if ( argc < 4 ) // we have to take  3arg
 {
	printf("usage: ./test < add / sub / div / mult\n");
goto end;
 }
 
int x, n, r, w;

w = 50;
n = 10000;

for (int i=0; i<n; i++) {
loadBar(i, n, r, w);
}

if ( *argv[1] == *addmode ) { 
double a = atof(argv[2]);
double b = atof(argv[3]);
double sum = add(a,b);
printf("mode is : %s\n", argv[1]);
printf("a is : %G\n", a);
printf("b is : %G\n", b);
printf("the sum is : %G\n", sum);
return sum;
}

else if ( *argv[1] == *submode ) {

double a = atof(argv[2]);
double b = atof(argv[3]);
double subb = sub(a,b);
printf("the output is : %G\n", subb);
return subb;
}

else if (*argv[1] == *divmode ) {

double a = atof(argv[2]);
double b = atof(argv[3]);
double subb = divv(a,b);
printf("the output is : %G\n", subb);
return subb;
}

else if (*argv[1] == *multmode ) {

double a = atof(argv[2]);
double b = atof(argv[3]);
double subb = mult(a,b);
printf("the output is : %G\n", subb);
return subb;
}

else {

goto end;
}
end:
printf("wrong args!!! terminating\n");
}