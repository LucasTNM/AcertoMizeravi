# Calculadora de Operações com Números Grandes

Este programa permite realizar operações de adição, subtração e multiplicação com números grandes em formato de string. Ele foi desenvolvido em C e pode lidar com números de até 504 dígitos.

## Como Usar

Compile o programa usando um compilador C, por exemplo, o GCC:

```bash
gcc programa.c -o calculadora

1. Execute o programa:
./calculadora

2. O programa solicitará o número de casos a serem processados.

3. Para cada caso, insira os números que deseja operar e selecione a operação desejada:

*Digite o primeiro número.
*Digite o segundo número.
*Selecione a operação:
Soma = 1
Subtração = 2
Multiplicação = 3

4. O programa calculará o resultado da operação selecionada e o imprimirá na tela.

5. Repita o processo para quantos casos desejar.

Como Funciona
O programa lê os números como strings e executa as operações de adição, subtração e multiplicação com base nos dígitos dessas strings. 
Ele também lida com casos em que os resultados dos números podem ser negativos.

Exemplo de Uso
Suponha que você deseja somar os números 1234567890123456789012345678901234567890 e 9876543210987654321098765432109876543210:

1. Execute o programa.

2. Insira o número de casos (por exemplo, 1).

3. Insira o primeiro número: 1234567890123456789012345678901234567890.

4. Insira o segundo número: 9876543210987654321098765432109876543210.

5. Selecione a operação de soma (digite 1).

6. O programa calculará e imprimirá o resultado: 1111111110111111112001111111110101111111100.

Isso é apenas um exemplo de uso. O programa pode lidar com números grandes em várias operações.
