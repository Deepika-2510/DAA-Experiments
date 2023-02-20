#include<stdio.h> 
#include<stdlib.h> 
#include <time.h> 
#include<limits.h>
void selection_sort(int arr[],int size)
{
for(int i=0;i<size-1;i++)
{
int min=i;
for(int j=i+1;j<size;j++)
{
if(arr[j]<arr[min])
{
min = j;
}
}
int temp = arr[min]; 
arr[min] = arr[i]; 
arr[i] = temp;
}
}
void insertion_sort(int arr[],int n)
{
int i,key,j;
for(int i=1;i<n;i++)
{
key = arr[i]; 
j=i-1;
while(j>=0 && arr[j]>key)
{
arr[j+1] = arr[j];
j=j-1;
}
arr[j+1] = key;
}
}
void main()
{
//creating a file object 
FILE *fp;
//opening file in data.txt in write mode 
fp = fopen ("data.txt", "w"); 
srand((unsigned int) time(NULL));
//generating 100 random numbers for 100 blocks and storing it 

for(int block=0;block<100;block++)
{
for(int i=0;i<100;i++)
{
int number = (int)(((float) rand() / 
(float)(RAND_MAX))*100000);
fprintf(fp,"%d ",number);
}
fputs("\n",fp);
}
fclose (fp);
//opening file in read mode 
fp = fopen("data.txt", "r");
printf("Block\t\tSelection Sort\t\tInsertion Sort\n");
//looping through each block 
int block=0;
for(block=0;block<100;block++)
{
clock_t selection,insertion; 
selection = clock();
int arr[(block+1)*100];
for(int i=0;i<(block+1)*100;i++)
{
fscanf(fp, "%d", &arr[i]);
}
selection_sort(arr,(block+1)*100); 
selection = clock() - selection;
insertion = clock();
for(int i=0;i<(block+1)*100;i++)
{
fscanf(fp, "%d", &arr[i]);
}
insertion_sort(arr,(block+1)*100); 
insertion = clock() - insertion;
//calculating the time taken to sort
double time_taken_s = ((double)selection)/CLOCKS_PER_SEC; 
double time_taken_i = ((double)insertion)/CLOCKS_PER_SEC;
printf("%d,%f,%f\n",(block+1)*100,time_taken_s,time_taken_i);

}
fclose(fp);
}
