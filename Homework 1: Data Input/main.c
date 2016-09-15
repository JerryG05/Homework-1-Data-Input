//
//  main.c
//  Homework 1: Data Input
//
//  Created by Gerardo Garcia on 9/7/16.
//  Copyright © 2016 Gerardo Garcia. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <math.h>


void checkDiploma(FILE *fp, FILE *fptr){
    
    int c;
    
    do
        c = fgetc(fp);
    while (c != '\n');
    printf("\n--------------------------------------------------------\n");
    printf("\tBelow are the results of the students who \n"
           "\t\tgot a diploma and those who did not. \n");
    printf("--------------------------------------------------------\n");
    // prints to export file
    fprintf(fptr,"\n--------------------------------------------------------\n");
    fprintf(fptr,"\tBelow are the results of the students who \n"
           "\t\tgot a diploma and those who did not. \n");
    fprintf(fptr,"--------------------------------------------------------\n");
    
    char  studname[8];
    float  studno;
    float testOne;
    float testTwo;
    
    while(fscanf(fp, "%s %f %f %f ", studname,&studno,&testOne,&testTwo) != EOF) {
        
        if(testOne >= 50 && testTwo >=50){
            printf("%s: Student got a diploma\n", studname);
            // prints to export file
            fprintf(fptr,"%s: Student got a diploma\n", studname);

        }else{
            printf("%s: Student did not get a diploma\n",studname);
            // export file
            fprintf(fptr,"%s: Student did not get a diploma\n",studname);

        }
        
    }
    return;
}



void getData(FILE *fp,FILE *fptr){
    int c;
    
    // initailizes the extracted data
    char  studname[10];
    int  studno;
    float testOne;
    float testTwo;
    
    char name[15][10];
    int num[15];
    float subA[15];
    float subB[15];
    
    // create an array for sorting
    char nameSort[15][10];
    int numSort[15];
    float subASort[15];
    float subBSort[15];
    
    
    float total;
    float average;
    float total2;
    float average2;
    
    do
        c = fgetc(fp);
    while (c != '\n');
    printf("--------------------------------------------------------\n");
    printf("\tBelow are the average exam scores along with");
    printf("\n\t the standard divation of the exams.");
    printf("\n--------------------------------------------------------\n");
    // exports to file
    fprintf(fptr,"--------------------------------------------------------\n");
    fprintf(fptr,"\tBelow are the average exam scores along with");
    fprintf(fptr,"\n\t the standard divation of the exams.");
    fprintf(fptr,"\n--------------------------------------------------------\n");

    
    int i=0;
    while(fscanf(fp, "%s %d %f %f ", studname,&studno,&testOne,&testTwo) !=EOF){
        
        strcpy(name[i],studname);
        num[i]=studno;
        subA[i]=testOne;
        subB[i]=testTwo;
        
        // sorting array
        strcpy(nameSort[i],studname);
        numSort[i]=studno;
        subASort[i]=testOne;
        subBSort[i]=testTwo;
        i++;
        
        
    }
    
    int j;
    for(j=0;j<7;j++){
        // printf("%.2f\n",subA[j]);
    }
    // calculates the average of test scores
    total = subA[0] + subA[1] + subA[2] + subA[3] + subA[4] + subA[5] + subA[6];
    average = (total/7);
    
    
    // calculates the standard divation for subject A
    float mean = average;
    
    
    // diviation from mean
    float div1 = subA[0] - mean;
    float div2 = subA[1] - mean;
    float div3 = subA[2] - mean;
    float div4 = subA[3] - mean;
    float div5 = subA[4] - mean;
    float div6 = subA[5] - mean;
    float div7 = subA[6] - mean;
    
    // divations squared
    float div1Sqr = pow(div1,2);
    float div2Sqr = pow(div2,2);
    float div3Sqr = pow(div3,2);
    float div4Sqr = pow(div4,2);
    float div5Sqr = pow(div5,2);
    float div6Sqr = pow(div6,2);
    float div7Sqr = pow(div7,2);
    
    // summ all divations^2
    
    float sumDivSqr = div1Sqr + div2Sqr+ div3Sqr+ div4Sqr+ div5Sqr+ div6Sqr+ div7Sqr;
    
    // divide by n
    
    float subAtot = sumDivSqr/7;
    
    // find standard Divation by square rooting
    
    float stdDivSubA= sqrt(subAtot);
    
    // print std Diviation to console.
    printf("The standard divation for subject A is : %.2f", stdDivSubA);
    // pritns to export file
    fprintf(fptr,"The standard divation for subject A is : %.2f", stdDivSubA);
    
    printf("\nThe average for test subject A is: %.2f", average);
    // export to export file
    fprintf(fptr,"\nThe average for test subject A is: %.2f", average);
    // find the std divition
    
    // printf("\n--------------------------------------------------------\n");
    // gets values for test subject B
    int h;
    for(h=0;h<7;h++){
        //   printf("%.1f\n",subB[h]);
    }
    total2 = subB[0] + subB[1] + subB[2] + subB[3] + subB[4] + subB[5] + subB[6];
    average2 = (total2/7);
    
    // calculates the standard divation for subject B
    
    float meanB = average2;
    
    // diviation from mean
    float div1B = subB[0] - meanB;
    float div2B = subB[1] - meanB;
    float div3B = subB[2] - meanB;
    float div4B = subB[3] - meanB;
    float div5B = subB[4] - meanB;
    float div6B = subB[5] - meanB;
    float div7B = subB[6] - meanB;
    
    // divations squared
    float div1SqrB = pow(div1B,2);
    float div2SqrB = pow(div2B,2);
    float div3SqrB = pow(div3B,2);
    float div4SqrB = pow(div4B,2);
    float div5SqrB = pow(div5B,2);
    float div6SqrB = pow(div6B,2);
    float div7SqrB = pow(div7B,2);
    
    // summ all divations^2
    
    float sumDivSqrB = div1SqrB + div2SqrB+ div3SqrB + div4SqrB + div5SqrB + div6SqrB + div7SqrB;
    
    // divide by n
    
    float subBtotB = sumDivSqrB/7;
    
    // find standard Divation by square rooting
    
    float stdDivSubB= sqrt(subBtotB);
    
    // prints test subject B average.
    printf("\n\nThe average for test subject B is: %.2f", average2);
    // pritns to export file
    fprintf(fptr,"\n\nThe average for test subject B is: %.2f", average2);
    
    // print std Diviation to console.
    printf("\nThe standard divation for subject B is : %.2f", stdDivSubB);
    // pritns to export
    fprintf(fptr,"\nThe standard divation for subject B is : %.2f", stdDivSubB);

    
    
    printf("\n--------------------------------------------------------\n");

    fprintf(fptr,"\n--------------------------------------------------------\n");

    // sorting tool based on the subject A
   /*
    char nameSort[15][10];
    int numSort[15];
    float subASort[15];
    float subBSort[15];
    */
    
    printf("Program is sorting...\n");
    //print to export file
     fprintf(fptr,"\t\tProgram is sorting...\n");
    // sorting will create a
    int w, x, y, z = 7;
    
    for (w = 0; w < z; ++w){
        for (x = w + 1; x < z; ++x){
            if (subASort[w] > subASort[x]){
                y =  subASort[w];
                subASort[w] = subASort[x];
                subASort[x] = y;
            }
        }
    }
    printf("Below are the subject A exam scores in accednding order. \n");
    fprintf(fptr,"Below are the subject A exam scores in accednding order. \n");
    fprintf(fptr,"--------------------------------------------------------\n");
    for (w = 0; w < z; ++w)
        printf(" %.2f | ", subASort[w]);
    printf("\n");
    // print to export
    fprintf(fptr," %.2f | %.2f | %.2f | %.2f | %.2f | %.2f | %.2f | ", subASort[0],subASort[1],subASort[2],subASort[3], subASort[4],subASort[5],subASort[6]);
    fprintf(fptr,"\n");

}
    


