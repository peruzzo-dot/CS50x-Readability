#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 1. Verificar se há exatamente 1 argumento (a chave)
    if (argc != 2)
    {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    string key = argv[1];

    // 2. Verificar se a chave tem 26 caracteres
    if (strlen(key) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }

    // 3. Verificar se todos os caracteres são letras e se não há repetidos
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("A chave deve conter apenas letras.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("A chave não deve conter letras repetidas.\n");
                return 1;
            }
        }
    }

    // 4. Pedir o texto ao usuário
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    // 5. Loop para substituir cada letra
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Calcula o índice (A=0, B=1...) e busca na chave
            int index = plaintext[i] - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            // Se não for letra, imprime igual (espaços, vírgulas)
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}
