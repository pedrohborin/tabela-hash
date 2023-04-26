#include<stdio.h>
#include<stdlib.h>
#include"tabela_hash.c"
#include<math.h>

/*

169   170

*/

No vetA[50];		// vetor A
No vetB[50];		// vetor B
No vetC[50];		// vetor C
int p = 196;
int x;

// Menu 2 para mostrar tabelas
void menu2(void){
	int choice2;
	do{
		// Menu para printar as Tabelas
		//system("cls");
		cabecalho();
		posicao(30,3);printf("    1. Mostrar tabela A\n");
		posicao(30,4);printf("    2. Mostrar tabela B\n");
		posicao(30,5);printf("    3. Mostrar tabela C\n");
		posicao(30,6);printf("    4. Voltar\n");
		base(8);
		posicao(30,10);printf("  Opcao: ");
		scanf("%d",&choice2);
		
		switch(choice2){
			// Printa na tela a tabela A
			case 1: system("cls");
			
				if(verificaTabela(vetA) == 0){
					cabecalho();
					posicao(30,3);printf("   Tabela inexistente\n\n");
					base(5);
				}else{
					imprimirTeste(vetA);
					printf("\n\n");
				}
				choice2 = 4; // ao printar o programa volta 
				break;		 // para o primeiro menu
				
			// Printa na tela a tabela B
			case 2: system("cls");
				if(verificaTabela(vetB) == 0){
					cabecalho();
					posicao(30,3);printf("   Tabela inexistente\n\n");
					base(5);
				}else{
					imprimirTeste(vetB);
					printf("\n\n");
				}
				choice2 = 4;	// ao printar o programa volta 
				break;			// para o primeiro menu
				
			// Printa na tela a tabela C
			case 3:system("cls");
				if(verificaTabela(vetC) == 0){
					cabecalho();
					posicao(30,3);printf("   Tabela inexistente\n\n");
					base(5);
				}else{
					imprimirTeste(vetC);
					printf("\n\n");
				}
				choice2 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu
			
			// Sair
			case 4:
				posicao(30,12);printf("  Voltando...\n\n");
				break;		// volta para o primeiro menu 
			
			// Default
			default:system("cls");
				printf("\n Escolha invalida.\n");
				system("pause");
				system("cls");
				break;
		}
				
	} while (choice2 != 4);
}

// Menu para unir tabelas
void menu3(void){
	int choice3;
	do{
		system("cls");
		cabecalho();
		posicao(30,3);printf("  1. Unir A com A\n");
		posicao(30,4);printf("  2. Unir A com B\n");
		posicao(30,5);printf("  3. Unir B com A\n");
		posicao(30,6);printf("  4. Unir B com B\n");
		posicao(30,7);printf("  5. Voltar");
		base(9);
		posicao(30,10);printf("Opcao: ");
		posicao(30,11);scanf("%d",&choice3);
		
		switch(choice3){
			// Mostrar tabela A
			case 1: system("cls");
				unir(vetA, vetA, vetC);
				cabecalho();
				posicao(30,3);printf("\t\t Unido A com A\n\n");
				base(5);
				choice3 = 5;	// ao printar o programa volta
				break;			// para o primeiro menu
				
			// Mostrar tabela B
			case 2: system("cls");
				unir(vetA, vetB, vetC);
				cabecalho();
				posicao(30,3);printf("\t\t Unido A com B\n\n");
				base(5);
				choice3 = 5;	// ao printar o programa volta
				break;			// para o primeiro menu
				
			// Mostrar tabela C
			case 3:system("cls");
				unir(vetB, vetA, vetC);
				cabecalho();
				posicao(30,3);printf("\t\t Unido B com A\n\n");
				base(5);
				choice3 = 5;	// ao printar o programa volta
				break;			// para o primeiro menu
			
			// Mostrar
			case 4:system("cls");
				unir(vetB, vetB, vetC);
				cabecalho();
				posicao(30,3);printf("\t\t Unido B com B\n\n");
				base(5);
				choice3 = 5;	// ao printar o programa volta
				break;			// para o primeiro menu
			
			// Sair
			case 5:system("cls");
				cabecalho();
				printf("Voltando...\n");
				break;
			
			// Default
			default:system("cls");
				printf("\n Escolha invalida.\n");
				system("pause");
				system("cls");
				break;
		}
				
	} while (choice3 != 5);
}