int main(){
    
    // Prompt user to enter data file
    printf("Enter the name of the .txt file you would like to import ");
    char input[1000];
    scanf("%s", input);
    
    // Will check if user input is valid
    if((fopen(input,"r"))!=NULL){
        printf("--------------------------------------------------------\n");
        printf("The file you have chosen was found: %s\n\n", input);
        
    }else{
        printf("--------------------------------------------------------\n");
        printf("\t\t\tERROR: File was not found!\n\t\tDon't forget to add file extension\n");
        printf("\t\t\t\tPlease try again!\n");
        printf("--------------------------------------------------------\n");
        main();
    }
    // will open the file the user wants to analyize
    FILE *fp;
    FILE *fptr;
    int c;
    
    
    fp=fopen(input,"r");
    c = fgetc(fp);
    
    // ask user for file naming
    char output[15];
    printf("This program will export your results onto a .txt file. Please name the file: ");
    scanf("%s", output);
    strcat(output, ".txt");
    fptr = fopen(output, "w");
    fprintf(fptr,"\t\t\t%s\t\t\t", output);
    if(fptr == NULL){
        printf("Error the file was not exported!");
        exit(1);
    }
    
    
    while (c!=EOF){
        printf("%c",c);
        c = fgetc(fp);
    }
    fp=fopen(input,"r");
    checkDiploma(fp, fptr);
    
    
    fp=fopen(input,"r");
    getData(fp, fptr);
    
    printf("--------------------------------------------------------\n");
    printf("Your file was saved as %s in the current directory.\n", output);
    
    fclose(fptr);
    
    return 0;
}
