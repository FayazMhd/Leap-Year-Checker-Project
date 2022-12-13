#include "../inc/leapyear.h"


// Created by Fayaz M. on 2022-10-18.
//
//Functions:

bool check_leap_year(int year) {

    if ( (year % 4 == 0) && (year % 100 != 0) ) {                                                               // if year is divisible by 4 AND if year is divisible by 100
        return true;                                                                                            // then return true
    }
    else if (year % 400 == 0) {                                                                                 // year is divisible by 400
        return true;                                                                                            // then return true
    }
    else {                                                                                                      // Or else return false
        return false;
    }
}

void print_table(bool table[][101]){                                                                            // prints leap year table
    int year;
    for (int j = 1; j < 22 ; j++) {                                                                             // runs for 21 centuries
        printf("Century #%d:     ", j);
        for (int i = 1; i < 101; i++) {                                                                         // runs for 100 years to check leap years in every century
            if (table[j][i] == true){
                switch (j) {
                    case 1:
                        printf("%d      ", i);                                                                  // checks if it is the first century and prints leap year values
                        break;
                    case 21:                                                                                    // checks the leap years for the 21st century as long as it is less than 2023 then prints
                        year = 100*(j-1)+i;
                        if (year < 2023){
                            printf("%d      ", year);
                        }
                        break;
                    default:                                                                                    // checks for leap years for all the remaining centuries and prints them
                        year = 100*(j-1)+i;
                        printf("%d      ", year);
                        break;
                }
            }
        }
        printf("\n");
    }
}

void generate_table(void){
    bool table[22][101] = {false};
    int i, year;
    for(i = 1; i < 22; i++){                                                                                    // runs for 21 centuries
        for (int j = 1; j < 101 ; j++) {                                                                        // runs for 100 years to check leap years in every century
            switch (i) {
                case 1:                                                                                         // check if the first century has leap years if yes then
                    if ( ((j % 4 == 0) && (j % 100 != 0) || (j % 400 == 0))) {
                        table[i][j] = true;                                                                     // append true at table location
                    }
                    break;
                default:
                    year = 100*(i-1)+j;                                                                         // checks for leap years for all the remaining centuries and prints them
                    if ( ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))) {
                        table[i][j] = true;
                    }
            }

        }
    }
    print_table(table);                                                                                         // calls print table function
}

