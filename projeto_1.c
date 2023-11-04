#include <stdio.h>
#include <string.h>
#define TAMANHO 504

// Protótipos das funções
void operacoes(int o, char num1[], char num2[]);
void add(char num1[TAMANHO], char num2[TAMANHO]);
void sub(char num1[TAMANHO], char num2[TAMANHO]);
void multi(char num1[TAMANHO], char num2[TAMANHO]);

int main(void) {
    //leitura do n
    int n;
    scanf("%d", &n);
    // Limpar o buffer de entrada
    while ((getchar()) != '\n');
    
    //laço de repetição para n casos
    for (int i = 0; i < n; i++) {
        char num1[TAMANHO];
        char num2[TAMANHO];
        int o;
        //será feita a leitura do num1, num2 e do numero de casos "o"
        scanf("%s", num1);
        scanf("%s", num2);
        scanf("%d", &o);
        //será realizada a operação e o resultado sera printado
        operacoes(o, num1, num2);
    }

    return 0;
}

// Função para executar a operação selecionada
void operacoes(int o, char num1[], char num2[]) {
    switch (o) {
    case 1:
        //soma dos numeros
        add(num1, num2);
        break;

    case 2:
        //subtração dos numeros
        sub(num1, num2);
        break;

    case 3:
        //multiplicação dos números
        multi(num1, num2);
        break;
    }
}

// Função para adição de números
void add(char num1[TAMANHO], char num2[TAMANHO]) {
    char res[TAMANHO + 1];
    int i = strlen(num1);
    int j = strlen(num2);
    int carry = 0; // Variável para guardar o carry (vai para o próximo dígito)

    // Inicialize o resultado como uma string vazia
    res[0] = '\0';

    while (i > 0 || j > 0 || carry > 0) {
        //retirada do 0 para transformar em "decimal" 
        int dg1 = (i > 0) ? (num1[--i] - '0') : 0;
        int dg2 = (j > 0) ? (num2[--j] - '0') : 0;
        
        int soma = dg1 + dg2 + carry;// faz a soma
        carry = soma / 10; //define o valor do carry

        // Concatena o dígito resultante à esquerda do resultado
        char dgChar[2];
        sprintf(dgChar, "%d", soma % 10);
        strcat(res, dgChar);
    }

    // Inverta a string resultado (a soma começa da direita para a esquerda)
    int len = strlen(res);
    for (int k = 0; k < len / 2; k++) {
        char temp = res[k]; //seleciona o numero que será invertido
        res[k] = res[len - k - 1]; //o numero do começo vai pro final
        res[len - k - 1] = temp;//o res recebe o temp que é o numero já invertido
    }
    printf("%s\n", res);
}

// Função para subtração de números
void sub(char num1[TAMANHO], char num2[TAMANHO]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    char res[TAMANHO];
    int Negativo = 0; // Variável para indicar se o resultado é negativo

    // Verifica se num1 é igual a num2
    if (len1 == len2 && strcmp(num1, num2) == 0) {
        printf("0\n");
        return; // Retorna imediatamente com o resultado 0
    }

    // Verifica se num1 é maior que num2; se sim, troque-os
    if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0)) {
        char temp[TAMANHO]; //processo para inverter os algarismo para realizar a conta negativa
        strcpy(temp, num1);
        strcpy(num1, num2);
        strcpy(num2, temp);
        int aux = len1;
        len1 = len2;
        len2 = aux;
        Negativo = 1;
    }

    int i = len1 - 1;
    int j = len2 - 1;
    int carry = 0; // Variável de empréstimo
    int k = 0; // Índice da string de resultado

    // Realiza a subtração
    while (i >= 0 || j >= 0) {
        // transforma o numero para "decimal"
        int dg1 = i >= 0 ? (num1[i] - '0') : 0;
        int dg2 = j >= 0 ? (num2[j] - '0') : 0;

        int sub = dg1 - dg2 - carry; // Subtração com o carry

        if (sub < 0) { //se for negativa corrijo o numero e coloco carry = 1
            sub += 10;
            carry = 1;
        } else {    //se for positivo carry = 0
            carry = 0;
        }

        res[k++] = sub + '0';

        i--;
        j--;
    }

    // Remove os zeros à esquerda no resultado
    while (k > 0 && res[k - 1] == '0') {
        k--;
    }

    // Inverte o resultado
    for (int z = 0; z < k / 2; z++) {
        char temp = res[z]; //seleciona o numero que será invertido
        res[z] = res[k - z - 1]; //o numero do começo vai pro final
        res[k - z - 1] = temp; //o res recebe o temp que é o numero já invertido
    }

    // Adiciona o caractere nulo ao final da string resultante
    res[k] = '\0';

    if (Negativo) {
        printf("-%s\n", res); // Imprime com o sinal negativo
    } else {       
        printf("%s\n", res); // Imprime com o sinal positivo
    }
}

// Função para multiplicação de números
void multi(char num1[TAMANHO], char num2[TAMANHO]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // O resultado da multiplicação terá no máximo len1 + len2 dígitos.
    char res[TAMANHO * 2] = {0}; // Inicialize com zeros.

    // Realiza a multiplicação
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0; // Variável de transporte para a próxima coluna
        int dg1 = num1[i] - '0';

        for (int j = len2 - 1; j >= 0; j--) {
            int dg2 = num2[j] - '0';
            int produto = dg1 * dg2 + carry + res[i + j + 1];
            carry = produto / 10;
            res[i + j + 1] = produto % 10;
        }

        // Após o loop interno, a variável de transporte é adicionada à coluna esquerda.
        res[i] = carry;
    }

    // Encontre o primeiro dígito não zero (o resultado pode começar com zeros).
    int k = 0;
    while (k < len1 + len2 && res[k] == 0) {
        k++;
    }

    // Se não houver dígitos significativos, o resultado é 0.
    if (k == len1 + len2) {
        printf("0\n");
    } else {
        // Imprima os dígitos significativos do resultado.
        for (int i = k; i < len1 + len2; i++) {
            printf("%d", res[i]);
        }
    }
}
