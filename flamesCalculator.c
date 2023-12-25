#include<stdio.h>
#include<string.h>
#include<ctype.h>

char flamesCalculation(char name1[], char name2[], int length1, int length2);

int main() {
    char name1[100], name2[100];
    printf("Enter your name: ");
    scanf("%s", name1);
    printf("Enter your crush's name: ");
    scanf("%s", name2);
    printf("\n");

    int length1 = strlen(name1);
    int length2 = strlen(name2);

    char result = flamesCalculation(name1, name2, length1, length2);
    
    if(result=='f'){
        printf("Relationship status: Friendship\n");
        printf("“En Nanbane pol yaarum ille indha bhoomiyille” ");
    }

    if(result=='l'){
        printf("Relationship status: Love\n");
        printf("Love is a dagger. It's a weapon to be wielded far away or up close. You can see yourself in it. It's beautiful.\n Until it makes you bleed. But ultimately when you reach for it... It isn't real. Love is an imaginary dagger.");
    }
    if(result=='a'){
        printf("Relationship status: Attraction\n");
        printf("What you seek is not seeking you.");
    }
    if(result=='m'){
        printf("Relationship status: Marriage\n");
        printf("Congrats buddy \nSome random advice for you..Marriage is when two become one. The trouble starts when they try to decide which one.So better think twice ");
            
    }
    if(result=='e'){
        printf("Relationship status: Enemy\n");
        printf("Oh, the misery.... Everybody wants to be my enemy....\n Spare the sympathy... Everybody wants to be my enemy-y-y-y-y (Look out for yourself)");
    }
    if(result=='s'){
        printf("Relationship status: Siblings\n");
        printf("In search of gold, you got a diamond");
    }

    return 0;
}

char flamesCalculation(char name1[], char name2[], int length1, int length2) {
    char str1[length1];
    char str2[length2];
    int flag = 0;

    for (int i = 0; i < length1; i++) {
        str1[i] = tolower(name1[i]);
    }
    for (int j = 0; j < length2; j++) {
        str2[j] = tolower(name2[j]);
    }


    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            if (str1[i] == str2[j]) {
                flag += 2;
                str2[j] = '\0'; 
                break; 
            }
        }
    }

    char flames[] = {'f', 'l', 'a', 'm', 'e', 's'};
    char final[6];
    int max_size = 6, k = 0;

    int length = length1 + length2 - flag;

    int i = 0;
    while (max_size > 1) {
        i = (i + length - 1) % max_size;
        for (int j = i; j < max_size - 1; j++) {
            flames[j] = flames[j + 1];
        }
        flames[max_size - 1] = '\0';
        max_size--;
    }

    return flames[0];
}
