#include<stdio.h>
#include<time.h>
void bsort(int a[], int n)
{
  int i,j,t,flag=0;
  
  
  for(i=0;i<n;i++)
 {
   flag=0;
   for(j=0;j<n-i-1;j++)
   {
     if(a[j]>a[j+1])
     {
       flag=1;
       t=a[j];
       a[j]=a[j+1];
       a[j+1]=t;
     }
   }
   if(!flag)
   return; 
 } 

}

void ssort(int a[],long n)
{
 int i,j,small,t,pos;


 for(i=0;i<n;i++)
{ 
  small=a[i];
  pos=i;

  for(j=i+1;j<n;j++)
 {
   if(a[j]<small)
   {
    small=a[j];
    pos=j;
   }
}
t=a[i];
a[i]=a[pos];
a[pos]=t;
}

}
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
 *           greater than key, to one position ahead
 *                     of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high],j;    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for ( j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

 void main()
{

    int a[500000];
    long n,i;
    clock_t s,e;
    double te;

  
    printf("\nEnter no of inputs:");
    scanf("%ld",&n);
    
    for(i=0;i<n;i++)
    a[i]=rand()%100+1;

    s=clock();

    bsort(a,n);
   
    e=clock();

    te=(double)(e-s)/CLOCKS_PER_SEC;

    printf("\n1.Bubble Sort: %lf",te);

    for(i=0;i<n;i++)
    a[i]=rand()%100+1;

    s=clock();
    ssort(a,n);
    e=clock();

    te=(double)(e-s)/CLOCKS_PER_SEC;

    printf("\n2.Selection sort: %lf", te);

    for(i=0;i<n;i++)
    a[i]=rand()%100+1;

    s=clock();
    insertionSort(a,n);
    e=clock();

    te=(double)(e-s)/CLOCKS_PER_SEC;

    printf("\n3.Inserion sort: %lf", te);
    
    for(i=0;i<n;i++)
    a[i]=rand()%100+1;

    s=clock();
    quickSort(a,0,n-1);
    e=clock();

    te=(double)(e-s)/CLOCKS_PER_SEC;

    printf("\n4.Quick sort: %lf", te);

    for(i=0;i<n;i++)
    a[i]=rand()%100+1;

    s=clock();
    mergeSort(a,0,n-1);
    e=clock();

    te=(double)(e-s)/CLOCKS_PER_SEC;

    printf("\n5.Merge sort: %lf", te);

    printf("\n");

}  

  
