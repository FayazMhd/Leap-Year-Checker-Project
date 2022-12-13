#include "../inc/leapyear.h"



//Author: Fayaz Mahmood
//Date: 18-10-22


int main()

{
    char user_input[MAX];
    int year;

    printf("Leap Checker! \n\n");                                               //Prints Leap Checker
    while(true) {
        printf("Please enter the year to check('N' to quit): ");
        fgets(user_input, MAX, stdin) ;


        year = atoi(user_input);                                                // if N then
        if(user_input[0] == 'N'){
            printf("Quitting.. \n\n");                                          // print Quitting then
            printf("THE LEAP YEARS PER CENTURY REPORT: \n\n" );                 // print report
            generate_table();                                                   // End
            break;
        }
        else if (year < 0 || isdigit(user_input[0]) == 0 ){                     // print if users input is lower than 0 OR check if user inputs letter
            printf("Sorry that input is invalid.. \n\n");
        }
        else if (check_leap_year(year)) {                                       // print if users input is a leap year
            printf("%d IS a leap year! \n\n", year);
        } else {
            printf("%d IS NOT a leap year! \n\n", year);                        // print if users input is not a leap year
        }

    }

    return 0;
}