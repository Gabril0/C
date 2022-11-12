#include <stdio.h>
#include <string.h>

void bubblesort(char *OGstring,int size){
    char temp;
    int troca;
    do{
    troca = -1;
    for(int i = 0; i < size - 1; i++){
        if(OGstring[i]>OGstring[i+1]){
            temp = OGstring[i];
            OGstring[i] = OGstring[i+1];
            OGstring[i+1] = temp;
            troca = i;}
    }size--;
    }while(troca != -1);
    printf("%s", OGstring);
    
}

int main() {
    char string[100];
    strcpy(string,"fgacndhbvipqoelkxwzynm");
    bubblesort(&string,strlen(string));
    

    return 0;
}
