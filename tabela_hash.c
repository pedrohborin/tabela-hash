//trabalho tabela hash

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<math.h>
#include "tabela_hash.h"




// fução que cria no  
No* criarNo(int value){
	No* aux = (No*) malloc( sizeof(No) ); // aloca na memoria
	aux->data = value;
	aux->prox = NULL;
	return aux;  // retorna endereço da memoria
}

// fução que cria tabela
void criarTabela(No vet[]){
	
	int i = 0;
	
	while(i < 50){ 			 // anda por todo o vetor
		
		vet[i].data = 0;
		vet[i].prox = NULL;  // coloca todos os elementos do vetor apontando para null
		i++;
	}
	
	int j = 0;
	
	while(j<50){			 // anda por todo o vetor novamente
		
		int a = rand() % 2;  // varivel que aloca aleatoriamente se o numero sera negativo ou 
							 // positivo 
        int b = pow(2,16);	 // variavel que aloca o 2^16
        int x = rand() % b;	 // variavel que aloca aleatoriamente um numero entre 0 e 2^16
        
        if(a==0){			 // caso onde se aloca o numero positivo 
        	inserir(x, vet);
		}
        else{
        	inserir(x*-1, vet); // caso onde se aloca o numero negativo 
		}
        j++;                // incremento do segundo laço
	}

}


// função que mostra a tabela na tela
void imprimirTeste(No vet[]){
	
	int i = 0;                               // contador
	int t = 1;                               // linha
	int b = 5;                               // coluna
	while(i<=49){                            // anda por toda a tabela
	
		posicao(b,t);printf("[%d]->  ",i);   // posiçao do vetor em que estamos
		
		if(vet[i].data == 0){
			posicao(b+6,t);printf(" ");      // caso nao tenha nenhum numero no endereço i do vetor
		}else{
		posicao(b+7,t);printf(" %d ", vet[i].data); // caso tenha numero no endereço
		}
		
		if(vet[i].prox != NULL){
			No* andar = vet[i].prox;         // variavel auxiliar que anda pela lista
			int h = b + 7;
			while(andar != NULL){   		 // anda pela lista que esta no endereço i do vetor
				
				posicao(h+7,t);printf(" %d ", andar->data);
				andar = andar->prox;         // incremento para andar na lista
				h = h + 7;					 // anda na tela pra imprimir
			}	
		}
		if(i == 24){                        // caso onde separamos a lista na tela
			b = b + 100;                    // anda 100 colunas pra frente 
			t = 0;                          // voltamo para linha 1
		}
		
		i++;                               // incremento para andar na lista
		t++;							   // incremtnto para imprimir na proxima linha
	}
}

// função hash
int hash(int value){
	int a = value % 50;   // resultado ta divisão 
	return a;       	  // retorna este resultado 
}

// função de inserir 
void inserir(int value , No vet[]){
	
	int aux;                  // variavel auxiliar que aloca o resultado da função hash para 
			                  // saber a posição do vetor 
	
	// Se o valor for negativo					   
	if(value < 0){             
		aux = hash(value*-1); // multiplica a variavel por -1 para entrar na função mod, porem 
							  // sem alterar o valor de value
	}
	else{
		aux = hash(value);   // entrando na função hash e retornando a posição no vetor
	}
	
	// Caso mais de um valor
	if(vet[aux].prox != NULL){
		No *andar = vet[aux].prox; // variavel auxiliar que aloca o enredeço do proximo do no vetor
		No *andar2 = NULL;         // 2ª variavel auxiliar para n perder o endereço do nó criado
		while(andar != NULL){      // andando na lista ate o enredeço vazio
			andar2 = andar;
			andar = andar->prox;   // incremento do while
		}
		
		andar = criarNo(value);   // criação do novo nó
		andar2->prox = andar;     // adicionando este novo no à lista
		
	}
	
	if(vet[aux].data !=0 && vet[aux].prox == NULL){   // caso endereço i tenha 1 valor
		
		vet[aux].prox = criarNo(value);
	}	

	if(vet[aux].data == 0 && vet[aux].prox == NULL){  // caso o nó no vetor n tenha nenhum valor
		vet[aux].data = value;
		
	}
	
}

