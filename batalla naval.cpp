#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include<time.h>
using namespace std;


void ColocarBarco(int,int,int,int,int,int,char[][10][10],char[][10],char);
void CampoCompleto(char[][10],char[][10]);
void ColocarBarcoPC(int,int,int largo,char[][10][10],char[][10]);
int main(int argc, char *argv[])
{
    char CampoJ[10][10],CampoPC[10][10];
    char Barcos[5][10][10],BarcosPC[5][10][10];
    int CoordX,CoordY,verificar=0,opc,largo,dibujo;
    int vidas[5],vidasPC[5],acertar=0,ganar=0,perder=0;

    
    vidas[0]=2;
    vidasPC[0]=2;
    vidas[1]=3;
    vidasPC[1]=3;
    vidas[2]=3;
    vidasPC[2]=3;
    vidas[3]=4;
    vidasPC[3]=4;
    vidas[4]=5;
    vidasPC[4]=5;    
    
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
        ColocarBarcoPC(x,verificar,largo,BarcosPC,CampoPC);
        CampoCompleto(CampoJ,CampoPC);
    
    }
    
    system("pause");
    
    printf("Ahora, comencemos a jugar...\n");
    system("PAUSE");
    do{
        CampoCompleto(CampoJ,CampoPC);
        
        do{
            printf("Ingrese la coordenada en X para atacar:");
            scanf("%d",&CoordX);
        }while(CoordX<=0 || CoordX>10);
        do{
            printf("Ingrese la coordenada en Y para atacar:");
            scanf("%d",&CoordY);
        }while(CoordY<=0 || CoordY>10); 
        CoordY--;
        CoordX--;
        
        for(int x=0;x<5;x++){
            if(BarcosPC[x][CoordY][CoordX]=='X'){
                acertar=1;
                BarcosPC[x][CoordY][CoordX]='-';
                vidasPC[x]--;
            }
        }
        if(acertar==1){
            printf("le has atinado a un barco!!!\n");
            CampoPC[CoordY][CoordX]='X';    
        }else{
            printf("has fallado!!!\n");
            CampoPC[CoordY][CoordX]='O';
        }
        
        system("pause");
        acertar=0;
        printf("ahora es turno de la PC:\n\n");
        
        
        CoordX=(0+rand()%(10));
        CoordY=(0+rand()%(10));
        printf("valor de la PC en X:%d\n",CoordX+1);
        printf("valor de la PC en Y:%d\n",CoordY+1);
        for(int x=0;x<5;x++){
            if(Barcos[x][CoordY][CoordX]=='X'){
                acertar=1;
                Barcos[x][CoordY][CoordX]='-';
                vidas[x]--;
            }
        }
        if(acertar==1){
            printf("La PC ha atinado un barco!!!\n");
            CampoJ[CoordY][CoordX]='X';    
        }else{
            printf("La PC ha fallado!!!\n");
            CampoJ[CoordY][CoordX]='O';
        }
        system("pause");        
        
        acertar=0;
        
        if(vidas[0]+vidas[1]+vidas[2]+vidas[3]+vidas[4]==0){
            printf("Has perdido, juego terminado!!!");
            perder=1;
        }
        
        if(vidasPC[0]+vidasPC[1]+vidasPC[2]+vidasPC[3]+vidasPC[4]==0){
            printf("Has ganado,Enhoranuena!!!");
            ganar=1;
        }
        
        
    }while(ganar==0 && perder==0);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



void CampoCompleto(char CampoJ[][10],char CampoPC[][10]){
    system("cls");
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
    
}
void ColocarBarcoPC(int Barco,int verificar,int largo,char Barcos[][10][10],char Campo[][10]){
    srand(time(NULL));
    int CoordX,CoordY,opc;
    int reiniciar=0;
    int repetir=0;
    do{
        CoordX=(0+rand()%(10)),CoordY=(0+rand()%(10));
        reiniciar=0;
        repetir=0;
        
        do{
            verificar=0;
            CoordX=(0+rand()%(10));
            CoordY=(0+rand()%(10));
            if(Campo[CoordY][CoordX]=='-'){
                Barcos[Barco][CoordY][CoordX]='X';
                //Campo[CoordY][CoordX]='X';            linea de codigo cuando quieres ver las posiciones de los barcos de la pc
            }else if(Campo[CoordY][CoordX]=='X'){
                verificar=1;
            }
        }while(verificar==1);
        verificar=0; 
        
        do{  
            opc=1+(rand()%(5));  
            repetir=0;
            int colocar=1;
            if(opc==1){
                if(CoordY-largo>=0){
                    for(int x=1;x<largo;x++){
                        if(Campo[CoordY-x][CoordX]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            Campo[CoordY-x][CoordX]='X';
                            Barcos[Barco][CoordY-x][CoordX]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordY-largo<0)){
                    repetir=1;
                }
            }
            
            if(opc==2){
                
                if(CoordX+largo<10){
                    for(int x=1;x<largo;x++){
                        if(Campo[CoordY][CoordX+x]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            Campo[CoordY][CoordX+x]='X';
                            Barcos[Barco][CoordY][CoordX+x]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordX+largo>=10)){
                    repetir=1;
                }
            }
            
            if(opc==3){
                
                if(CoordY+largo<10){
                    for(int x=1;x<largo;x++){
                        if(Campo[CoordY+x][CoordX]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            Campo[CoordY+x][CoordX]='X';
                            Barcos[Barco][CoordY+x][CoordX]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordY+largo>=10)){   
                    repetir=1;
                }
            }
            
            if(opc==4){
                
                if(CoordX-largo>=0){
                    for(int x=1;x<largo;x++){
                        if(Campo[CoordY][CoordX-x]!='-'){
                            colocar=0;
                        }
                    }
                    if(colocar==1){
                        for(int x=1;x<largo;x++){
                            Campo[CoordY][CoordX-x]='X';
                            Barcos[Barco][CoordY][CoordX-x]='X';
                        }
                    }
                }
                
                if(colocar==0 || (CoordX-largo<0)){
                    repetir=1;
                }
            }
            
            if (opc==5){
                reiniciar=1;
                Barcos[Barco][CoordY][CoordX]='-';
                Campo[CoordY][CoordX]='-';
            }
        }while(repetir==1);
    }while(reiniciar==1);        
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
                
                if((CoordY+1)-largo>=0){
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
                
                if(colocar==0 || ((CoordY+1)-largo<0)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if(opc==2){
                
                if((CoordX)+largo<=10){
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
                
                if(colocar==0 || ((CoordX)+largo>10)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if(opc==3){
                
                if((CoordY)+largo<=10){
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
                
                if(colocar==0 || ((CoordY)+largo>10)){
                    printf("no se pudo realizar la colocacion\n");
                    repetir=1;
                    system("pause");
                }
            }
            
            if(opc==4){
                
                if((CoordX+1)-largo>=0){
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
                
                if(colocar==0 || ((CoordX+1)-largo<0)){
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
