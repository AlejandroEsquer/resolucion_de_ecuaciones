#include <stdio.h>
typedef struct matriz{
	
	int n;
	float ent[10][11];
	
}matriz;

matriz multrow(matriz mat,int row,float mult);
matriz restarow(matriz mat,int ren,int resta,float mult);
matriz diagonalizamat(matriz mat);
int escribesol(matriz mat,matriz aux);



int escribemat(matriz mat);
int main(void){

	int ec,i,j,k,row,resta;
	float mult;	

	printf("Escriba el numero de ecuaciones(menor a 10):\n");
	scanf("%d",&ec);
	
	
	 matriz mat,mataux;
	mat.n=ec;



	for(i=0;i<ec;i++){
		for(j=0;j<=ec;j++){
			printf("Escriba la entrada [%d,%d]:\n",i,j);
			scanf("%g",&mat.ent[i][j]);

		}
	}
	
	printf("La matriz es:\n");
	for(i=0;i<ec;i++){
		for(j=0;j<=ec;j++){
			printf(" %g ",mat.ent[i][j]);
		}
		printf("\n");
	}

	mataux=mat;
	mat=diagonalizamat(mat);
	printf("La nueva matriz es:\n");
	escribemat(mat);
	escribesol(mat,mataux);
return 0;
	

	}


matriz multrow(matriz mat,int row,float mult){
	int i,j;
	for(i=0;i<=mat.n;i++)
		mat.ent[row][i]=mat.ent[row][i]*mult;

	return mat;
	}

matriz restarow(matriz mat,int ren,int resta,float mult){
	
	int i,j,n;
	matriz aux;

	n=mat.n;
	aux=multrow(mat,resta,mult);

	for(i=0;i<n+1;i++)
		mat.ent[ren][i]=mat.ent[ren][i]-aux.ent[resta][i];

	return mat;

}

matriz diagonalizamat(matriz mat){
	double a,d,aux;
	int i,j,n,c;

	n=mat.n;

	for(i=0;i<n;i++){
		a=mat.ent[i][i];
		for(j=0;j<n ;j++){
			if(j!=i){
				d=mat.ent[j][i];
				aux=d/a;
				mat=restarow(mat,j,i,aux);
				printf("%d este es %f, %f\n",j,d,a);
				escribemat(mat);
			}
		}
	}

	for(i=0;i<n;i++){
		mat.ent[i][n]=mat.ent[i][n]/mat.ent[i][i];
		mat.ent[i][i]=1;
	}

	return mat;
}



int escribemat(matriz mat){
	 printf("La matriz es:\n");
	int i,j;

        for(i=0;i<mat.n;i++){
                for(j=0;j<=mat.n;j++){
                        printf(" %g ",mat.ent[i][j]);
                }
                printf("\n");
        }
}

int escribesol(matriz mat,matriz aux){
	int i,n=mat.n,j;

	printf("\nLas ecuaciones son:\n");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(j==n)
				printf("=");
			printf("(%f)",aux.ent[i][j]);
			if(j!=n){
				printf("X%d",j);
				if(j!=(n-1))
					printf("+");
			}
		}
		printf("\n");
	}

	printf("\nLas soluciones de las ecuaciones son:\n");
	for(i=0;i<mat.n;i++){
		printf("X%d = %f\n",i,mat.ent[i][n]);
	}
}
