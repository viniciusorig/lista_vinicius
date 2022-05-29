#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libex.h"

FILE *file, *file2;

int main(int argc, const char *argv[])
{
    document(&file, argv[1]);
    document(&file2, argv[2]);
    int line = atoi(argv[3]), column = atoi(argv[4]), cancel_line = 0,
        cancel_column = 0, quantidade = 0;
    float vector[line][column];
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
            fscanf(file, "%f", &vector[i][j]);
    }
    printf("arquivo scaneado\nQuantas posições deseja anular?\t");
    scanf("%d", &quantidade);
    for (int i = 0; i < quantidade; i++)
    {
        printf("quais pocições?\tline:\t");
        scanf("%d", &cancel_line);
        printf("column:\t");
        scanf("%d", &cancel_column);
        vector[cancel_line][cancel_column] = 0;
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fprintf(file2, "%f", vector[i][j]);
            fprintf(file2, "\t");
        }
        fprintf(file2, "\n");
    }
    fclose(file);
    fclose(file2);
}