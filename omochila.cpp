#include <iostream>
using namespace std;

/*

	cd Desktop/OneDrive/2017.1/Complexidade/
	
	g++ omochila.cpp -o omochila
	
*/

int tam;


#define TAM 10000000

int entrada[TAM][3];
int b[TAM],wt[TAM];
int V[TAM][TAM];

int knapsack(int W, int wt[], int b[], int n){
	int w,i;
	for(w = 0; w <= W; w++)
		V[0][w] = 0;
	for(i = 1; i <= n; i++)
		V[i][0] = 0;

	for( i = 1; i <= n; i++){
		for( w = 1; w <= W; w++){	
			// elemento pode fazer parte da solução
			if(wt[i - 1] <= w){
				// Tenta colocar o item completo
				if((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
					V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w]; // wi > w
		}
	}
	// retorna o valor máximo colocado na mochila
	return V[n][W];
}

int main(){
	int i,j;
	int capacidade;
	
	scanf("%d",&tam);
	
	for(i = 0; i < tam; i++){
        for(j = 0; j < 3; j++){
        	scanf("%d",&entrada[i][j]);
        }
        b[i] = entrada[i][1];
        wt[i] = entrada[i][2];
	}
    	
    scanf("%d",&capacidade);

	int max_valor = knapsack(capacidade, wt, b, tam);
	cout << "Valor maximo: " << max_valor << endl;

	return 0;
}

/*

Numero de Itens

	Uma linha para cada item usando o seguinte formato: 
	Numero do item		Valor do item		Peso do item
		  0					  1			/		  2
Capacidade da Mochila

*/