// Retorna o numero de valores naquela posicao
int meuContar(No vet1[], int i){
	
	No *andar = &vet1[i]; 		 // aloca o endereço do nó i do vetor
	int x = 0;
	
	while(andar != NULL){        // andando pela lista encadeada
		if(andar->data == 0){    // caso n tenha nada
			andar=andar->prox;   // incremento do while
		}else{
			x++;                 // caso tenha algo, x adicina 1
			andar=andar->prox;   // incremento do while
		}
			
	}
	return x;					 // retorna o valor de x
	
}

// Insere os valores iniciais de um vet1 em um vet2, onde vet2 nao tem nada
void meuUnir(No vet1[], No vet2[]){
	
	int i = 0;
	while(i<50){            // andando pelo vet1
		vet2[i] = vet1[i];  // igualando cada endereço do vet2 igual ao vet1
		i++;				// incremento do while
	}
	return;
}

// Inserie os valores de um vet1 em um vet2, onde vet2 ja tem valores inseridos 
void meuSegundoUnir(No vet1[], No vet2[]){
	
	int i = 0;
	
	while(i<50){
		meuUnirAuxiliar(vet1, vet2, i);
		
		i++;
	}
}

// Inserir os valores do endereço i do vet1 no endereço i do vet2
void meuUnirAuxiliar(No vet1[], No vet2[], int i){
	
	// Se temos 0 valores no endereço i de vet2
	if(&vet2[i].data == 0){
		
		No *andar = NULL;			// variavel auxiliar
		No *andar2 = NULL;			// variavel auxiliar
		
		No *andarVet1 = &vet1[i];	// variavel auxilair anda pelo vetor 1
		
		// Numero de valores naquela posiçao do vetor 1
		int x = meuContar(vet1, i);
		
		vet2[i].data = andarVet1->data; // colocando o 1º valor de vet1 em vet2
							
		x--;							// diminuindo o numero de valores que deve 
										// ser inserido em vet2
		andar = &vet2[i];				// incrementando andar, apontando para o no
										// do vet2 
		
		while(x>0){
			
			andar->prox = criarNo(andarVet1->data);  // criando o nó da lista encadeada de
													 // vet2
			andar2 = andar;							 // movimentando os ponteiros para frente
													 // no vet2
			andar = andar->prox;    				 // movimentando os ponteiros para frente
													 // no vet2
			andarVet1 = andarVet1->prox;             // movimentando o ponterio para frente no
													 // vet1
			x--;									 // incremento do while
			
		}
		return;
		
	}
	
	// Se temos 1 valor no enredeço i do vet2
	else if(&vet2[i].data != 0 && vet2[i].prox == NULL){
		
		No *andar = &vet2[i];            // variavel auxiliar
		No *andar2 = NULL;				 // variavel auxiliar
		
		No *andarVet1 = &vet1[i];		 // variavel auxilair anda pelo vetor 1
		
		// Numero de valores naquele vetor
		int x = meuContar(vet1, i);
		
		while(x>0){
			
			andar->prox = criarNo(andarVet1->data);  // criando o nó da lista encadeada de
													 // vet2
			andar2 = andar;							 // movimentando os ponteiros para frente
													 // no vet2
			andar = andar->prox;					 // movimentando os ponteiros para frente
													 // no vet2
			andarVet1 = andarVet1->prox;			 // movimentando o ponterio para frente no
													 // vet1
			x--;									 // incremento do while
			
		}
		return;
	}
	
	// Se temos 2 valores ou mais
	else if(vet2[i].prox != NULL){
		No *andar = vet2[i].prox;       // variavel auxiliar
		No *andar2 = &vet2[i];			// variavel auxiliar
		
		No *andarVet1 = &vet1[i];		// variavel auxilair anda pelo vetor 1
		
		// Numero de valores naquele vetor
		int x = meuContar(vet1, i);
		
		while(andar->prox!=NULL){
			andar2 = andar;				// alocando o endereço do atual 
			andar = andar->prox;		// andando para o proximo ate que seja null
		}
		while(x>0){
			
			andar->prox = criarNo(andarVet1->data);    // criando o nó da lista encadeada de
													   // vet2
			andar2 = andar;							   // movimentando os ponteiros para frente
												   	   // no vet2
			andar = andar->prox;					   // movimentando os ponteiros para frente
													   // no vet2
			andarVet1 = andarVet1->prox;			   // movimentando o ponterio para frente no
													   // vet1
			x--;									   // incremento do while
		}
		return;
	}
	else{
		printf("\nErou\n");							   // caso nao tivesse entrado em nada antes
		return;
	}
	
}

