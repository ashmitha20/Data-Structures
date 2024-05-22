/*#include <stdio.h>
#include <stdlib.h>

void matrixtotuple(int mat[100][100],int rows,int cols,int tuple[][3]) {
    int i,j,k=1;
    tuple[0][0] = rows;
    tuple[0][1]= cols;
    tuple[0][2] = 0;
    for(i = 0; i< rows;i++) {
        for(j = 0; j< cols;j++) {
            if(mat[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = mat[i][j];
                k++;
            }
        }
    }
    tuple[0][2] = k-1;
}
void display(int tuple[][3]) {
    int k = tuple[0][2];
    printf("Rows\tCols\tElements\n");
    for(int i = 0; i <= k;i++) {
        printf("%d\t%d\t%d\n",tuple[i][0],tuple[i][1],tuple[i][2]);
    }
}
void addtuples(int tuple1[][3],int tuple2[][3],int res[][3]) {
    int i = 1, j = 1, k = 1;
    while(i <= tuple1[0][2] && j <= tuple2[0][2]) {
        if(tuple1[i][0] < tuple2[j][0]|| tuple1[i][0] == tuple2[j][0] && tuple1[i][1] < tuple2[j][1]) {
            res[k][0] = tuple1[i][0];
            res[k][1] = tuple1[i][1];
            res[k][2] = tuple1[i][2];
            i++;
        }
        else if(tuple1[i][0] > tuple2[j][0]|| tuple1[i][0] == tuple2[j][0] && tuple1[i][1] > tuple2[j][1]) {
            res[k][0] = tuple2[j][0];
            res[k][1] = tuple2[j][1];
            res[k][2] = tuple2[j][2];
            j++;
        }
        else {
             res[k][0] = tuple1[i][0];
            res[k][1] = tuple1[i][1];
            res[k][2] = tuple1[i][2]+tuple2[j][2];
            i++;
            j++;
        }
        k++;
    }
     while(i <= tuple1[0][2]) {
        res[k][0] = tuple1[i][0];
            res[k][1] = tuple1[i][1];
            res[k][2] = tuple1[i][2];
            i++;
            k++;
     }
     while(j <= tuple2[0][2]) {
            res[k][0] = tuple2[j][0];
            res[k][1] = tuple2[j][1];
            res[k][2] = tuple2[j][2];
            j++;
            k++;
     }
     res[0][0] = tuple1[0][0];
     res[0][1] = tuple1[0][1];
     res[0][2] = k - 1;

}
void main() {
    int mat1[100][100],mat2[100][100],tuple1[500][3],tuple2[500][3],res[500][3];
    int r1,c1,r2,c2;
    int i,j,k;
    printf("\nEnter the number of rows and columns in first matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1;j++) {
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("\nEnter the number of rows and columns in second matrix: ");
    scanf("%d %d",&r2,&c2);
     printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2;j++) {
            scanf("%d",&mat2[i][j]);
        }
    }
    matrixtotuple(mat1,r1,c1,tuple1);
    display(tuple1);
    matrixtotuple(mat2,r2,c2,tuple2);
    display(tuple2);
    addtuples(tuple1,tuple2,res);
    display(res);

}*/

#include <stdio.h>
#include <stdlib.h>

void totuple(int mat[100][100], int rows, int cols, int tuple[][3]) {
    int i , j , k = 1;
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = 0;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(mat[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = mat[i][j];
                k++;
            }
    }
    }
    tuple[0][2] = k -1;
    }
void display(int tup[][3]) {
    int i,k;
    k = tup[0][2];
    printf("The Tuple is : \n Rows\tColumns\tValues\n");
    for(i = 0; i <= k; i++) {
        printf("\n%d\t%d\t%d",tup[i][0],tup[i][1],tup[i][2]);
    }

}
void addtuples(int tup1[][3], int tup2[][3], int res[][3]) {
    int i = 1, j = 1 , k = 1;
    while(i <= tup1[0][2] && j <= tup2[j][2]) {
        if(tup1[i][0] < tup2[j][0] || tup1[i][0] == tup2[j][0] && tup1[i][1] < tup2[j][1]) {
            res[k][0] = tup1[i][0];
            res[k][1] = tup1[i][1];
            res[k][2] = tup1[i][2];
            i++;k++;
        }
        else if(tup1[i][0] > tup2[j][0] || tup1[i][0] == tup2[j][0] && tup1[i][1] > tup2[j][1]) {
            res[k][0] = tup2[j][0];
            res[k][1] = tup2[j][1];
            res[k][2] = tup2[j][2];
            j++;k++;
        }
        else {
            res[k][0] = tup2[j][0];
            res[k][1] = tup2[j][1];
            res[k][2] = tup1[i][2] + tup2[j][2] ;
            i++;j++;k++;
    }
    }
     while(i <= tup1[0][2]) {
            res[k][0] = tup1[i][0];
            res[k][1] = tup1[i][1];
            res[k][2] = tup1[i][2];
            i++;k++;
     }
     while(j <= tup2[0][2]) {
            res[k][0] = tup2[j][0];
            res[k][1] = tup2[j][1];
            res[k][2] = tup2[j][2];
            j++;k++;
    }
    res[0][0] = tup1[0][0];
    res[0][1] = tup1[0][1];
    res[0][2] = k - 1;
}

void main() {
    int mat1[100][100],mat2[100][100],tup1[500][3],tup2[500][3],res[500][3];
    int rows, cols,rows2,cols2, i,j,k;
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d%d",&rows, &cols);
    printf("\nEnter elements of first matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d",&mat1[i][j]);
    }
    }
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d%d",&rows2, &cols2);
    printf("\nEnter elements of second matrix:\n");
    for(i = 0; i < rows2;i++) {
        for(j = 0; j < cols2; j++) {
            scanf("%d",&mat2[i][j]);
        }
    }
    totuple(mat1,rows,cols,tup1);
    totuple(mat2,rows2,cols2,tup2);
    addtuples(tup1,tup2,res);
    display(res);
}