// Menu para excluir valor
void menu4(void){
	int choice4;
	do{
		system("cls");
		cabecalho();
		posicao(30,3);printf("  1. Excluir na tabela A\n");
		posicao(30,4);printf("  2. Excluir na tabela B\n");
		posicao(30,5);printf("  3. Excluir na tabela C\n");
		posicao(30,6);printf("  4. Voltar");
		base(8);
		posicao(30,9);printf("\n Opcao: ");
		posicao(30,10);scanf("%d",&choice4);
		
		switch(choice4){
			// Excluir na tabela A
			case 1: system("cls");
				cabecalho();
				posicao(30,3);printf("   Valor a ser excluido: ");
				base(5);
				posicao(56,3);scanf("%d", &x);
				excluirFeatLaurinho(x, vetA);
				system("cls");
				cabecalho();
				posicao(30,3);printf("   Valor %d excluido com sucesso!\n", x);
				base(5);
				choice4 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu
				
			// Excluir na tabela B
			case 2: system("cls");
				cabecalho();
				posicao(30,3);printf("   Valor a ser excluido: ");
				base(5);
				posicao(56,3);scanf("%d", &x);
				excluirFeatLaurinho(x, vetB);
				system("cls");
				cabecalho();
				posicao(30,3);printf("   Valor %d excluido com sucesso!\n", x);
				base(5);
				choice4 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu
				
			// Excluir na tabela C
			case 3:system("cls");
				cabecalho();
				posicao(30,3);printf("   Valor a ser excluido: ");
				base(5);
				posicao(56,3);scanf("%d", &x);
				excluirFeatLaurinho(x, vetC);
				system("cls");
				cabecalho();
				posicao(30,3);printf("   Valor %d excluido com sucesso!\n", x);
				base(5);
				choice4 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu
			
			// Mostrar
			case 4:system("cls");
				choice4 = 4;
				break;  // volta para menu principal 
			
			// Default
			default:system("cls");
				printf("\n Escolha invalida.\n");
				system("pause");
				system("cls");
				break;
		}
				
	} while (choice4 != 4);
}

// Menu para adicionar valor
void menu5(void){
	int choice5;
	do{
		system("cls");
		cabecalho();
		posicao(30,3);printf("  1. Adicionar na tabela A\n");
		posicao(30,4);printf("  2. Adicionar na tabela B\n");
		posicao(30,5);printf("  3. Adicionar na tabela C\n");
		posicao(30,6);printf("  4. Voltar");
		base(8);
		posicao(30,9);printf("\n Opcao: ");
		posicao(30,10);scanf("%d",&choice5);
		
		switch(choice5){
			// Adicionar na tabela A
			case 1: system("cls");
				if(verificaTabela(vetA) == 0){
					cabecalho();
					posicao(30,3);printf("\t\tTabela inexistente\n\n");
					base(5);
					
				}else{
					cabecalho();
					posicao(30,3);printf("   Valor a ser adicionado: ");
					base(5);
					posicao(57,3);scanf("%d", &x);
					inserir(x,vetA);
					system("cls");
					cabecalho();
					posicao(30,3);printf("   Valor %d inserido com sucesso!\n", x);
					base(5);
				}
				choice5 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu
			
				
			// Adicionar na tabela B
			case 2: system("cls");
				if(verificaTabela(vetB) == 0){
					cabecalho();
					posicao(30,3);printf("\t\t Tabela inexistente\n\n");
					base(5);
					
				}else{
					cabecalho();
					posicao(30,3);printf("   Valor a ser adicionado: ");
					base(5);
					posicao(57,3);scanf("%d", &x);
					inserir(x,vetB);
					system("cls");
					cabecalho();
					posicao(30,3);printf("   Valor %d inserido com sucesso!\n", x);
					base(5);
				}
				choice5 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu		
				
			// Adicionar na tabela C
			case 3:system("cls");
				if(verificaTabela(vetC) == 0){
					cabecalho();
					posicao(30,3);printf("\t\t Tabela inexistente\n\n");
					base(5);
					
				}else{
					cabecalho();
					posicao(30,3);printf("   Valor a ser adicionado: ");
					base(5);
					posicao(57,3);scanf("%d", &x);
					inserir(x,vetC);
					system("cls");
					cabecalho();
					posicao(30,3);printf("   Valor %d inserido com sucesso!\n", x);
					base(5);
				}
				choice5 = 4;	// ao printar o programa volta
				break;			// para o primeiro menu	
			
			// Mostrar
			case 4:system("cls");
				break;
			
			// Default
			default:system("cls");
				printf("\n Escolha invalida.\n");
				break;
		}
				
	} while (choice5 != 4);
}