// função que uni duas tabelas em uma terceira tabela
void unir(No vet1[],No vet2[],No vet3[]){
	
	meuUnir(vet1,vet3); 			// valores de 1 inseridos em 3, com 3 vazio
	
	meuSegundoUnir(vet2, vet3);		// valorees de 2 inseridos em 3, com 3 ja tendo numero

	return;
}

// funçã que avalia se a tabela existe ou não
int verificaTabela(No vet[]){
	
	int verifica = 0;       	// variavel auxiliar 
	int k= 0;					
	while(k<= 49){
		if(vet[k].data == 0){  // caso nao tenha nada no endereço k da lista
			k++;			   // incremento do while
		}else{
			verifica = 1;      // caso tenha algo, verifica igual a 1 e a função acaba
							   // pois ja se sabe que a tabela existe
			return verifica;
		}
	}
	return verifica;
}

// função que seta a posição no cmd como um plano carteziano
void posicao(int x, int y)
{
 HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(SaidaSTD, coord);
}

//função que printa o cabecalho
void cabecalho(){
	
	int p = 196;
	posicao(30,1);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c Menu %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n"
	, 218, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, 191);
	
}

// função que printa a base
void base(int var){
	
	int p = 196;
	posicao(30,var);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n"
	,192, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, p, 217);
	
}

// retorna 0 se nao existe, e 1 se existir
int queroBuscar(int value, No vet[]){
	
	int aux; // cria aux para armazenar posicao do valor
	
	// Se negativo
	if(value < 0){
		aux = hash(value*-1);      // multiplica a variavel por -1 para entrar na função mod, porem 
							 	   // sem alterar o valor de value

	}
	// Se positivo
	else{
		aux = hash(value);
	}
	
	// Se o valor for o primeiro positivo
	if(vet[aux].data == value){
		
		return 1;
	}
	
	else{    // Se houver mais de um valor
		if(vet[aux].prox != NULL){
			No *andar = vet[aux].prox;  // aloca o endereço do proximo 
			while(andar != NULL){       // anda pela lista encadeada
				if(andar->data == value){  // verifica se o valor esta na tabela
					return 1;
				}
				andar = andar->prox;   // incremento do while
			}
			return 0;				   // caso nao ache o numero 
			
			
		}else{
			return 0;				   // caso nao ache o numero 
		}
	}
	
}

void excluirFeatLaurinho(int value, No vet[]){
	
	// Se o valor existir, buscar retorna 1
	if(queroBuscar(value, vet)){
		
		int aux; // cria aux para armazenar posicao do valor
	
		// Se negativo
		if(value < 0){
			aux = hash(value*-1);
		}
		// Se positivo
		else{
			aux = hash(value);
		}
		
		// Se apenas um valor
		if(value == vet[aux].data && vet[aux].prox == NULL){
			vet[aux].data = 0;
		}                                                                             
			
		// se mais de um valor, porem o valor excluido é o primeiro 
		else if(vet[aux].prox != NULL){
			if(value == vet[aux].data){
				vet[aux].data = vet[aux].prox->data; // valor do no é o mesmo do seu proximo 
				vet[aux].prox = vet[aux].prox->prox; // no aponta para o proximo do seu 
													 // proximo 
			}
			// Se for o segundo a diante
			else{
				No *andar = vet[aux].prox; 		// aloca a posição do nó do vetor
				No *andar2 = &vet[aux];			// aloca posição do seu proximo 
				
				// Percorre o vetor ate chegar no valor
				while(andar != NULL){
					
					if(andar->data == value){   // quando achar o nó com o valor
						
						andar2->prox = andar->prox; // seu anterior aponta para o seu proximo 
													// perdendo esse endereço
						return;
						
					}else{
						andar2 = andar; 			// incremento do while, andando os dois 
						andar = andar->prox;		// auxilares para frente
					}
				}
			}
		}else{
			printf("\ndeu ruim\n");					// caso não entrasse em nenhum antes
		}
	
	// Se nao existir
	}else{
		system("cls");
		cabecalho();   // print
		posicao(30,3);printf("\t\tValor nao existe...");
		base(5);       // print
	}
	
}