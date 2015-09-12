#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* atof */
#include <unistd.h>
#include<stdbool.h>

// char addmode[3] = "add";
// char submode[3] = "sub";
// char divmode[3] = "div";
// char multmode[4] = "mult";
// char advanced[5] = "fancy";
// char normal[4] = "norm";

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

// printf("printing args :%s\n", argv[1]);
// printf("printing args :%s\n", argv[2]);
// printf("printing args :%s\n", argv[3]);
// printf("printing args :%s\n", argv[4]);

 
 if ( argc < 2 ) // we have to take  3arg
 {
	printf("usage: ./test < fancy||norm add / sub / div / mult >\n");
goto end;
 }
 
else if ( !strcmp(argv[1], "fancy")) {
    printf("advanced mode selected");
    goto move;
}

else if (!strcmp(argv[1], "norm")) {
    
    if (argc < 5) {
        	printf("usage: ./test < fancy||norm add / sub / div / mult >\n");
goto end;
    }
    else {
    goto move;
    }
}

else {
    printf("usage: ./test < fancy||norm add / sub / div / mult >\n");
goto end;
}

 move:
if ( !strcmp(argv[1], "fancy")) {
    
     //Variable used for reading the user input
    char option;
    //Variable used for controlling the while loop
    bool isRunning = true;
    double number1;
    double number2;
    double result;
     int x, n, r, w;
    while(isRunning==true)
    {
        //Clears the screen
        system("clear");        //For UNIX-based OSes

        //Clears the keyboard buffer
        fflush(stdin);
        //Outputs the options to console
        puts("\n[1]ADD"
             "\n[2]SUB"
             "\n[3]DIV"
             "\n[4]MULT"
             "\n.........."
             "\n[x]Exit");
        //Reads the user's option
        option = getchar();
        //Selects the course of action specified by the option
        switch(option)
        {
            case '1':
                     printf("Type in first number \n");
	                 scanf("%lf", &number1);
	                 printf("Type in second number \n");
	                 scanf("%lf", &number2);
	                 printf("first number %G\n", number1);
	                 printf("second number %G\n", number2);
                     w = 50;
                     n = 5000;
                    
                     for (int i=0; i<n; i++) {
                     loadBar(i, n, r, w);
                     }
	                 result = add(number1,number2);
	                 printf("Output is : %G\n", result);
	                 return result;
                     break;
            case '2':
                     printf("Type in first number \n");
	                 scanf("%lf", &number1);
	                 printf("Type in second number \n");
	                 scanf("%lf", &number2);
                     w = 50;
                     n = 5000;
                    
                     for (int i=0; i<n; i++) {
                     loadBar(i, n, r, w);
                     }
	 
	                 result = sub(number1,number2);
	                 printf("Output is : %G\n", result);
                     return result;
                     break;
            case '3':
                     printf("Type in first number \n");
	                 scanf("%lf", &number1);
	                 printf("Type in second number \n");
	                 scanf("%lf", &number2);
                     w = 50;
                     n = 5000;
                    
                     for (int i=0; i<n; i++) {
                     loadBar(i, n, r, w);
                     }
	 
                     result = divv(number1,number2);
	                 printf("Output is : %G\n", result);
                     return result;
                     break;
            case '4':
                     printf("Type in first number \n");
	                 scanf("%lf", &number1);
	                 printf("Type in second number \n");
	                 scanf("%lf", &number2);
	                 w = 50;
                     n = 5000;
                    
                     for (int i=0; i<n; i++) {
                     loadBar(i, n, r, w);
                     }
	                 result = mult(number1,number2);
	                 printf("Output is : %G\n", result);
                     return result;
                     break;
            //...
            case 'x':
                     //Exits the system
                     isRunning = false;
                     return 0;
            default :
                     //User enters wrong input
                     //TO DO CODE
                     break;
        }
    }
    return 0;
}

else {

// int x, n, r, w;

// w = 50;
// n = 10000;

// for (int i=0; i<n; i++) {
// loadBar(i, n, r, w);
// }

if ( !strcmp(argv[2], "add")) { 
double a = atof(argv[3]);
double b = atof(argv[4]);
double sum = add(a,b);
printf("mode is : %s\n", argv[1]);
printf("a is : %G\n", a);
printf("b is : %G\n", b);
printf("the sum is : %G\n", sum);
return sum;
}

else if ( !strcmp(argv[2], "sub")) {

double a = atof(argv[3]);
double b = atof(argv[4]);
double subb = sub(a,b);
printf("the output is : %G\n", subb);
return subb;
}

else if (!strcmp(argv[2], "div")) {

double a = atof(argv[3]);
double b = atof(argv[4]);
double subb = divv(a,b);
printf("the output is : %G\n", subb);
return subb;
}

else if (!strcmp(argv[2], "mult")) {

double a = atof(argv[3]);
double b = atof(argv[4]);
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

}