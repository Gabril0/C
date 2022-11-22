#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void printVetor(int* v, int n){
    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d",v[i]);
                if(i!=9) printf(",");}
            printf("}");
}

void bubbleSort(int* v, int n)
{
    int i, aux, fim, troca;
    fim = n;
    printf("\n==Bubble Sort==");
    
    printf("\nCria uma var troca e atribui -1");
    printf("\nFaz um loop que verifica se v[i] eh maior que v[i+1]");
    printf("\nAtribui troca o valor de i caso ocorra uma troca(v[i]<v[i+1])");
    printf("\nDo while verifica se troca continua -1");
    printf("\nAcaba o loop quando nao ocorre uma troca, pois o valor nao seria alterado dentro do for");
    printf("\nSempre diminui um do valor de fim a cada ciclo(fora do for)");
    printf("\nInicio do vetor: ");
    printVetor(v,n);
    do{
        troca = -1;
        for(i=0;i<fim - 1;i++)
        { //troca sempre que o elemento da esquerda for maior
            if(v[i]>v[i+1])//realiza a troca
            {
            printf("\nInstancia: %d do vetor: ",i);
            printVetor(v,n);
            aux = v[i]; v[i] = v[i+1]; v[i+1] = aux;
            troca = i;//marca se houve a troca
            }
        }
    fim--;
    }while(troca!=-1);//enquanto tiver acontecido troca
    printf("\n!!RESUMO: joga o numero inicial do inicio do vetor para o final enquanto ele for maior que o proximo");
}

void selectionSort(int* v, int n)
{
    int i, j, menor, aux;
    printf("\n==Selection Sort==");
    printf("\nInicia atribuindo a var menor o valor de i em si dentro do for");
    printf("\nCria se outro for e procura se tem um valor menor na direita");
    printf("\nSe tiver um menor, substitui pela posicao em j");
    printf("\nSe i for diferente do menor entao ele troca os valores");
    printf("\nInicio do vetor: ");
    printVetor(v,n);
    for(i=0;i<n - 1;i++)
        { menor = i;
        for(j=i+1;j<n;j++)//procurando se tem menor à direita
            { //atualiza a posição do novo menor
            if(v[j]<v[menor]) menor = j;
            printf("\nInstancia: %d do vetor: ",i);
            printVetor(v,n);
            }
            if(i!=menor)//encontrou um elemento menor à direita
            {//realiza a troca
            printf("\nInstancia: %d do vetor: ",i);
            printVetor(v,n);
            aux = v[menor]; v[menor] = v[i]; v[i] = aux;
        }
    }
    printf("\n!!RESUMO: percorre todos os elementos ate achar o menor comparando com o primeiro, depois disso compara ele");
    printf("depois faz a mesma coisa a partir do j 2");
}

void insertionSort(int* v, int n)
{
    int i, j, aux;
    printf("\n==Insertion Sort==");
    printf("\nComeca na segunda posicao e compara se existe alguem maior na direita, enquanto existir duplica e substitui");
    printf("\n**note que so troca quando j>0 e v[j-1] > aux e diminui um dos j");
    printf("\nInicio do vetor: ");
    printVetor(v,n);
    for(i=1; i<n; i++){//vai da segunda posição em diante
        aux = v[i];
        j = i;
        while(j>0 && v[j-1] > aux)//enqto existe alguém maior
            { //que aux, faz o deslocamento para direita
            v[j] = v[j-1]; j--;//duplicando esse elemento
        }
        v[j] = aux;//local correto em que posso substituir
        printf("\nInstancia: %d do vetor: ",i);
        printVetor(v,n);
    }
    printf("\n!!RESUMO: Faz uma comparacao com os numeros da direita a cada ciclo, fazendo com que a cada i termos");
    printf("ele ordene esses i+1 termos pela comparacao e duplicando os fora de ordem e subsstituindo logo depois,");
    printf("por exemplo, no i = 4 os 5 primeiros elementos vao estar ordenados");
}

int buscaLinear(int* v, int n, int x)
{
    int i;
    printf("\n==Busca Linear==");
    printf("\nRoda um loop enquanto o valor procurado nao for igual a v[i], quando acha, retorna o i(i+1 se nao for a posicao do vetor)");
    printf("\nInicio do vetor: ");
    printVetor(v,10);
    for(i=0;i<n;i++)
    {   
        printf("\nX = %d e v[i] = %d",x,v[i]);
        if(x==v[i]) return i+1;
    }
    return -1;
}

