#include <stdio.h>
#include <stdlib.h>

/*
	cd Desktop/OneDrive/2017.1/Complexidade/

	gcc nlognmochila.c -o nlognmochila

*/

int tam;

int comp(const void *a,const void *b){
	double *l1 = (double *) a;
	double *l2 = (double *) b;
	if(l1[3] < l2[3])
		return 1;
	if(l1[3] > l2[3])
		return -1;
	return 0;
}

void preenche_mochila(double vetor[tam][3],float capacidade){
	int i;
	double vetor_valores[tam][5];
	float soma = 0,peso_mochila = 0,x;
	
	for (i = 0; i < tam; ++i){
		vetor_valores[i][0] = vetor[i][0];	// Id
		vetor_valores[i][1] = vetor[i][1];	// Valor
		vetor_valores[i][2] = vetor[i][2];	// Peso
		
		vetor_valores[i][3] = vetor[i][1] / vetor[i][2]; // Valor por Peso
		
		vetor_valores[i][4] = 100.0;					// Porcentagem do Item
	}

	qsort( vetor_valores, tam, 5*sizeof(double), comp);	// N log N
	
	for(i = 0; i < tam ; i++){
		//Se não der pra colocar um item completo, para o laço
		if(vetor_valores[i][2] + peso_mochila > capacidade )
			break;
		// Se der pra colocar o item completo
		soma += vetor_valores[i][1];
		peso_mochila += vetor_valores[i][2];		
	}

	while(i < tam){
		x = (capacidade - peso_mochila) / vetor_valores[i][2];		
		soma += vetor_valores[i][1] * x;
		peso_mochila += (capacidade - peso_mochila) / vetor_valores[i][2];	
		i++;
	}

	printf("\n\nSoma total do Valor da Mochila [%.0f]\n",soma);
	printf("Capacidade da Mochila [%.0f]\n",capacidade);
}

int main(){
	
	int i,j;
	float capacidade;
	
	scanf("%d",&tam);
	
	double entrada[tam][3];
	
	for(i = 0; i < tam; i++)
        for(j = 0; j < 3; j++)
        	scanf("%lf",&entrada[i][j]);
    	
    scanf("%f",&capacidade);

	printf("\n");
    preenche_mochila(entrada,capacidade);  
	
	return 0;
}



/*

Numero de Itens

	Uma linha para cada item usando o seguinte formato: 
	Numero do item		Valor do item		Peso do item
		  0					  1			/		  2
Capacidade da Mochila

*/