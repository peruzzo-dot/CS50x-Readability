#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 1. Verificar se o programa foi executado com apenas um argumento (a chave)
    if (argc != 2)
    {
        printf("Uso: ./caesar chave\n");
        return 1; // Retornar 1 indica erro
    }

    // 2. Verificar se cada caractere da chuva (argv[1]) é um número
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Uso: ./caesar chave (deve ser um número positivo)\n");
            return 1;
        }
    }

    // 3. Converter a chave de string para int
    int k = atoi(argv[1]);

    // 4. Pedir o texto original (plaintext) ao usuário
    string plaintext = get_string("plaintext: ");

    // 5. Criptografar e imprimir o resultado (ciphertext)
    printf("ciphertext: ");

    for (int j = 0, length = strlen(plaintext); j < length; j++)
    {
        // Se for letra maiúscula
        if (isupper(plaintext[j]))
        {
            // Transforma o caractere ASCII para 0-25 (subtraindo 'A')
            // Aplica a fórmula e volta para ASCII (somando 'A')
            printf("%c", (plaintext[j] - 'A' + k) % 26 + 'A');
        }
        // Se for letra minúscula
        else if (islower(plaintext[j]))
        {
            // Transforma o caractere ASCII para 0-25 (subtraindo 'a')
            // Aplica a fórmula e volta para ASCII (somando 'a')
            printf("%c", (plaintext[j] - 'a' + k) % 26 + 'a');
        }
        // Se não for letra (espaço, ponto, etc), imprime como está
        else
        {
            printf("%c", plaintext[j]);
        }
    }

    printf("\n");
    return 0;
}
