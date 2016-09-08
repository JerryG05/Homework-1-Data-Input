//
//  main.c
//  Homework 1: Data Input
//
//  Created by Gerardo Garcia on 9/7/16.
//  Copyright © 2016 Gerardo Garcia. All rights reserved.
//

#include <stdio.h>

int main(){
    
    // Prompt user to enter data file
    printf("Enter the name of the .txt file you would like to import ");
    char input[1000];
    scanf("%s", input);
    
    // Will check if user input is valid
    if((fopen(input,"r"))!=NULL){
        
        printf("The file you have chosen was found: %s\n\n", input);
        
        FILE *fp;
        int c;
        
        fp=fopen(input,"r");
        c = fgetc(fp);
        while (c!=EOF){
            printf("%c",c);
            c = fgetc(fp);
        }
    }else{
        printf("--------------------------------------------------------\n");
        printf("\t\t\tERROR: File was not found!\n\t\tDon't forget to add file extension\n");
        printf("\t\t\t\tPlease try again!\n");
        printf("--------------------------------------------------------\n");
        main();
    }
    
    
    return 0;
}
