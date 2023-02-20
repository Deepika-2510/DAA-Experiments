#include<stdio.h> 
#include<stdlib.h> 
#include <time.h> 
#include<limits.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
printf("Block\t\tMerge Sort\t\tQuick Sort\n");
//looping through each block 
int block=0;
for(block=0;block<100;block++)
{
clock_t merge,quick; 
merge= clock();
int arr[(block+1)*100];
for(int i=0;i<(block+1)*100;i++)
{
fscanf(fp, "%d", &arr[i]);
}
mergeSort(arr,0,(block+1)*100); 
merge = clock() -merge;
quick= clock();
for(int i=0;i<(block+1)*100;i++)
{
fscanf(fp, "%d", &arr[i]);
}
quickSort(arr,0,(block+1)*100); 
quick = clock() - quick;
//calculating the time taken to sort
double time_taken_s = ((double)merge)/CLOCKS_PER_SEC; 
double time_taken_i = ((double)quick)/CLOCKS_PER_SEC;
printf("%d,%f,%f\n",(block+1)*100,time_taken_s,time_taken_i);

}
fclose(fp);
}
