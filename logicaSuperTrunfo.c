#include <stdio.h>
#include <string.h> // Para strcpy, strcat

// Enum para identificar os atributos de forma clara
typedef enum {
    NENHUM_ATTR = 0,
    POPULACAO,
    AREA,
    PIB,
    PONTOS_TURISTICOS,
    DENSIDADE_DEMOGRAFICA
} AtributoID;

// Estrutura para ajudar na gestão dos atributos para o menu
typedef struct {
    AtributoID id;
    char nome[50];
} InfoAtributo;

// Dados das cartas (pré-definidos)
// Carta 1
char nomePais1[50] = "Brasil";
char codigoCarta1[5] = "BR01";
int populacao1 = 210000000;
float area1 = 8515767.0f;
float pibBilhoes1 = 1800.0f;
int numPontosTuristicos1 = 1500;
float densidadeDemografica1;
float pibPerCapita1;

// Carta 2
char nomePais2[50] = "Argentina";
char codigoCarta2[5] = "AR01";
int populacao2 = 45000000;
float area2 = 2780400.0f;
float pibBilhoes2 = 450.0f;
int numPontosTuristicos2 = 700;
float densidadeDemografica2;
float pibPerCapita2;

// Array com informações dos atributos selecionáveis
InfoAtributo atributosSelecionaveis[] = {
    {POPULACAO, "População"},
    {AREA, "Área"},
    {PIB, "PIB (em bilhões)"},
    {PONTOS_TURISTICOS, "Pontos Turísticos"},
    {DENSIDADE_DEMOGRAFICA, "Densidade Demográfica"}
};
int numTotalAtributosSelecionaveis = sizeof(atributosSelecionaveis) / sizeof(InfoAtributo);

// Função para limpar o buffer de entrada (stdin)
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para obter o nome de um atributo pelo ID
const char* get_nome_atributo(AtributoID id) {
    for (int i = 0; i < numTotalAtributosSelecionaveis; ++i) {
        if (atributosSelecionaveis[i].id == id) {
            return atributosSelecionaveis[i].nome;
        }
    }
    return "Desconhecido";
}

// Função para obter o valor float de um atributo para uma carta específica
float get_valor_atributo(AtributoID id, int pop, float area_val, float pib_val, int pontos_val, float densidade_val) {
    switch (id) {
        case POPULACAO: return (float)pop;
        case AREA: return area_val;
        case PIB: return pib_val;
        case PONTOS_TURISTICOS: return (float)pontos_val;
        case DENSIDADE_DEMOGRAFICA: return densidade_val;
        default: return 0.0f;
    }
}

// Função para imprimir o valor de um atributo com sua unidade/descrição
void print_valor_formatado_atributo(AtributoID id, int pop, float area_val, float pib_val, int pontos_val, float densidade_val) {
    switch (id) {
        case POPULACAO: printf("%d habitantes", pop); break;
        case AREA: printf("%.2f km²", area_val); break;
        case PIB: printf("%.2f bilhões", pib_val); break;
        case PONTOS_TURISTICOS: printf("%d", pontos_val); break;
        case DENSIDADE_DEMOGRAFICA: printf("%.2f hab/km²", densidade_val); break;
        default: printf("N/A"); break;
    }
}

