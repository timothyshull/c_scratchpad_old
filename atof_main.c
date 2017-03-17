//
//  main.c
//  program-structure
//
//  Created by Timothy Shull on 6/17/15.
//  Copyright (c) 2015 Timothy Shull. All rights reserved.
//

#include <stdio.h>

int strindex(char str[], char t);

int main(int argc, const char * argv[])
{
    char testString[] = "fdsaklfd";
    int index;
    
    index = strindex(testString, 'd');
    
    printf("%d", index);
}

int strindex(char str[], char t)
{
    int i, j = 0, k = 0;
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == t) {
            j = i;
            k = 1;
        }
    }
    if (k == 1) {
        return j + 1;
    } else {
        return -1;
    }
}
