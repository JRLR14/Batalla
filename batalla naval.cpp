#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include<time.h>
using namespace std;

void CampoCompleto(char[][10],char[][10]);
int main(int argc, char *argv[])
{
    char CampoJ[10][10],CampoPC[10][10];
    char Barcos[5][10][10],BarcosPC[5][10][10];
    
    for(int z=0;z<5;z++){    
        for(int x=0;x<10;x++){
            for(int y=0;y<10;y++){
                Barcos[z][x][y]='-';
                BarcosPC[z][x][y]='-';
            }
        }
    }
    
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            CampoJ[x][y]='-';
            CampoPC[x][y]='-';
        }
    }

    CampoCompleto(CampoJ,CampoPC);
    
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



void CampoCompleto(char CampoJ[][10],char CampoPC[][10]){
    
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for(int x=0;x<10;x++){
        if(x!=9){
            printf("%d  ",x+1);
        }
        else{
            printf("%d ",x+1);
        }
        
        for(int y=0;y<10;y++){
            printf("%c ",CampoPC[x][y]);
        }
        printf("\n");
    }
    
    printf("-----------------------\n");
    
    for(int x=0;x<10;x++){
        if(x!=9){
            printf("%d  ",x+1);
        }
        else{
            printf("%d ",x+1);
        }
        
        for(int y=0;y<10;y++){
            printf("%c ",CampoJ[x][y]);
        }
        printf("\n");
    }
    
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    
    system("pause");
}