// Função para o jogador escolher um atributo (menu dinâmico)
AtributoID escolher_atributo_menu(const char* mensagem_prompt, AtributoID atributo_ja_escolhido) {
    int escolha_menu_usuario;
    int escolha_valida = 0;
    AtributoID id_final_escolhido = NENHUM_ATTR;

    // Array para mapear a opção do menu (1, 2, 3...) para o AtributoID real
    AtributoID opcoes_reais_menu[numTotalAtributosSelecionaveis];
    int contador_opcoes_exibidas = 0;

    do {
        printf("\n%s\n", mensagem_prompt);
        contador_opcoes_exibidas = 0;
        for (int i = 0; i < numTotalAtributosSelecionaveis; ++i) {
            if (atributosSelecionaveis[i].id != atributo_ja_escolhido) {
                contador_opcoes_exibidas++;
                printf("%d. %s\n", contador_opcoes_exibidas, atributosSelecionaveis[i].nome);
                opcoes_reais_menu[contador_opcoes_exibidas - 1] = atributosSelecionaveis[i].id;
            }
        }

        if (contador_opcoes_exibidas == 0) {
            printf("Erro: Não há atributos suficientes para escolher.\n");
            return NENHUM_ATTR;
        }

        printf("Digite sua escolha (1-%d): ", contador_opcoes_exibidas);
        if (scanf("%d", &escolha_menu_usuario) != 1) {
            printf("Entrada inválida. Por favor, digite um número.\n");
            limpar_buffer_entrada();
            continue; // Volta para o início do loop do-while
        }
        limpar_buffer_entrada();

        if (escolha_menu_usuario >= 1 && escolha_menu_usuario <= contador_opcoes_exibidas) {
            id_final_escolhido = opcoes_reais_menu[escolha_menu_usuario - 1];
            escolha_valida = 1;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (!escolha_valida);

    return id_final_escolhido;
}


int main() {
    // Comentário: Calculando atributos derivados para Carta 1
    if (area1 > 0.000001f) {
        densidadeDemografica1 = (float)populacao1 / area1;
    } else {
        densidadeDemografica1 = (populacao1 > 0) ? 1.0e20f : 0.0f; // Simula densidade "infinita" ou zero
    }
    if (populacao1 > 0) {
        pibPerCapita1 = (pibBilhoes1 * 1000000000.0f) / (float)populacao1;
    } else {
        pibPerCapita1 = (pibBilhoes1 > 0) ? 1.0e20f : 0.0f; // Simula PIB per capita "infinito" ou zero
    }

    // Comentário: Calculando atributos derivados para Carta 2
    if (area2 > 0.000001f) {
        densidadeDemografica2 = (float)populacao2 / area2;
    } else {
        densidadeDemografica2 = (populacao2 > 0) ? 1.0e20f : 0.0f;
    }
    if (populacao2 > 0) {
        pibPerCapita2 = (pibBilhoes2 * 1000000000.0f) / (float)populacao2;
    } else {
        pibPerCapita2 = (pibBilhoes2 > 0) ? 1.0e20f : 0.0f;
    }

    // Comentário: Exibindo os dados completos das cartas
    printf("--- Carta 1: %s (%s) ---\n", nomePais1, codigoCarta1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pibBilhoes1);
    printf("Pontos Turísticos: %d\n", numPontosTuristicos1);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadeDemografica1);
    printf("PIB per Capita: %.2f\n\n", pibPerCapita1);

    printf("--- Carta 2: %s (%s) ---\n", nomePais2, codigoCarta2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pibBilhoes2);
    printf("Pontos Turísticos: %d\n", numPontosTuristicos2);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadeDemografica2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);

    // --- Escolha dos Atributos ---
    AtributoID attr1_escolhido = escolher_atributo_menu("Escolha o PRIMEIRO atributo para comparar:", NENHUM_ATTR);
    if (attr1_escolhido == NENHUM_ATTR) {
        return 1; // Sai se erro na primeira escolha
    }
    printf("Você escolheu '%s' como primeiro atributo.\n", get_nome_atributo(attr1_escolhido));

    AtributoID attr2_escolhido = escolher_atributo_menu("Escolha o SEGUNDO atributo para comparar (diferente do primeiro):", attr1_escolhido);
    if (attr2_escolhido == NENHUM_ATTR) {
        return 1; // Sai se erro na segunda escolha
    }
     printf("Você escolheu '%s' como segundo atributo.\n", get_nome_atributo(attr2_escolhido));


    // --- Coleta dos Valores dos Atributos Escolhidos ---
    float valor_attr1_c1 = get_valor_atributo(attr1_escolhido, populacao1, area1, pibBilhoes1, numPontosTuristicos1, densidadeDemografica1);
    float valor_attr1_c2 = get_valor_atributo(attr1_escolhido, populacao2, area2, pibBilhoes2, numPontosTuristicos2, densidadeDemografica2);
    float valor_attr2_c1 = get_valor_atributo(attr2_escolhido, populacao1, area1, pibBilhoes1, numPontosTuristicos1, densidadeDemografica1);
    float valor_attr2_c2 = get_valor_atributo(attr2_escolhido, populacao2, area2, pibBilhoes2, numPontosTuristicos2, densidadeDemografica2);

    // --- Soma dos Atributos para cada Carta ---
    float soma_c1 = valor_attr1_c1 + valor_attr2_c1;
    float soma_c2 = valor_attr1_c2 + valor_attr2_c2;

    // --- Exibição dos Resultados da Comparação ---
    printf("\n\n--- Resultado da Rodada de Comparação ---\n");
    printf("Países: %s vs %s\n", nomePais1, nomePais2);
    printf("Atributos Escolhidos: %s e %s\n\n", get_nome_atributo(attr1_escolhido), get_nome_atributo(attr2_escolhido));

    printf("Valores para %s:\n", get_nome_atributo(attr1_escolhido));
    printf("  %s: ", nomePais1); print_valor_formatado_atributo(attr1_escolhido, populacao1, area1, pibBilhoes1, numPontosTuristicos1, densidadeDemografica1); printf("\n");
    printf("  %s: ", nomePais2); print_valor_formatado_atributo(attr1_escolhido, populacao2, area2, pibBilhoes2, numPontosTuristicos2, densidadeDemografica2); printf("\n\n");

    printf("Valores para %s:\n", get_nome_atributo(attr2_escolhido));
    printf("  %s: ", nomePais1); print_valor_formatado_atributo(attr2_escolhido, populacao1, area1, pibBilhoes1, numPontosTuristicos1, densidadeDemografica1); printf("\n");
    printf("  %s: ", nomePais2); print_valor_formatado_atributo(attr2_escolhido, populacao2, area2, pibBilhoes2, numPontosTuristicos2, densidadeDemografica2); printf("\n\n");

    printf("Soma dos valores dos atributos para %s: %.2f\n", nomePais1, soma_c1);
    printf("Soma dos valores dos atributos para %s: %.2f\n", nomePais2, soma_c2);
    printf("\n");

    // Comentário: Determinar o vencedor usando o operador ternário para a mensagem
    if (soma_c1 == soma_c2) {
        printf("Resultado Final: Empate!\n");
    } else {
        // Usando operador ternário para escolher a string do nome do país vencedor
        printf("Resultado Final: %s venceu a rodada!\n", (soma_c1 > soma_c2 ? nomePais1 : nomePais2));
    }

    return 0;
}