// tabela hash, estrutura de dados 2

struct No {
    
    int data;
    struct No *prox;
};

typedef struct No No;

/***********************************
*****    FUNÇÕES DO TIPO NO    *****
***********************************/

No* criarNo(int value);
No* pilh (No* ptr);

/***********************************
*****   FUNÇÕES DE ESTRUTURA   *****
***********************************/

void criarTabela(No vet[]);
void inserir(int value, No vet[]);
void unir(No vet1[],No vet2[],No vet3[]);
void juntar(No vet1[], No vet2[]);
void excluirFeatLaurinho(int value, No vet[]);
void meuUnir(No vet1[], No vet2[]);


/***********************************
*****    FUNÇÕES AUXILIARES    *****
***********************************/

void imprimirTeste(No vet[]);
void posicao(int x, int y);
int hash(int value);
int verificaTabela(No vet[]);
int queroBuscar(int value, No vet[]);
void cabecalho();
void base(int var);
int meuContar(No vet1[], int aux);
void meuUnir(No vet1[], No vet2[]);
void meuSegundoUnir(No vet1[], No vet2[]);
void meuUnirAuxiliar(No vet1[], No vet2[], int i);