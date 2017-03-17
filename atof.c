//
//  atof.c
//  program-structure
//
//  Created by Timothy Shull on 6/17/15.
//  Copyright (c) 2015 Timothy Shull. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

double userAtof(char s[]);

int main(int argc, const char * argv[])
{
    char testString[20];
    
    strcpy(testString, "98993489");
    
    double returnVal = userAtof(testString);
    
    double secondVal = atof(testString);
    
    printf("%f\n", returnVal);
    
    printf("%f\n", secondVal);
}

double userAtof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}