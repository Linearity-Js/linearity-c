using namespace std;

#include <iostream>

struct Matrix
{
    struct Value **values;
    int colsLength;
    int rowsLength;
    int pointer[2]; // not used
};

struct Value
{
    int imaginary;
    float value;
};

struct Value *initField(int if_imaginary, float value);
struct Matrix *initMatrix(int colsLength, int rowsLength);

void addValue(struct Matrix *matrix, int row, int col, struct Value *value);
void printValue(Value field);
void printMatrix(Matrix *matrix);
struct Value *requestValues(struct Matrix *matrix);
struct Value *requestValue();
struct Matrix *printMenuMatrix();
void printMenu(struct Matrix *matrix);

// PROGRAMS
void searchMin(struct Matrix *matrix);
void searchMax(struct Matrix *matrix);
void printMaxAndMinLocation(struct Matrix *matrix);

struct Value *getRowValues(struct Matrix *matrix, int row);
struct Value *getColValues(struct Matrix *matrix, int col);
void switchRowAndCol(struct Matrix *matrix);

void sortMatrix(struct Matrix *matrix);

int main(int argc, char const *argv[])
{
    cout << "creando matriz \n";

    struct Matrix *matrix = printMenuMatrix();
    requestValues(matrix); // required

    cout << "imprimiendo matriz de prueba \n";
    printMatrix(matrix);

    printMenu(matrix);

    return 0;
}

struct Value *requestValues(struct Matrix *matrix)
{
    int rows = matrix->rowsLength;
    int cols = matrix->colsLength;
    int i, j;
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            cout << "Registro del valor [" << i << "][" << j << "]. ";
            addValue(matrix, i, j, requestValue());
        }
    }
}

struct Value *requestValue()
{
    int if_imaginary;
    float value;
    cout << "Es una valor imaginario (1/0)? ";
    cin >> if_imaginary;
    cout << "Ingresa un valor:";
    cin >> value;
    return initField(if_imaginary, value);
}

struct Value *initField(int if_imaginary, float value)
{
    Value *field = new Value;
    field->imaginary = if_imaginary;
    field->value = value;
    return field;
}

void printMatrix(Matrix *matrix)
{
    int rows = matrix->rowsLength;
    int cols = matrix->colsLength;

    if (matrix && rows != 0 && cols != 0)
        for (int i = 0; i < cols; i++)
        {
            Value **values = matrix->values;
            Value tempValue;
            for (int j = 0; j < rows; j++)
            {
                tempValue = values[i][j];
                printValue(tempValue);
            }
            cout << "\n";
        }
}

void printValue(Value field)
{
    cout << field.value;
    if (field.imaginary)
        cout << "i";
    else
        cout << " ";
    cout << " ";
    // last lines: format
}

struct Matrix *initMatrix(int rowsLength, int colsLength)
{
    Matrix *matrix = new Matrix;
    matrix->rowsLength = rowsLength;
    matrix->colsLength = colsLength;

    Value **fields = new Value *[rowsLength];
    for (int i = 0; i < rowsLength; ++i)
        fields[i] = new Value[colsLength];
    matrix->values = fields;

    matrix->pointer;
    return matrix;
}

void addValue(struct Matrix *matrix, int row, int col, struct Value *value)
{
    if (matrix)
    {
        matrix->values[row][col].value = value->value;
        matrix->values[row][col].imaginary = value->imaginary;
    }
}

struct Value getValue(struct Matrix *matrix, int row, int col)
{
    if (matrix)
        return matrix->values[row][col];
}

struct Matrix *printMenuMatrix()
{
    cout << "*********************************\n";
    cout << "***** PROGRAMA DE MATRICES ******\n";
    cout << "*********************************\n";
    cout << "\nIngresa que tipo de matriz quieres:\n";
    cout << "1 Matriz de 2 x 2\n";
    cout << "2 Matriz de 3 x 2\n";
    cout << "3 Matriz de 3 x 3\n";
    cout << "4 Matriz de 4 x 4\n";
    cout << "5 Mostrar otras opciones...\n";
    cout << "Ingesa una opcion: ";

    int option, rows, cols;
    cin >> option;

    //devline: test
    //struct Matrix *matrix;

    switch (option)
    {
    case 0:
        rows = 2;
        cols = 2;
        break;
    case 1:
        rows = 2;
        cols = 2;
        break;
    case 2:
        rows = 3;
        cols = 2;
        break;
    case 3:
        rows = 3;
        cols = 3;
        break;
    case 4:
        rows = 4;
        cols = 4;
        break;
    case 5:
        cout << "\nIngresa m x n ";
        cout << "\nValor para m:";
        cin >> rows;
        cout << "Valor para m:";
        cin >> cols;
        break;
    default:
        cout << "\nHas ingresado una opcion no valida";
        rows = 0;
        cols = 0;
        break;
    }

    // Dvlines: test
    // matrix = initMatrix(rows, cols);
    // addValue(matrix, 0, 0, initField(0, 1));
    // addValue(matrix, 0, 1, initField(0, 2));
    // addValue(matrix, 1, 0, initField(0, 3));
    // addValue(matrix, 1, 1, initField(0, 4));

    return initMatrix(rows, cols);

    //Dvline: test
    //return matrix;
}

