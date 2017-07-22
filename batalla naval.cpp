#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include<time.h> // libreria para valores al azar con respecto al tiempo



void ColocarBarco(int,int,int,int,int,int,char[][10][10],char[][10],char);
void CampoCompleto(char[][10],char[][10]);

int main(int argc, char *argv[])
{
    char CampoJ[10][10],CampoPC[10][10];
    char Barcos[5][10][10],BarcosPC[5][10][10];
    int CoordX,CoordY,verificar=0,opc,largo,dibujo;
    
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
    
    printf("\nAHORA, TOCA COLOCAR LOS BARCOS:\n\n");
    for(int x=0;x<5;x++){
        
        if(x==0){
            printf("Patrullero (2 espacios):\n\n");
            largo=2;
            dibujo=15;
            
        }
        
        if(x==1){
            printf("Submarino (3 espacios):\n\n");
            largo=3;
            dibujo=35;
        }
       
        if(x==2){
            printf("Destructor(3 espacios):\n\n");
            largo=3;
            dibujo=64;
        }       
        
        if(x==3){
            printf("Acorazado(4 espacios):\n\n");
            largo=4;
            dibujo=177;
        }
        
        if(x==4){
            printf("Porta-aviones (5 espacios):\n\n");
            largo=5;
            dibujo=219;
        }
        
        
        ColocarBarco(x,verificar,CoordX,CoordY,largo,opc,Barcos,CampoJ,dibujo);
        CampoCompleto(CampoJ,CampoPC);
    
    }
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

void ColocarBarco(int Barco,int verificar,int CoordX,int CoordY,int largo,int opc, char Barcos[][10][10],char CampoJ[][10],char dibujo){
    
    
    int repetir=0,reiniciar;
    do{
        do{
            printf("primero, ingrese una coordenada de referencia:\n\n");
            verificar=0;
            do{
                printf("ingrese la coordenada en X:");
                scanf("%d",&CoordX);
            }while(CoordX<=0 || CoordX>10);
            do{
                printf("ingrese la coordenada en Y:");
                scanf("%d",&CoordY);
            }while(CoordY<=0 || CoordY>10);
            CoordY--;
            CoordX--;
            if(CampoJ[CoordY][CoordX]=='-'){
                Barcos[Barco][CoordY][CoordX]='X';
                CampoJ[CoordY][CoordX]=dibujo;
            }else if(CampoJ[CoordY][CoordX]!='-'){
                printf("Esta casilla ya tiene un barco.\n\n");
                verificar=1;
            }
            system("pause");
            system("cls");
        }while(verificar==1);
        verificar=0; 
        
        do{
            reiniciar=0;    
            do{
            repetir=0;
                printf("Selecccione hacia que direccion quiere el resto del barco:\n1.Arriba\n2.Derecha\n3.Abajo\n4.Izquierda\n5.Volver a colocar la posicion inicial\nR:");  
                scanf("%d",&opc);
            }while(opc<1 || opc>5);
            
            int colocar=1;
            if(opc==1){
                
                if(CoordY-largo>=0){
                    for(int x=1;x<largo;x++){
                        if(CampoJ[CoordY-x][CoordX]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            CampoJ[CoordY-x][CoordX]=dibujo;
                            Barcos[Barco][CoordY-x][CoordX]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordY-largo<0)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if(opc==2){
                
                if(CoordX+largo<10){
                    for(int x=1;x<largo;x++){
                        if(CampoJ[CoordY][CoordX+x]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            CampoJ[CoordY][CoordX+x]=dibujo;
                            Barcos[Barco][CoordY][CoordX+x]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordX+largo>=10)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if(opc==3){
                
                if(CoordY+largo<10){
                    for(int x=1;x<largo;x++){
                        if(CampoJ[CoordY+x][CoordX]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            CampoJ[CoordY+x][CoordX]=dibujo;
                            Barcos[Barco][CoordY+x][CoordX]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordY+largo>=10)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if(opc==4){
                
                if(CoordX-largo>=0){
                    for(int x=1;x<largo;x++){
                        if(CampoJ[CoordY][CoordX-x]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            CampoJ[CoordY][CoordX-x]=dibujo;
                            Barcos[Barco][CoordY][CoordX-x]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordX-largo<0)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if (opc==5){
                reiniciar=1;
                Barcos[Barco][CoordY][CoordX]='-';
                CampoJ[CoordY][CoordX]='-';
            }
        }while(repetir==1);
    }while(reiniciar==1);
} 
