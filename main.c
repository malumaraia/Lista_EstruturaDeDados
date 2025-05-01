#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 1
int calcularFatorial(int numero) {
    return (numero <= 1) ? 1 : numero * calcularFatorial(numero - 1);
}

// 2
int somatorioNatural(int valor) {
    return (valor <= 1) ? 1 : valor + somatorioNatural(valor - 1);
}

// 3
int calcularFibonacci(int termo) {
    return (termo <= 1) ? 1 : calcularFibonacci(termo - 1) + calcularFibonacci(termo - 2);
}

// 4
int elevarPotencia(int base, int expoente) {
    return (expoente == 0) ? 1 : base * elevarPotencia(base, expoente - 1);
}

// 5
int imprimirRegressivo(int contador) {
    if (contador <= 0) return 0;
    printf("%d ", contador);
    return imprimirRegressivo(contador - 1);
}

// 6
int somarDigitos(int numero) {
    return (numero == 0) ? 0 : (numero % 10) + somarDigitos(numero / 10);
}

// 7
void inverterTexto(char texto[], int inicio, int tamanho) {
    if (inicio >= tamanho / 2) return;
    char tmp = texto[inicio];
    texto[inicio] = texto[tamanho - inicio - 1];
    texto[tamanho - inicio - 1] = tmp;
    inverterTexto(texto, inicio + 1, tamanho);
}

// 8
int verificarPalindromo(const char *palavra, int ini, int fim) {
    if (ini >= fim) return 1;
    if (palavra[ini] != palavra[fim]) return 0;
    return verificarPalindromo(palavra, ini + 1, fim - 1);
}

// 9
int calcularMDC(int x, int y) {
    return (y == 0) ? x : calcularMDC(y, x % y);
}

// 10
int multiplicarRec(int fator1, int fator2) {
    return (fator2 == 0) ? 0 : fator1 + multiplicarRec(fator1, fator2 - 1);
}

// 11
int contarCaracter(const char *texto, char caractere) {
    return (*texto == '\0') ? 0 : (*texto == caractere) + contarCaracter(texto + 1, caractere);
}

// 12
int somarVetor(int vetor[], int tam, int posicao) {
    return (posicao == tam) ? 0 : vetor[posicao] + somarVetor(vetor, tam, posicao + 1);
}

// 13 && 14
int auxiliarPrimo(int numero, int divisor) {
    if (divisor * divisor > numero) return 1;
    if (numero % divisor == 0) return 0;
    return auxiliarPrimo(numero, divisor + 1);
}
int verificarPrimo(int numero) {
    if (numero <= 1) return 0;
    return auxiliarPrimo(numero, 2);
}

// 15
void converterParaBinario(int numero) {
    if (numero == 0) return;
    converterParaBinario(numero / 2);
    printf("%d", numero % 2);
}

// 16
void exibirPares(int limite) {
    if (limite < 0) return;
    exibirPares(limite - 2);
    if (limite % 2 == 0) printf("%d ", limite);
}

// 17
void exibirImpares(int limite) {
    if (limite <= 0) return;
    exibirImpares(limite - 2);
    if (limite % 2 == 1) printf("%d ", limite);
}

// 18
int buscarElemento(int vetor[], int tam, int alvo, int pos) {
    if (pos == tam) return 0;
    if (vetor[pos] == alvo) return 1;
    return buscarElemento(vetor, tam, alvo, pos + 1);
}

// 19
int tamanhoTexto(const char *texto) {
    return (*texto == '\0') ? 0 : 1 + tamanhoTexto(texto + 1);
}

// 20
void resolverHanoi(int discos, char origem, char destino, char aux) {
    if (discos == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    resolverHanoi(discos - 1, origem, aux, destino);
    printf("Mover disco %d de %c para %c\n", discos, origem, destino);
    resolverHanoi(discos - 1, aux, destino, origem);
}

//20
void trocarCaracteres(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void gerarPermutacoes(char *texto, int inicio, int fim) {
    if (inicio == fim) {
        printf("%s\n", texto);
        return;
    }
    for (int indice = inicio; indice <= fim; indice++) {
        trocarCaracteres(&texto[inicio], &texto[indice]);
        gerarPermutacoes(texto, inicio + 1, fim);
        trocarCaracteres(&texto[inicio], &texto[indice]);  
    }
}

int main() {
    int resultado;

    resultado = calcularFatorial(5);
    printf("1. Fatorial: %d\n", resultado);

    resultado = somatorioNatural(5);
    printf("2. Soma natural: %d\n", resultado);

    resultado = calcularFibonacci(5);
    printf("3. Fibonacci: %d\n", resultado);

    resultado = elevarPotencia(2, 3);
    printf("4. Potência: %d\n", resultado);

    printf("5. Regressivo: ");
    imprimirRegressivo(5);
    printf("\n");

    resultado = somarDigitos(1234);
    printf("6. Soma dos dígitos: %d\n", resultado);

    char palavraInvertida[] = "recursao";
    inverterTexto(palavraInvertida, 0, strlen(palavraInvertida));
    printf("7. String invertida: %s\n", palavraInvertida);

    char pal[] = "radar";
    printf("8. Verificando se '%s' é palíndromo: %s\n", pal,
           verificarPalindromo(pal, 0, strlen(pal) - 1) ? "Sim" : "Não");

    resultado = calcularMDC(48, 18);
    printf("9. MDC: %d\n", resultado);

    resultado = multiplicarRec(3, 4);
    printf("10. Multiplicação: %d\n", resultado);

    resultado = contarCaracter("banana", 'a');
    printf("11. Ocorrências de 'a': %d\n", resultado);

    int vetor1[] = {1, 2, 3, 4, 5};
    resultado = somarVetor(vetor1, 5, 0);
    printf("12. Soma array: %d\n", resultado);

    resultado = verificarPrimo(7);
    printf("13. É primo: %s\n", resultado ? "Sim" : "Não");

    printf("14. Binário de 10: ");
    converterParaBinario(10);
    printf("\n");

    printf("15. Pares até 10:\n");
    exibirPares(10);
    printf("\n16. Ímpares até 9:\n");
    exibirImpares(9);
    printf("\n");

    int vetor2[] = {1, 2, 3};
    resultado = buscarElemento(vetor2, 3, 2, 0);
    printf("17. Busca elemento 2: %s\n", resultado ? "Encontrado" : "Não encontrado");

    resultado = tamanhoTexto("exemplo");
    printf("18. Comprimento da string: %d\n", resultado);

    printf("19. Torre de Hanoi (3 discos):\n");
    resolverHanoi(3, 'A', 'C', 'B');
    
    char palavra[] = "abc";
    printf("20. Permutações de '%s':\n", palavra);
    gerarPermutacoes(palavra, 0, strlen(palavra) - 1);

    return 0;
}
