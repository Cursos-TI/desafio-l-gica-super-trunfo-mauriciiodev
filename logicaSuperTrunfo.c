#include <stdio.h>  // Para printf, scanf, getchar, EOF
#include <string.h> // Para strcpy (não usado diretamente aqui, mas bom ter para manipulação de strings)

// Função para limpar o buffer de entrada (stdin)
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Comentário: Definindo os dados da Carta 1 (Ex: Brasil)
    char nomePais1[50] = "Brasil";
    char codigoCarta1[5] = "BR01"; // Adicionado um espaço extra para o terminador nulo
    int populacao1 = 210000000;
    float area1 = 8515767.0f;    // km²
    float pibBilhoes1 = 1800.0f; // Em bilhões de USD (exemplo)
    int numPontosTuristicos1 = 1500;
    float densidadeDemografica1;
    float pibPerCapita1;

    // Comentário: Definindo os dados da Carta 2 (Ex: Argentina)
    char nomePais2[50] = "Argentina";
    char codigoCarta2[5] = "AR01";
    int populacao2 = 45000000;
    float area2 = 2780400.0f;    // km²
    float pibBilhoes2 = 450.0f; // Em bilhões de USD (exemplo)
    int numPontosTuristicos2 = 700;
    float densidadeDemografica2;
    float pibPerCapita2;

    // Comentário: Calculando Densidade Demográfica e PIB per Capita para a Carta 1
    if (area1 > 0.000001f) { // Evitar divisão por área muito pequena ou zero
        densidadeDemografica1 = (float)populacao1 / area1;
    } else {
        densidadeDemografica1 = 0.0f; // Ou um valor indicando densidade "infinita" se pop > 0
    }

    if (populacao1 > 0) {
        pibPerCapita1 = (pibBilhoes1 * 1000000000.0f) / (float)populacao1;
    } else {
        pibPerCapita1 = 0.0f;
    }

    // Comentário: Calculando Densidade Demográfica e PIB per Capita para a Carta 2
    if (area2 > 0.000001f) {
        densidadeDemografica2 = (float)populacao2 / area2;
    } else {
        densidadeDemografica2 = 0.0f;
    }

    if (populacao2 > 0) {
        pibPerCapita2 = (pibBilhoes2 * 1000000000.0f) / (float)populacao2;
    } else {
        pibPerCapita2 = 0.0f;
    }

    // Comentário: Exibindo os dados completos das cartas (informativo)
    printf("--- Carta 1: %s (%s) ---\n", nomePais1, codigoCarta1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pibBilhoes1);
    printf("Pontos Turísticos: %d\n", numPontosTuristicos1);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadeDemografica1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);

    printf("\n--- Carta 2: %s (%s) ---\n", nomePais2, codigoCarta2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pibBilhoes2);
    printf("Pontos Turísticos: %d\n", numPontosTuristicos2);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadeDemografica2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);

    int escolha;
    do {
        // Comentário: Apresentando o menu interativo para o usuário
        printf("\n\n--- Super Trunfo - Escolha o Atributo para Comparar ---\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Número de Pontos Turísticos\n");
        printf("5. Densidade Demográfica\n");
        printf("0. Sair do Jogo\n");
        printf("Digite sua escolha: ");

        // Comentário: Lendo a escolha do usuário e validando a entrada
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada inválida. Por favor, digite um número correspondente à opção.\n");
            limpar_buffer_entrada(); // Limpa o buffer em caso de entrada não numérica
            escolha = -1; // Define uma escolha inválida para continuar no loop ou exibir erro
        } else {
            limpar_buffer_entrada(); // Limpa o restante da linha (ex: se o usuário digitou "1abc")
        }

        // Comentário: Estrutura switch para processar a escolha do usuário
        switch (escolha) {
            case 1: // População
                printf("\n--- Comparando por População ---\n");
                printf("%s: %d habitantes\n", nomePais1, populacao1);
                printf("%s: %d habitantes\n", nomePais2, populacao2);
                if (populacao1 > populacao2) {
                    printf("Vencedor: %s!\n", nomePais1);
                } else if (populacao2 > populacao1) {
                    printf("Vencedor: %s!\n", nomePais2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 2: // Área
                printf("\n--- Comparando por Área ---\n");
                printf("%s: %.2f km²\n", nomePais1, area1);
                printf("%s: %.2f km²\n", nomePais2, area2);
                if (area1 > area2) {
                    printf("Vencedor: %s!\n", nomePais1);
                } else if (area2 > area1) {
                    printf("Vencedor: %s!\n", nomePais2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 3: // PIB
                printf("\n--- Comparando por PIB (em bilhões) ---\n");
                printf("%s: %.2f bilhões\n", nomePais1, pibBilhoes1);
                printf("%s: %.2f bilhões\n", nomePais2, pibBilhoes2);
                if (pibBilhoes1 > pibBilhoes2) {
                    printf("Vencedor: %s!\n", nomePais1);
                } else if (pibBilhoes2 > pibBilhoes1) {
                    printf("Vencedor: %s!\n", nomePais2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 4: // Número de Pontos Turísticos
                printf("\n--- Comparando por Número de Pontos Turísticos ---\n");
                printf("%s: %d\n", nomePais1, numPontosTuristicos1);
                printf("%s: %d\n", nomePais2, numPontosTuristicos2);
                if (numPontosTuristicos1 > numPontosTuristicos2) {
                    printf("Vencedor: %s!\n", nomePais1);
                } else if (numPontosTuristicos2 > numPontosTuristicos1) {
                    printf("Vencedor: %s!\n", nomePais2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 5: // Densidade Demográfica (MENOR vence)
                printf("\n--- Comparando por Densidade Demográfica ---\n");
                printf("%s: %.2f hab/km²\n", nomePais1, densidadeDemografica1);
                printf("%s: %.2f hab/km²\n", nomePais2, densidadeDemografica2);
                if (densidadeDemografica1 < densidadeDemografica2) {
                    printf("Vencedor: %s!\n", nomePais1);
                } else if (densidadeDemografica2 < densidadeDemografica1) {
                    printf("Vencedor: %s!\n", nomePais2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 0: // Sair
                printf("\nObrigado por jogar Super Trunfo! Saindo...\n");
                break;

            default: // Opção inválida
                if (escolha != -1) { // Evita mensagem duplicada se scanf falhou
                   printf("\nOpção inválida. Por favor, escolha uma opção do menu.\n");
                }
                break;
        } // Fim do switch

    } while (escolha != 0); // Comentário: Loop continua até o usuário escolher sair (opção 0)

    return 0; // Indica que o programa terminou com sucesso
}