int buscaOrdenada(int* v, int n, int x)
{
    int i = 0;
    printf("\n==Busca Ordenada==");
    printf("\nVerifica enquanto nao estiver no final e o n v[i] for menor que n, se for igual ele retorna a posicao");
    printf("\n**Dica: Para quem esta confuso, esse parece bastante o linear mas utiliza do fato da lista estar ordenada para fazer a verificacao de menor");
    printf("\nInicio do vetor: ");
    printVetor(v,10);
    while(i<n && v[i] < x) {printf("\nX = %d e v[i] = %d",x,v[i]);i++;}
    if(x==v[i]) return i+1;
    else return -1;
}

int buscaBinaria(int* v, int n, int x)
{
    int inicio, fim, meio;
    inicio = 0;
    fim = n-1;
    printf("\n==Busca Binaria==");
    printf("\nEscolhe o inicio e o final, apos isso acha o meio(meio = (inicio + fim)/2)), entao faz dois if's para");
    printf(" para comparar se x eh menor que o elemento do meio pela esquerda, apos isso faz fim = meio - 1");
    printf(" caso nao encontre ele vai para a direita mudando de menor para maior e de fim para inicio");
    printf("\nInicio do vetor: ");
    printVetor(v,10);
    while(inicio<=fim)
    {
        
        meio = (inicio + fim)/2;
        printf("\nX = %d e v[i] = %d",x,v[meio]);
        if(x<v[meio]) fim = meio - 1;//metade esquerda
        else
    {
        if(x>v[meio]) inicio = meio + 1;//metade direita
        else return (meio+1);
    }
    } return -1;
    printf("!!RESUMO: Pega a lista ordenada e divide ao meio, entao compara, se for diferente entao quebra ao meio de novo e compara novamente");
    printf(" sempre quebrando ao meio a direita se o procurado for maior e a esquerda se ainda for menor, faz isso enquanto inicio<=final");
}

int main(){
    int op;
    while(1){
    printf("\n\n=== Revisao ED2 ===");
    printf("\nSelecione a explicacao da ED desejada");
    printf("\n1.Bubble Sort                     (melhor:n, medio:n^2, pior: n^2)");
    printf("\n2.Selection Sort                  (melhor:n^2, medio:n^2, pior: n^2)");
    printf("\n3.Insertion Sort                  (melhor:n, medio:n^2, pior: n^2)");
    printf("\n4.Busca Sequencial ou Linear      (melhor:1, medio:n, pior: n)");
    printf("\n5.Busca Ordenada                  (melhor:1, medio:n, pior: n)");
    printf("\n6.Busca Binaria                   (melhor:1, medio:log n, pior: log n)");
    printf("\n9.Links recomendados");
    printf("\n0.Sair");
    printf("\nOpcao: ");
    scanf("%d", &op);
    switch(op){
        case(1):{
            int vetorBubble [10] = {9,8,7,6,5,4,3,2,1,0};
            bubbleSort(vetorBubble,10);
            printf("\n");
            printf("Resultado: ");
            printVetor(vetorBubble,10);
            break;
        }
        case(2):{
            int vetorSelection[10] = {9,8,7,6,5,4,3,2,1,0};
            selectionSort(vetorSelection,10);
            printf("\n");
            printf("Resultado: ");
            printVetor(vetorSelection,10);
            break;
        }
        case(3):{
            int vetorInsertion[10] = {9,8,7,6,5,4,3,2,1,0};
            insertionSort(vetorInsertion,10);
            printf("\n");
            printf("Resultado: ");
            printVetor(vetorInsertion,10);
            break;
        }
        case(4):{
            int vetorSequencial[10] = {9,8,7,6,5,4,3,2,1,0};
            printf("\n");
            printf("\nResultado: posicao %d!!",buscaLinear(vetorSequencial,10,5));
            break;
        }
        case(5):{
            int vetorOrdenada[10] = {0,1,2,3,4,5,6,7,8,9};
            printf("\n");
            printf("\nResultado: posicao %d!!",buscaOrdenada(vetorOrdenada,10,5));
            break;
        }
        case(6):{
            int vetorBinario[10] = {0,1,2,3,4,5,6,7,8,9};
            printf("\n");
            printf("\nResultado: posicao %d!!",buscaBinaria(vetorBinario,10,9));
            break;
        }
        case(9):{
            printf("\nhttps://www.programiz.com/dsa/bubble-sort");
            printf("\nhttps://www.programiz.com/dsa/selection-sort");
            printf("\nhttps://www.programiz.com/dsa/insertion-sort");
            printf("\nhttps://www.programiz.com/dsa/linear-search");
            printf("\nhttps://www.programiz.com/dsa/binary-search");
            printf("\n");
            printf("\n");
            printf("\nhttps://www.programiz.com/dsa/divide-and-conquer");
            break;

        }
        case(0):{return 0;}
        default:{printf("Erro no numero digitado");}
        }
    }
    return 0;
}