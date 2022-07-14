//Made by https://github.com/Gabril0 

#include<stdio.h>//standard library
#include<stdlib.h>//memory allocation library
#include<conio.h>//library used for the "Press any key to continue:"


//Function allocates the memory and creates a matrix with the numbers typed by the user
int **matrix_maker(int row, int columns){
    int **matrixaux;
    int insertion;

    matrixaux = (int **) malloc(row * sizeof(int *));

    for(int i = 0; i < row; i++){
        matrixaux[i] = (int *) malloc(row * sizeof(int));
        for(int j = 0; j < columns; j++){
            printf("\nType the desired number that you want to insert in position matrix row [%d] column [%d]: ", i+1, j+1);
            scanf("%d", &insertion);
            matrixaux[i][j] = insertion;
        }
    }

    return matrixaux;
}


//Prints the matrix in the console
void matrix_printer(int row, int columns, int **matrixaux){
    int cycles = 0;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            if(cycles == columns){
                cycles = 0;
                printf("|\n");
            }
            if(cycles == 0){
                printf("|");
            }
            printf(" %d ", matrixaux[i][j]);
            cycles++;}
    }
    printf("|");}

//Creates a matrix and fills it with a number typed by the user
int **matrix_filler(int row, int columns){
    int **matrixaux;
    int insertion;

    printf("\nType the desired number to insert: ");
    scanf("%d", &insertion);

    matrixaux = (int **) malloc(row * sizeof(int *));

    for(int i = 0; i < row; i++){
        matrixaux[i] = (int *) malloc(row * sizeof(int));
        for(int j = 0; j < columns; j++){
            matrixaux[i][j] = insertion;
        }
    }

    return matrixaux;
}

//Exports a matrix to a txt file
void export_matrix(int row, int columns, int **matrixaux){
    FILE *m;
    int cycles;

    m = fopen("Matrixes.txt","w");
    if(m == NULL) printf("ERROR");
    else{for(int i = 0; i < row; i++){
    for(int j = 0; j < columns; j++){
        if(cycles == columns){
            cycles = 0;
            fprintf(m,"|\n");
        }
        if(cycles == 0){
            fprintf(m,"|");
        }
        fprintf(m," %d ", matrixaux[i][j]);
        cycles++;}
    }
    fprintf(m,"|");}
    fclose(m);
}

//The menu with all the function callls and options
void menu(){
    int row, columns;
    int **matrix;
    int op;
    while(1){
        printf("\n\n == Welcome to Dynamic Memory Matrix Maker == ");
        printf("\n1 - Create a custom Matrix");
        printf("\n2 - Fill a matrix");
        printf("\n3 - Export matrix to text file");
        printf("\n0 - Exit");
        printf("\nChoose an option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
            if(matrix != NULL) free(matrix);
            printf("\nWARNING!!! Typing very large number may lead to a system crash, proceed carefuly and only use small numbers for your safety\n");
            printf("\nPlease type the number of rows: ");
            scanf("%d",&row);
            printf("\nPlease type the number of columns: ");
            scanf("%d",&columns);
            matrix = matrix_maker(row, columns);
            printf("\n");
            matrix_printer(row,columns,matrix);
            printf("\n\nPress any key to continue:");
            getch();

            break;
            
            case 2:
            if(matrix != NULL) free(matrix);
            printf("\nWARNING!!! Typing very large number may lead to a system crash, proceed carefuly and only use small numbers for your safety\n");
            printf("\nPlease type the number of rows: ");
            scanf("%d",&row);
            printf("\nPlease type the number of columns: ");
            scanf("%d",&columns);
            matrix = matrix_filler(row, columns);
            printf("\n");
            matrix_printer(row,columns,matrix);
            printf("\n\nPress any key to continue:");
            getch();

            break;

            case 3:
            if(matrix == NULL){
                printf("\nERROR! The matrix is empty\n"); 
                return;}
            export_matrix(row,columns,matrix);
            printf("\nExportation completed!!");
            printf("\n\nPress any key to continue:");
            getch();
            break;

            case 0:
            if(matrix != NULL) free(matrix);
            exit(1);

            default:
            printf("\nThat's not a valid option");
            break;
        }
    }
}

//Main function
int main(){
    menu();
}
