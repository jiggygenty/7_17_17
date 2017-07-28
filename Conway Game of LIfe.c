#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void main()
{
clock_t now, then;
time_t t;
int i,j,n,k,m,count;
double pause=2*CLOCKS_PER_SEC;
srand((unsigned) time(&t));

printf("Enter the the length of the side for the n by n grid: ");
scanf("%d",&n);
printf("Enter the number of iterations: ");
scanf("%d",&k);
int array[n][n][k];
char finarray[n][n][k];

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        array[i][j][0]=round(rand()%2);
    }
}

for(m=0;m<k;m++)
{
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
    count=0;
        if(i<n-1&&i>0&&j>0&&j<n-1)
        {
            if(array[i][j+1][m]==1)
            count++;
            if(array[i+1][j+1][m]==1)
            count++;
            if(array[i+1][j][m]==1)
            count++;
            if(array[i+1][j-1][m]==1)
            count++;
            if(array[i][j][m]==1)
            count++;
            if(array[i-1][j-1][m]==1)
            count++;
            if(array[i-1][j][m]==1)
            count++;
            if(array[i-1][j+1][m]==1)
            count++;
        }
        else
        {
        //lower boundary
        if(i==n-1)
        {
            if(j==0)
            {
            if(array[i-1][j][m]==1)
            count++;
            if(array[i-1][j+1][m]==1)
            count++;
            if(array[i][j+1][m]==1)
            count++;
            }
            else if(j==n-1)
            {
            if(array[i-1][j][m]==1)
            count++;
            if(array[i-1][j-1][m]==1)
            count++;
            if(array[i][j-1][m]==1)
            count++;
            }
            else
            {
            if(array[i][j+1][m]==1)
            count++;
            if(array[i][j-1][m]==1)
            count++;
            if(array[i-1][j-1][m]==1)
            count++;
            if(array[i-1][j][m]==1)
            count++;
            if(array[i-1][j+1][m]==1)
            count++;
            }
        }
        //upper boundary
        if(i==0)
        {
            if(j==0)
            {
            if(array[i+1][j+1][m]==1)
            count++;
            else if(array[i+1][j][m]==1)
            count++;
            if(array[i][j+1][m]==1)
            count++;
            }
            if(j==n-1)
            {
            if(array[i+1][j][m]==1)
            count++;
            else if(array[i+1][j-1][m]==1)
            count++;
            if(array[i][j-1][m]==1)
            count++;
            }
        else
        {
        if(array[i][j+1][m]==1)
            count++;
        else if(array[i][j-1][m]==1)
            count++;
        else if(array[i+1][j+1][m]==1)
            count++;
        else if(array[i+1][j][m]==1)
            count++;
        if(array[i+1][j-1][m]==1)
            count++;
        }
        }
        //left boundary
        if(j==0&&i>0&&i<n-1)
        {
        if(array[i][j+1][m]==1)
            count++;
        else if(array[i-1][j+1][m]==1)
            count++;
        else if(array[i+1][j+1][m]==1)
            count++;
        else if(array[i+1][j][m]==1)
            count++;
        if(array[i-1][j][m]==1)
            count++;
        }
        //right boundary
        if(j==n-1&&i>0&&i<n-1)
        {
        if(array[i][j-1][m]==1)
            count++;
        else if(array[i-1][j-1][m]==1)
            count++;
        else if(array[i+1][j-1][m]==1)
            count++;
        else if(array[i+1][j][m]==1)
            count++;
        if(array[i-1][j][m]==1)
            count++;
        }
        }
        if(count==3&&array[i][j][m]==0)
            array[i][j][m+1]=1;
        else if (count<2)
            array[i][j][m+1]=0;
        else if (count>1&&count<4&&array[i][j][m]==1)
            array[i][j][m+1]=1;
        else if (count>3)
            array[i][j][m+1]=0;
        else
            array[i][j][m+1]=array[i][j][m];

    }
}
}
for(m=0;m<k;m++)
{
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if(array[i][j][m]==0)
        finarray[i][j][m]=' ';
        else
        finarray[i][j][m]='@';
    }
    printf("\n");
}
}

for(m=0;m<k;m++)
{
system("cls");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        printf("%d\t",array[i][j][m]);
    }
    printf("\n");
}
now=clock();
then=now;
while((now-then)<pause)
    now=clock();
}
}
