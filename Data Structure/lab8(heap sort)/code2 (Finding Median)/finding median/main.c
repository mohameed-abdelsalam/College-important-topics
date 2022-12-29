// Heap Sort in C

  #include <stdio.h>

  // Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  // Driver code
  int main()
{
    int n, i;
    float median=0;
    scanf("%d",&n);
    int array[n] ;
    for (i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    heapSort(array, n);

    if (n<=0)
    printf("Not Exist");

    else if (n%2==0)
      {
         median=(array[(n-1)/2] + array[n/2])/2.0;
         if(median==(int)median)
            printf("%d",(int)median);
         else
         printf("%0.1f",median);
      }
    else if (n%2==1)
    {
       median=array[n/2];
       median==(int)median;
       printf("%d",median);
    }
}
