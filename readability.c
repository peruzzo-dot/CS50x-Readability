#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // 1. Solicitar o texto ao usuário
    string texto = get_string("Text: ");

    // 2. Inicializar contadores
    int letras = 0;
    int palavras = 1;
    int frases = 0;

    // 3. Loop para analisar o texto
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        // Conta letras
        if (isalpha(texto[i]))
        {
            letras++;
        }
        // Conta palavras
        else if (isspace(texto[i]))
        {
            palavras++;
        }
        // Conta frases
        else if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            frases++;
        }
    }

    // 4. Calcular o índice (Coleman-Liau)
    float L = (float) letras / palavras * 100;
    float S = (float) frases / palavras * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // 5. Imprimir o resultado
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
