#include <stdio.h>

void mergeSort(int array[], int left, int right)
{
    if (left < right)
        {

        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int leftsize = mid - left + 1;
    int rightsize = right - mid;
    int L[leftsize], R[rightsize];

    for (i = 0; i < leftsize; i++)
        L[i] = array[left + i];
    for (j = 0; j < rightsize; j++)
        R[j] = array[mid + 1 + j];

    i = 0, j = 0, k = left;
    while (i < leftsize && j < rightsize) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < leftsize) {
        array[k] = L[i];
        i++;
        k++;
    }


    while (j < rightsize) {
        array[k] = R[j];
        j++;
        k++;
    }
}


int main()
{
int size;
int R;
scanf("%d ",&size);
scanf("%d ",&R);
int array[size];
for(int i=0;i<size;i++)
{
    scanf("%d",&array[i]);
}

int freq[size];
int passed = -1;
    for(int i = 0; i < size; i++)
        {
        int count = 1;
        for(int j = i+1; j < size; j++)
        {
            if(array[i] == array[j])
            {
                count++;
                freq[j] = passed;
            }
        }
        if(freq[i] != passed)
            freq[i] = count;
    }

 mergeSort(freq, 0, size - 1);


int newsize=0;
    for(int i = 0; i < size; i++)
    {
        if(freq[i] != passed)
        {
            newsize++;
        }
    }
    int newarray[newsize];
    int k=0;
    for(int i = 0; i < size; i++)
    {
        if(freq[i] != passed)
        {
            newarray[k]=freq[i];
            k++;
        }
    }

//to get minimum freq num .
    int counter,z,calc = 0;
    for(z=0;z<newsize;z++)
        {
         calc=calc+newarray[z];


        if(calc==R)
            {
                for(int x=z+1 ;x<newsize; x++)
                    {
                     counter++;
                    }
               printf("%d",counter);
                break;
            }


        else if(calc > R)
            {
              for(int x=z;x<newsize; x++)
                    {
                     counter++;
                    }
              printf("%d",counter);
                break;
            }

        }
        if(z==newsize)
            {printf("0");}
    return 0;
}
