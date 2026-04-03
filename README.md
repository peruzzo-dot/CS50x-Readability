# Readability - CS50

Este projeto foi desenvolvido como parte do curso **CS50 Introduction to Computer Science da Harvard University**.

### 📝 Descrição
O programa calcula o índice de legibilidade de um texto utilizando a fórmula de **Coleman-Liau**. Ele analisa a quantidade de letras, palavras e frases para determinar o nível escolar necessário para compreender o conteúdo.

### 🛠️ Tecnologias Utilizadas
- Linguagem C
- Biblioteca CS50 (`cs50.h`)
- Lógica de manipulação de strings e arredondamento matemático.

### 🚀 Como funciona
A fórmula aplicada é: $0.0588 * L - 0.296 * S - 15.8$
Onde **L** é a média de letras por 100 palavras e **S** é a média de frases por 100 palavras.
