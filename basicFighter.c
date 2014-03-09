#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


/* Function prototypes */
char *name(void);
int your_move(int opp_hp, int your_hp);
int opp1_move(int your_move, int opp_hp);
/*Function prototypes */



/* MAIN */
main()
{
    int opp_hp = 100, your_hp = 100;
    char *your_name;
    your_name = name();
    
    printf("Hello %s welcome to TD RPG!\nYou will fight 3 opponents and battle your way to the end of the game.\n\n", your_name);
    printf("You get a choice of 3 attacks and a defence, choose wisely!\n\n");
    
    printf("You have entered a battle with Enemy1\n\n");
    
    while (opp_hp > 0 && your_hp > 0)
    {
        opp_hp = your_move(opp_hp, your_hp);
        printf ("\nOpponents HP: %d\n", opp_hp);
        
        your_hp = opp1_move(your_hp, opp_hp);
        printf ("Your HP: %d\n", your_hp);
    }
    
    getch();
}


/* User enters name */
char *name(void)
{
    char *name; 
    
    name = "";
    
    puts ("Enter your name");
    gets (name);

    return(name);
}



/* Users move: user chooses attack and opp_hp is decremented */
int your_move(int opp_hp, int your_hp)
{
    int choice = 0;
    int atk1 = 10, atk2 = 20, atk3 = 2, heal = 10;
    
    
    do
    {
        printf ("1 - atk1\n2 - atk2\n3 - atk3\n4 - heal\n\n");
        
        scanf ("%d", &choice);
        
        switch (choice)
        {
            case 1:
            {
                puts("You punched for 10HP");
                opp_hp = opp_hp - atk1;
                return(opp_hp);
                break;
            }
            
            case 2:
            {
                puts("You kicked for 20HP");
                opp_hp = opp_hp - atk2;
                return(opp_hp);
                break;
            }
            
            case 3:
            {
                puts("You chose intimidate");
                opp_hp = opp_hp - atk3;
                return(opp_hp);
                break;
            }
            
            case 4:
            {
                puts("You healed for 10HP");
                your_hp = your_hp + heal;
                return(your_hp);
                break;
            }
            
            default:
            {
                puts("Invallid move!");
                choice = 5;
                break;
            }
        }
    }
    while (choice > 4);
    
}


/* Opponent1's moves are randomly generated using the srand function */
int opp1_move(int your_hp, int opp_hp)
{
    int choice = 0;
    int atk1 = 10, atk2 = 20, atk3 = 2, heal = 10;
    
    srand(time(NULL));
    
    choice = (rand() % 4 + 1);
    
    switch (choice)
    {
        case 1:
        {
            your_hp = your_hp - atk1;
            return(your_hp);
            break;
        }
            
        case 2:
        {
            your_hp = your_hp - atk2;
            return(your_hp);
            break;
        }
            
        case 3:
        {
            your_hp = your_hp - atk3;
            return(your_hp);
            break;
        }
            
        case 4:
        {
            opp_hp = opp_hp + heal;
            return(opp_hp);
            break;
        }
        
    }
    
    return(your_hp);
    
}
