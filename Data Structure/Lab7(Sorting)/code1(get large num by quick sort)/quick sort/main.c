#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void freq(int arr2[],int len)
{
   int count=0,count_digit=0;
   int *digit_num;
   digit_num=malloc(len*sizeof(int));
   for(int i=0;i<len;i++)
   {
       count=0;
       int l=arr2[i];
       while(l>0)
       {
           l/=10;
           count++;
       }
//array to get largest num of digits in array .
       digit_num[i]=count;
       if(count>count_digit)
        count_digit=count+1;
   }


   int new_element;
   //handling numbers to get equel digits.
   for(int i=0;i<len;i++)
   {
    new_element=arr2[i];
    int count_new=digit_num[i];
    while(count_new<count_digit)
    {
        new_element=new_element*pow(10,digit_num[i])+arr2[i];
        count_new=0;
        int new_element_1=new_element;
        while(new_element_1>0)
        {
            new_element_1/=10;
            count_new++;
        }
    }
    while(count_new>count_digit)
    {
        new_element/=10;
        count_new--;
    }
    arr2[i]=new_element;
   }

}


/*##########################################################################################################*/


// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// main function
int main() {

     int i,size,element;
    scanf("%d",&size);
     int arr[size],arr2[size];


    for(i=0;i<size;i++){

       scanf("%d",&element);
       arr[i]=element;
       arr2[i]=element;
    }

    freq(arr2,size);


   int arr3[size];
   for(int g=0;g<size;g++)
   {
      arr3[g]=arr2[g];
   }
  quickSort(arr3, 0, size - 1);

  for(int i=size-1;i>=0;i--)
  {
      element=arr3[i];
      for(int j=0;j<size;j++)
      {
          if(arr2[j]==element)
          {
              printf("%d",arr[j]);
              break;
          }
      }
  }
  return 0;
}
