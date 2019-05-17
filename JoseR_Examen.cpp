#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
void imprimir(char**matriz,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<'['<<matriz[i][j]<<']';
		}
		cout<<endl;
	}
}
int movimientoplayer1(char**matriz,int m,int n,int m2,int n2){
	   if(matriz[m][n]=='N'&&matriz[m2][n2]==' '&&(m==m2||n==n2)){
		   matriz[m2][n2]=matriz[m][n];
		   matriz[m][n]=' ';
		   return 2;
	   }else{
		   cout<<"!COORDENADA INVALIDA"<<endl;
		   return 1;
	   }

}
int movimientoplayer2(char**matriz,int m,int n,int m2,int n2){
           if((matriz[m][n]=='O'||matriz[m][n]=='W')&&matriz[m2][n2]==' '&&(m==m2||n==n2)){
                   matriz[m2][n2]=matriz[m][n];
                   matriz[m][n]=' ';
                   return 1;
           }else{
                   cout<<"!COORDENADA INVALIDA"<<endl;
                   return 2;
           }

}

char**llenadomatriz(char**matriz){
	int size=11;
        matriz= new char*[size];
        for(int i=0;i<size;i++){
                matriz[i]=new char[size];
                }
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matriz[i][j]=' ';
			if((i==0&&(j==10||j==0))||(i==10&&(j==0||j==10))){
				matriz[i][j]='X';
			}
			if(((i==4&&(j==0||j==10))||(i==5&&(j==0||j==10))||(i==6&&(j==0||j==10)))||((j==4&&(i==0||i==10)||(j==5&&(i==0||i==10))||(j==6&&(i==0||i==10))))){
				matriz[i][j]='N';
			}
			if(i==4||i==6){
				if(j==1||j==9){
				matriz[i][j]='N';
				}
			}
			if(j==4||j==6){
				if(i==1||i==9){
				matriz[i][j]='N';
				}
			}
			if(i==5&&(j==2||j==8)){
				matriz[i][j]='N';
			}
			if(j==5&&(i==2||i==8)){
				matriz[i][j]='N';
			}
			if((i>=3&&i<=7)&&j==5){
			 	matriz[i][j]='O';

			}
			if((j>=3&&j<=7)&&i==5){
				matriz[i][j]='O';

			}


		}
	}
	matriz[4][6]='O';
	matriz[6][4]='O';
	matriz[4][4]='O';
	matriz[6][6]='O';
	matriz[5][5]='W';

	
	return matriz;
}
void comer1(char**matriz,int size){
     for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        if(j==0&&(matriz[i][j]=='O'&&matriz[i-1][j]=='N'&&matriz[i+1][j]=='N')&&i!=0&&i!=10){
				matriz[i][j]=' ';
			}else if(j==10&&(matriz[i][j]=='O'&&matriz[i-1][j]=='N'&&matriz[i+1][j]=='N')&&i!=0&&i!=10){
				 matriz[i][j]=' ';

			}else if(i==0&&(matriz[i][j]=='O'&&matriz[i][j-1]=='N'&&matriz[i][j+1]=='N')&&j!=0&&j!=10){
				 matriz[i][j]=' ';
			}
			else if(i==10&&(matriz[i][j]=='O'&&matriz[i][j-1]=='N'&&matriz[i][j+1]=='N')&&j!=0&&j!=10){
			 	matriz[i][j]=' ';

			}else if(matriz[i][j]=='O'&& (matriz[i][j-1]=='N'&&matriz[i][j+1]=='N'||matriz[i-1][j]=='N'&&matriz[i+1][j]=='N')){
				 matriz[i][j]=' ';

			}
             }

        }

}
void comer2(char**matriz,int size){
	cout<<"hey";
     for(int i=0;i<size;i++){
	     cout<<"hey";
                for(int j=0;j<size;j++){
			cout<<"hey";
                        if(i==0&&(matriz[i][j]=='N'&&matriz[i-1][j]=='O'&&matriz[i+1][j]=='O')&&j!=0&&j!=10){
                                matriz[i][j]=' ';
                        }else if(i==10&&(matriz[i][j]=='N'&&matriz[i-1][j]=='O'&&matriz[i+1][j]=='O')&&j!=0&&j!=10){
                                 matriz[i][j]=' ';

                        }else if(j==0&&(matriz[i][j]=='N'&&matriz[i][j-1]=='O'&&matriz[i][j+1]=='O')&&i!=0&&i!=10){
                                 matriz[i][j]=' ';
                        }
                        else if(j==10&&(matriz[i][j]=='N'&&matriz[i][j-1]=='O'&&matriz[i][j+1]=='O')&&i!=0&&i!=10){
                                matriz[i][j]=' ';

                        }else if(matriz[i][j]=='N'&& (matriz[i][j-1]=='O'&&matriz[i][j+1]=='O'||matriz[i-1][j]=='O'&&matriz[i+1][j]=='O')){
                                 matriz[i][j]=' ';

                        }
                }
        }

}

int main(){
	char resp='s', fila='A',filanueva='A';
	int turno=1,colum=0,column=0;
	char**matriz=NULL;
	cout<<"hola"<<endl;
	matriz=llenadomatriz(matriz);
	imprimir(matriz,11);
	cout<<(int)fila-65<<endl;
	while(turno!=0){
		while(turno==1){
			cout<<"Player 1 ingrese letra de la fila de su pieza"<<endl;
			cin>>fila;
			cout<<"Player 1 ingrese la letra de la columna de su pieza"<<endl;
			cin>>colum;
			cout<<"Fila a mover"<<endl;
			cin>>filanueva;
			cout<<"Columna a mover"<<endl;
			cin>>column;
			turno=movimientoplayer1(matriz,(int)fila-65,colum,(int)filanueva-65,column);
			comer1(matriz,11);
			imprimir(matriz,11);	
		
		}
		while(turno==2){
		    cout<<"Player 2 ingrese letra de la fila de su pieza"<<endl;
                        cin>>fila;
                        cout<<"Player 2 ingrese la letra de la columna de su pieza"<<endl;
                        cin>>colum;
                        cout<<"Fila a mover"<<endl;
                        cin>>filanueva;
                        cout<<"Columna a mover"<<endl;
                        cin>>column;
                        turno=movimientoplayer2(matriz,(int)fila-65,colum,(int)filanueva-65,column);
			//comer2(matriz,11);
                        imprimir(matriz,11);

		}
		if(matriz[0][10]=='w'||matriz[10][0]=='w'||matriz[0][0]=='w'||matriz[10][10]=='w'){
			turno=0;
			cout<<"El juego ha terminado"<<endl;
		}
	

	}
return 1;
}
