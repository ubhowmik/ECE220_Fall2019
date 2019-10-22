#include <stdio.h>

int main()
{
    FILE *in;
    FILE *out;

    int m,n;
    int i,j;


    in = fopen("in_matrix.txt", "r");
    if(in == NULL)
    {
        return -1;

    }
    fscanf(in, "%d %d", &m, &n);

    int matrix[m][n];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(in, "%d ", &matrix[i][j]);
        }
    }
    fclose(in);


    out = fopen("out_matrix.txt", "w");
    if(out == NULL)
    {
        return -1;
    }

    fprintf(out, "%d %d \n", n, m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fprintf(out, "%d ", matrix[j][i]);
        }
        fprintf(out, "\n");
    }
    fclose(out);

}