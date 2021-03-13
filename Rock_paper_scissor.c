#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int GAME(char c, char u)
{
    if (c == u)
    {
        return -1;
    }
    if ((u = 'r') && (c = 'p'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if ((u = 's') && (c = 'r'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if (u = 'p') && (c = 's'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char compchr, userchr;
    char name[20];
    int comp, user;
    int random_no;
    int compscr = 0, userscr = 0;
    int n;
    char dict[] = {'r', 'p', 's'};
    printf("**********ROCK , PAPER AND SCISSOR*********\n");
    printf("**********Hope you enjoy this game**********\n");

    srand(time(NULL));
    printf("For how  many times you want to play game this game : ");
    scanf("%d", &n);

    printf("Hey player enter your name: ");
    scanf("%s", &name);
    printf("**********W E L C O M E %s **********\n", name);

    for (int i = 0; i < n; i++) //FOR LOOP STARTED
    {
        random_no = rand() % 3; // GENERATE RANDOM NUMBER.
        //TAKING USERS INPUT..
        printf("%s's turn>>>>>>>>\n", name);
        printf("Choose (1) for rock (2) for paper and (3) for scissor\n");
        scanf("%d", &user);
        userchr = dict[user - 1]; // CONVERTING INTERGER INTO CHARACTER
        printf("%s choose : %c \n", name, userchr);
        //COMPUTER'S INPUT..
        printf("computer's turn>>>>>> ");
        printf("Choose (1) for rock (2) for paper and (3) for scissor\n");
        comp = random_no + 1;
        compchr = dict[comp - 1]; // CONVERTING INTERGER INTO CHARACTER
        printf("computer choose : %c \n", compchr);

        if (GAME(compchr, userchr) == 1) //CALLING  FUNCTION.
        {
            printf("win\n");
            printf("you got 1 point\n");
            userscr += 1; // ADDING POINT TO USER
        }
        if (GAME(compchr, userchr) == -1)
        {
            printf("draw\n");
            printf("Both got 1 point\n");
            userscr += 1; // ADDING POINT TO USER
            compscr += 1; // ADDING POINT TO COMPUTER
        }
        if (GAME(compchr, userchr) == 0)
        {
            printf("loose\n");
            printf("computer got 1 point\n");
            compscr += 1; // ADDING POINT TO COMPUTER
        }
    } // END OF FOR LOOP ..

    if (compscr == userscr)
    {
        printf("computer score : %d\n", compscr);
        printf("%s's score : %d\n", name, userscr);
        printf("*****MATCH DRAW*****");
    }
    else if (compscr > userscr)
    {
        printf("computer score : %d\n", compscr);
        printf("%s's score : %d\n", name, userscr);
        printf("*****YOU LOOSE by %d points*****,compscr-userscr");
    }
    else
    {
        printf("computer score : %d\n", compscr);
        printf("%s's score : %d\n", name, userscr);
        printf("*****YOU WIN by %d points *****,userscr-compscr");
    }

    return 0;
}
