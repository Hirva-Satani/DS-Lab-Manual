#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char str[20],newStr[20];
    printf("Enter a String:");
    scanf("%s",str);

    char *ptr=str;
    char *ptr1=newStr;

    for(int i=strlen(str)-1,j=0;i>=0;i--,j++){
        *(ptr1+j)=*(ptr+i);
    }

    *(ptr1+strlen(str))='\0';

    if(strcmp(ptr,ptr1)==0){
        printf("String is palindrome.");
    }
    else{
        printf("String is not palindrome.");
    }
}