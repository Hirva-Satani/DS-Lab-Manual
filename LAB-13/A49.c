#include<stdio.h>
#include<stdlib.h>

void main(){
    int *iptr=(int *)malloc(sizeof(int));
    char *cptr=(char *)malloc(sizeof(char));
    float *fptr=(float *)malloc(sizeof(float));

    if(iptr!=NULL && cptr!=NULL && fptr!=NULL){

        printf("Enter Integer: ");
        scanf("%d",iptr);

        printf("Enter Character: ");
        scanf(" %c",cptr);

        printf("Enter Float: ");
        scanf("%f",fptr);

        printf("\nInteger: %d\n",*iptr);
        printf("Character: %c\n",*cptr);
        printf("Float: %f\n",*fptr);

        free(iptr);
        free(cptr);
        free(fptr);
    }
    else{
        printf("Memory allocation failed.");
    }
}