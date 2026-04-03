#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // 1. Pedir o texto ao usuário
    string text = get_string("Text: ");

    // 2. Contar letras, palavras e frases
    int letters = 0;
    int words = 1; // Começamos com 1 porque a última palavra não tem espaço depois
    int sentences = 0;

    // 3. O Loop para analisar o texto
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Conta letras: verifica se o caractere atual é alfabético
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Conta palavras: assume que uma nova palavra começa após um espaço
        else if (text[i] == ' ')
        {
            words++;
        }
        // Conta frases: verifica pontos finais, exclamação ou interrogação
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    // L = média de letras por 100 palavras
    float L = (float) letters / words * 100;
    // S é a média de frases por 100 palavras
    float S = (float) sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

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
// 4. Calcular o índece (Coleman-Liau)

// 5. Imprimir o resultado (Grade x)
