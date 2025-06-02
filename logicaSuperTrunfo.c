#include <stdio.h> // Para funções de entrada e saída como printf
#include <string.h> // Para strcpy, se necessário para nomes de atributos (não estritamente para este exemplo)

int main() {
    // Comentário: Definindo os dados da Carta 1 (São Paulo)
    char estado1[3] = "SP"; // Estado como string (2 caracteres + terminador nulo)
    char codigoCarta1[4] = "A01";
    char nomeCidade1[50] = "Sao Paulo";
    int populacao1 = 12300000; // População como int
    float area1 = 1521.11f;    // Área em km²
    float pib1_bilhoes = 699.28f; // PIB em bilhões de reais
    int numPontosTuristicos1 = 50;
    float densidadePopulacional1;
    float pibPerCapita1;

    // Comentário: Definindo os dados da Carta 2 (Rio de Janeiro)
    char estado2[3] = "RJ";
    char codigoCarta2[4] = "B01";
    char nomeCidade2[50] = "Rio de Janeiro";
    int populacao2 = 6000000;
    float area2 = 1200.25f;
    float pib2_bilhoes = 300.50f;
    int numPontosTuristicos2 = 30;
    float densidadePopulacional2;
    float pibPerCapita2;

    // Comentário: Calculando Densidade Populacional e PIB per Capita para a Carta 1
    // Assumindo que area1 e populacao1 são maiores que 0 para evitar divisão por zero.
    if (area1 > 0.0f) {
        densidadePopulacional1 = (float)populacao1 / area1;
    } else {
        densidadePopulacional1 = 0.0f; // Evita divisão por zero, define como 0
    }

    if (populacao1 > 0) {
        // PIB é dado em bilhões, converter para unidades para o cálculo per capita em reais
        pibPerCapita1 = (pib1_bilhoes * 1000000000.0f) / (float)populacao1;
    } else {
        pibPerCapita1 = 0.0f; // Evita divisão por zero, define como 0
    }

    // Comentário: Calculando Densidade Populacional e PIB per Capita para a Carta 2
    if (area2 > 0.0f) {
        densidadePopulacional2 = (float)populacao2 / area2;
    } else {
        densidadePopulacional2 = 0.0f;
    }

    if (populacao2 > 0) {
        pibPerCapita2 = (pib2_bilhoes * 1000000000.0f) / (float)populacao2;
    } else {
        pibPerCapita2 = 0.0f;
    }

    // Comentário: Exibindo os dados completos das cartas
    printf("--- Detalhes da Carta 1 ---\n");
    printf("Nome: %s (%s)\n", nomeCidade1, estado1);
    printf("Código: %s\n", codigoCarta1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1_bilhoes);
    printf("Pontos Turísticos: %d\n", numPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n--- Detalhes da Carta 2 ---\n");
    printf("Nome: %s (%s)\n", nomeCidade2, estado2);
    printf("Código: %s\n", codigoCarta2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2_bilhoes);
    printf("Pontos Turísticos: %d\n", numPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // --- Comparação de Cartas ---
    // Comentário: Atributo escolhido para comparação (hardcoded): População
    // Para outros atributos, a lógica de qual valor é "melhor" pode mudar.
    // Ex: Densidade Populacional -> menor é melhor.
    // Para este exemplo, População -> maior é melhor.

    printf("\n\nComparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, populacao2);

    // Comentário: Lógica de comparação utilizando if e if-else
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    /* // Comentário: Exemplo de como seria para Densidade Populacional (MENOR vence)
    // (Este bloco está comentado, pois a escolha foi População)
    
    // char atributoComparadoDensidade[50] = "Densidade Populacional";
    // printf("\n\nComparação de cartas (Atributo: %s):\n\n", atributoComparadoDensidade);
    // printf("Carta 1 - %s (%s): %.2f hab/km²\n", nomeCidade1, estado1, densidadePopulacional1);
    // printf("Carta 2 - %s (%s): %.2f hab/km²\n", nomeCidade2, estado2, densidadePopulacional2);
    // 
    // if (densidadePopulacional1 < densidadePopulacional2) {
    //     printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    // } else if (densidadePopulacional2 < densidadePopulacional1) {
    //     printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    // } else {
    //     printf("Resultado: Empate!\n");
    // }
    */

    return 0; // Indica que o programa terminou com sucesso
}