// PROGRAMS
void printMenu(struct Matrix *matrix)
{
    cout << "*********************************\n";
    cout << "***** PROGRAMA DE MATRICES ******\n";
    cout << "*********************************\n";
    cout << "\nIngresa que tipo operacion deseas:\n";
    cout << "1 Ubicaciones y valores de los elementos mayor y menor. (30 y 31)\n";
    cout << "2 Intercambiar fila con columna (33)\n";
    cout << "3 Ordenar Ascendentemente por filas (35)\n";

    int option;
    cout << "Ingesa una opcion: ";
    cin >> option;

    switch (option)
    {
    case 1:
        printMaxAndMinLocation(matrix);
        break;
    case 2:
        if (matrix->colsLength == matrix->rowsLength)
        {
            switchRowAndCol(matrix);
            printMatrix(matrix);
        }
        else
            cout << "solo para mxm matrices";
        break;
    case 3:
        sortMatrix(matrix);
        printMatrix(matrix);
        break;
    case 4:
        cout << "not working yet";
        break;
    case 5:
        cout << "not working yet";
        break;
    default:
        cout << "\nHas ingresado una opcion no valida";
        break;
    }
}

void searchMax(struct Matrix *matrix)
{

    if (matrix)
    {
        int rows = matrix->rowsLength;
        int cols = matrix->colsLength;

        int i, j;
        int location[2];

        Value maxValue = getValue(matrix, 0, 0);
        Value tempValue;

        for (i = 0; i < rows; i++)
            for (j = 1; j < cols; j++)
            {
                tempValue = getValue(matrix, i, j);
                if (maxValue.value < tempValue.value)
                {
                    location[0] = i;
                    location[1] = j;
                    maxValue = tempValue;
                }
            }

        cout << "\nUbicacion: [" << location[0] << "][" << location[1] << "]";
        cout << "\nValor: " << maxValue.value;
    }
}

void searchMin(struct Matrix *matrix)
{
    if (matrix)
    {
        int rows = matrix->rowsLength;
        int cols = matrix->colsLength;

        int i, j;
        int location[2];

        Value min = getValue(matrix, 0, 0);
        location[0] = 0;
        location[1] = 0;

        Value tempValue;

        for (i = 0; i < rows; i++)
            for (j = 1; j < cols; j++)
            {
                tempValue = getValue(matrix, i, j);
                if (tempValue.value < min.value)
                {
                    location[0] = i;
                    location[1] = j;
                    min = tempValue;
                }
            }

        cout << "\nUbicacion: [" << location[0] << "][" << location[1] << "]";
        cout << "\nValor: " << min.value;
    }
}

//max & min location
void printMaxAndMinLocation(struct Matrix *matrix)
{
    cout << "\nBuscando valor minimo...";
    searchMin(matrix);
    cout << "\nBuscando valor maximo...";
    searchMax(matrix);
}

struct Value *getRowValues(struct Matrix *matrix, int row)
{
    if (matrix)
    {
        int size = matrix->rowsLength;
        if (size >= 0)
        {
            cout << "size: " << size;
            cout << "\nrow: " << row << "\n";
            struct Value *values;
            values = new Value[size];
            for (int i = 0; i < size; i++)
                values[i] = getValue(matrix, row, i);

            return values;
        }
    }
    return NULL;
}

struct Value *getColValues(struct Matrix *matrix, int col)
{
    if (matrix)
    {
        int size = matrix->colsLength;
        if (size >= 0)
        {
            cout << "size: " << size;
            cout << "\ncol: " << col << "\n";
            struct Value *values;
            values = new Value[size];
            for (int i = 0; i < size; i++)
                values[i] = getValue(matrix, i, col);

            return values;
        }
    }
    return NULL;
}

void addCol(struct Matrix *matrix, Value *colValues, int col)
{
    if (matrix)
    {
        int size = matrix->colsLength;
        Value *value = new Value;
        for (int i = 0; i < size; i++)
        {
            value->imaginary = colValues[i].imaginary;
            value->value = colValues[i].value;
            addValue(matrix, i, col, value);
        }
    }
}

void addRow(struct Matrix *matrix, Value *rowValues, int row)
{
    if (matrix)
    {
        int size = matrix->rowsLength;
        Value *value = new Value;
        for (int i = 0; i < size; i++)
        {

            value->imaginary = rowValues[i].imaginary;
            value->value = rowValues[i].value;
            addValue(matrix, row, i, value);
        }
    }
}

void switchRowAndCol(struct Matrix *matrix)
{
    if (matrix)
    {
        int row, col;

        cout << "\nRow a cambiar:";
        cin >> row;

        cout << "\nCol a cambiar:";
        cin >> col;

        Value *colValues = getColValues(matrix, col);

        for (int i = 0; i < matrix->colsLength; i++)
        {
            printValue(colValues[i]);
        }

        Value *rowValues = getRowValues(matrix, row);

        for (int i = 0; i < matrix->colsLength; i++)
        {
            printValue(rowValues[i]);
        }

        addRow(matrix, colValues, row);
        addCol(matrix, rowValues, col);
    }
}

void sortMatrix(struct Matrix *matrix)
{
    if (matrix)
    {
        int rows = matrix->rowsLength;
        int cols = matrix->colsLength;
        int valuesLength = cols * rows;
        struct Value *values = new Value[valuesLength];

        int k = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                values[k++] = getValue(matrix, i, j);

        struct Value temporalValue;
        for (int i = 0; i < valuesLength; i++)
            for (int j = 0; j < valuesLength; j++)
            {
                if (values[j].value < values[i].value)
                {
                    temporalValue = values[i];
                    values[i] = values[j];
                    values[j] = temporalValue;
                }
            }

        k = 0;
        struct Value *value = new Value;
        int rowsCounter = 0, colsCounter = 0;

        for (int i = 0; i < valuesLength; i++, k++)
        {
            value->imaginary = values[k].imaginary;
            value->value = values[k].value;
            addValue(matrix, rowsCounter, colsCounter, value);

            if (colsCounter == (cols - 1))
            {
                rowsCounter++;
                colsCounter = 0;
            }
            else
                colsCounter++;
        }
    }
}