// Menu para buscar valor
void menu6(void){
	int choice6;
	do{
		system("cls");
		cabecalho();
		posicao(30,3);printf("  1. Buscar na tabela A\n");
		posicao(30,4);printf("  2. Buscar na tabela B\n");
		posicao(30,5);printf("  3. Buscar na tabela C\n");
		posicao(30,6);printf("  4. Voltar");
		base(8);
		posicao(30,9);printf("\n Opcao: ");
		posicao(30,10);scanf("%d",&choice6);
		
		switch(choice6){
			// buscar na tabela A
			case 1: system("cls");
				if(verificaTabela(vetA) == 0){
					cabecalho();
					posicao(30,3);printf("\t\tTabela inexistente\n\n");
					base(5);
					choice6 = 4;
					
				}else{
					cabecalho();
					posicao(30,3);printf("   Valor a ser buscado: ");
					base(5);
					posicao(57,3);scanf("%d", &x);
					system("cls");
					cabecalho();
					if(queroBuscar(x, vetA) == 1){
						posicao(30,3);printf("   Valor %d existe!\n", x);
					}else{
						posicao(30,3);printf("   Valor %d nao existe!\n", x);
					}
					base(5);
					system("pause");
					system("cls");
					choice6 = 4;
				}
				break;
				
			// buscar na tabela B
			case 2: system("cls");
				if(verificaTabela(vetB) == 0){
					cabecalho();
					posicao(30,3);printf("\t\tTabela inexistente\n\n");
					base(5);
					choice6 = 4;
					
				}else{
					cabecalho();
					posicao(30,3);printf("   Valor a ser buscado: ");
					base(5);
					posicao(57,3);scanf("%d", &x);
					system("cls");
					cabecalho();
					if(queroBuscar(x, vetB) == 1){
						posicao(30,3);printf("   Valor %d existe!\n", x);
					}else{
						posicao(30,3);printf("   Valor %d nao existe!\n", x);
					}
					base(5);
					system("pause");
					system("cls");
					choice6 = 4;
				}
				break;
				
			// buscar na tabela C
			case 3: system("cls");
				if(verificaTabela(vetC) == 0){
					cabecalho();
					posicao(30,3);printf("\t\tTabela inexistente\n\n");
					base(5);
					choice6 = 4;
					
				}else{
					cabecalho();
					posicao(30,3);printf("   Valor a ser buscado: ");
					base(5);
					posicao(57,3);scanf("%d", &x);
					system("cls");
					cabecalho();
					if(queroBuscar(x, vetC) == 1){
						posicao(30,3);printf("   Valor %d existe!\n", x);
					}else{
						posicao(30,3);printf("   Valor %d nao existe!\n", x);
					}
					base(5);
					system("pause");
					system("cls");
					choice6 = 4;
				}
				break;
			
			// Sair
			case 4:system("cls");
				break;
			
			// Default
			default:system("cls");
				printf("\n Escolha invalida.\n");
				break;
		}
				
	} while (choice6 != 4);
}

// Menu main
void menu(void){
	
	int choice;
	int contador = 0;
	
	do{
		system("cls");
		cabecalho();
		posicao(30,3);printf("   1. Criar tabela\n");
		posicao(30,4);printf("   2. Mostrar tabela\n");
		posicao(30,5);printf("   3. Unir tabelas\n");
		posicao(30,6);printf("   4. Adicionar valor na tabela\n");
		posicao(30,7);printf("   5. Excluir valor da tabela\n");
		posicao(30,8);printf("   6. Buscar valor\n");
		posicao(30,9);printf("   7. Sair\n");
		base(11);
		posicao(30,12);printf("Opcao: ");
		posicao(30,13);scanf("%d",&choice);
		
		switch(choice){
			// Criar tabela
			case 1: system("cls");
				// Se nenhuma tabela
				if(contador == 0){
					criarTabela(vetA);
					printf("\n");
					cabecalho();
					posicao(30,3);printf("\t\tTabela A criada!");
					base(5);
					contador++;
				}
				// Se uma tabela
				else if(contador == 1){
					criarTabela(vetB);
					printf("\n");
					cabecalho();
					posicao(30,3);printf("\t\tTabela B criada!");
					base(5);
					contador++;
				}
				// Se duas tabelas
				else{
					printf("\n");
					cabecalho();
					posicao(30,3);printf("\t   Tabela A e B ja existentes.");
					printf("\n");
					printf("\n");
					base(5);
				}
				system("pause");
				system("cls");
				break;
				
			// Mostrar tabela
			case 2: system("cls");
				menu2();
				system("pause");
				system("cls");
				break;
				
			// Unir tabelas
			case 3:system("cls");
				menu3();
				system("pause");
				system("cls");
				break;
			
			// Adicionar valor na tabela
			case 4: system("cls");
				menu5();
				system("pause");
				system("cls");
				break;
				
			// Excluir valor da tabela
			case 5: system("cls");
				menu4();
				system("pause");
				system("cls");
				break;
				
			// Adicionar valor tabela c
			case 6: system("cls");
				
				menu6();
				system("pause");
				system("cls");
				break;
				
			// Sair
			case 7:system("cls");
				
				break;

			
			// Default
			default:
				posicao(30,16);printf("Escolha invalida.\n\n");
				system("pause");
				system("cls");
				break;
		}
	} while (choice != 7);
	
}
	
	// trabalho tabela hash

int main(){
	
	menu();  // roda o programa, chamando o menu

}