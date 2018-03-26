#include<stdio.h>

int main()
{
    int a = 3;
    // make it bigger by 10
    a +=10;
    printf("%d\n", a);

    int b = 100;
    b -=7;
    // make it smaller by 7
    printf("%d\n", b);


    int c = 44;
    c *= c;
    // please double c's value
    printf("%d\n", c);


    int d = 125;
    d /= 5;
    // please divide by 5 d's value
    printf("%d\n", d);


    int e = 8;
    e = pow(e, 3);
    // please cube of e's value
    printf("%d\n", e);


    int f1 = 123;
    int f2 = 345;
    if (f1 > f2){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    // tell if f1 is bigger than f2 (print as a boolean)


    int g1 = 350;
    int g2 = 200;
    if  ((g2*2) > g1){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    // tell if the double of g2 is bigger than g1 (print as a boolean)

    int h = 1357988018575474;
    // tell if it has 11 as a divisor (print as a boolean)
    if  (h % 11 == 0){
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    if  (i1 > i2 * 2 && i1 < pow(i2, 3)){
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    if  (j % 3 == 0 && j % 5 == 0) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
/*
    char k[5] = "Apple";
    //fill the k variable with its cotnent 4 times
    printf(k[1]);
*/


    return 0;
}
