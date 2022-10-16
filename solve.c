#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getRandChar(){
    return (char) ((rand() % 16) +70);
}
int main (int argc, char **argv) {


int i, n;
time_t t; 
char c[33]="";
char r0, r1, r2, r3;


for (int j =1655173080; j<1655173379; j++){   
	t = (time_t) j;
    int offset=0;
    srand((unsigned) t);
    r1 = getRandChar();
    r2 = getRandChar();
    r3 = getRandChar();
    r1 = getRandChar();
    r2 = getRandChar();
    r0 = r2  + 4;
    c[offset++] = r0;
    r2 = r3-5;
    c[offset++] = r1;
    r1 = 15;
    r3 = 13;
    c[offset++] = r2;
    r2 = r1 -r3;
    r1 = getRandChar();
    r3 = r1-r2;
    c[offset++] = r3;
    r2=getRandChar();
    c[offset++]=r2;
    r1=getRandChar();
    r1=getRandChar();
    r3 = 5;
    r2 = r1-r3;
    c[offset++]=r2;
    c[offset++]=r1;
    r3=getRandChar();
    r1=5;
    r2=r3+r1;
    r3=r2+0;
    c[offset++]=r3;
    r1 = getRandChar();
    r2 = getRandChar();
    r3 = getRandChar();
    r1 = getRandChar();
    r2 = getRandChar();
    r0 = r2  + 4;
    c[offset++] = r0;
    r2 = r3-5;
    c[offset++] = r1;
    r1 = 15;
    r3 = 13;
    c[offset++] = r2;
    r2 = r1 -r3;
    r1 = getRandChar();
    r3 = r1-r2;
    c[offset++] = r3;
    r2=getRandChar();
    c[offset++]=r2;
    r1=getRandChar();
    r1=getRandChar();
    r3 = 5;
    r2 = r1-r3;
    c[offset++]=r2;
    c[offset++]=r1;
    r3=getRandChar();
    r1=5;
    r2=r3+r1;
    r3=r2+0;
    c[offset++]=r3;

	
    printf("%s\n", c); 
}
   return(0);
}
