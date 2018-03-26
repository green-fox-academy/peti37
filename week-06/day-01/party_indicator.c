#include<stdio.h>

int main()
{
    int girls;
    int boys;

    printf("How many girls are coming?:\n");
    scanf("%d", &girls);
    printf("How many boys are coming?:\n");
    scanf("%d", &boys);

    if  (boys == girls && (boys+girls) > 20){
        printf("The party is excellent!");
    }
    else if (boys != girls && (boys+girls) > 20) {
        printf("Quite cool party!");
    }
    else if ((boys+girls) < 20 && girls > 0) {
        printf("Average party...");
    }
    else if (girls <= 0) {
        printf("Sausage party");
    }

    return 0;
}