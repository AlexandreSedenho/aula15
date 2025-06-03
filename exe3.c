#include <stdio.h>
#include <string.h>

// Função para desenhar retângulo
void retangulo(FILE *stream) {
    int x, y, width, height;

    printf("Informe x: ");
    scanf("%d", &x);

    printf("Informe y: ");
    scanf("%d", &y);

    printf("Informe largura (width): ");
    scanf("%d", &width);

    printf("Informe altura (height): ");
    scanf("%d", &height);

    fprintf(stream,
        "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n",
        x, y, width, height);
}

// Função para desenhar círculo
void circulo(FILE *stream) {
    int cx, cy, r;

    printf("Informe cx: ");
    scanf("%d", &cx);

    printf("Informe cy: ");
    scanf("%d", &cy);

    printf("Informe o raio (r): ");
    scanf("%d", &r);

    fprintf(stream,
        "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"blue\" />\n",
        cx, cy, r);
}

// Função para desenhar linha
void linha(FILE *stream) {
    int x1, y1, x2, y2;

    printf("Informe x1: ");
    scanf("%d", &x1);

    printf("Informe y1: ");
    scanf("%d", &y1);

    printf("Informe x2: ");
    scanf("%d", &x2);

    printf("Informe y2: ");
    scanf("%d", &y2);

    fprintf(stream,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"2\" />\n",
        x1, y1, x2, y2);
}

// Função para inserir texto
void texto(FILE *stream) {
    int x, y;
    char str[256];

    printf("Informe x: ");
    scanf("%d", &x);

    printf("Informe y: ");
    scanf("%d", &y);

    getchar(); // limpa o \n do buffer antes de usar fgets
    printf("Informe o texto: ");
    fgets(str, sizeof(str), stdin);

    // Remove '\n' do final
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    fprintf(stream,
        "<text x=\"%d\" y=\"%d\" font-family=\"Verdana\" font-size=\"20\" fill=\"black\">%s</text>\n",
        x, y, str);
}

// Função principal
int main() {
    char nomeArquivo[100];
    char opcao;

    printf("Digite o nome do arquivo SVG: ");
    scanf("%s", nomeArquivo);

    strcat(nomeArquivo, ".svg");
    FILE *svg = fopen(nomeArquivo, "w");
    if (!svg) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Cabeçalho SVG
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n");

    // Menu de figuras
    do {
        printf("\nEscolha uma opção:\n");
        printf("R - Retângulo\n");
        printf("C - Círculo\n");
        printf("L - Linha\n");
        printf("T - Texto\n");
        printf("F - Finalizar\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'R':
            case 'r':
                retangulo(svg);
                break;
            case 'C':
            case 'c':
                circulo(svg);
                break;
            case 'L':
            case 'l':
                linha(svg);
                break;
            case 'T':
            case 't':
                texto(svg);
                break;
            case 'F':
            case 'f':
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 'F' && opcao != 'f');

    // Finaliza SVG
    fprintf(svg, "</svg>\n");
    fclose(svg);

    printf("Arquivo '%s' salvo com sucesso.\n", nomeArquivo);
    return 0;
}