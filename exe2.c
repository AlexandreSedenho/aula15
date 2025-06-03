#include <stdio.h>
#include <string.h>

int main() {
    char nomeArquivo[100];
    int x, y, width, height;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    printf("Digite a posição do quadrado (x e y): ");
    scanf("%d %d", &x, &y);
    printf("Digite a largura e a altura do quadrado: ");
    scanf("%d %d", &width, &height);

    strcat(nomeArquivo, ".svg");
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "<svg version=\"1.1\"\n");
    fprintf(arquivo, "width=\"300\" height=\"200\"\n");
    fprintf(arquivo, "xmlns=\"http://www.w3.org/2000/svg\">\n");
    fprintf(arquivo, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, width, height);
    fprintf(arquivo, "</svg>\n");

    fclose(arquivo);

    printf("Arquivo %s criado com sucesso.\n", nomeArquivo);

    return 0;
}