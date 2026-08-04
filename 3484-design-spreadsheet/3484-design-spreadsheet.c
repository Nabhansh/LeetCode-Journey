#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int rows;
    int **grid;
} Spreadsheet;

/* ---------- Helper ---------- */

int getOperand(Spreadsheet *obj, char *s)
{
    if (isdigit(s[0]) || s[0] == '-')
    {
        return atoi(s);
    }

    int col = s[0] - 'A';
    int row = atoi(s + 1) - 1;

    return obj->grid[row][col];
}

/* ---------- Constructor ---------- */

Spreadsheet* spreadsheetCreate(int rows)
{
    Spreadsheet *obj = (Spreadsheet *)malloc(sizeof(Spreadsheet));

    obj->rows = rows;

    obj->grid = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        obj->grid[i] = (int *)calloc(26, sizeof(int));
    }

    return obj;
}

/* ---------- Set Cell ---------- */

void spreadsheetSetCell(Spreadsheet* obj,
                        char* cell,
                        int value)
{
    int col = cell[0] - 'A';
    int row = atoi(cell + 1) - 1;

    obj->grid[row][col] = value;
}

/* ---------- Reset Cell ---------- */

void spreadsheetResetCell(Spreadsheet* obj,
                          char* cell)
{
    int col = cell[0] - 'A';
    int row = atoi(cell + 1) - 1;

    obj->grid[row][col] = 0;
}

/* ---------- Evaluate Formula ---------- */

int spreadsheetGetValue(Spreadsheet* obj,
                        char* formula)
{
    char expr[105];

    strcpy(expr, formula + 1);

    char *left = strtok(expr, "+");
    char *right = strtok(NULL, "+");

    return getOperand(obj, left)
         + getOperand(obj, right);
}

/* ---------- Destructor ---------- */

void spreadsheetFree(Spreadsheet* obj)
{
    for (int i = 0; i < obj->rows; i++)
        free(obj->grid[i]);

    free(obj->grid);
    free(obj);
}