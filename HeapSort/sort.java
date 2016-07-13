package algorithms_homework4;

import java.util.Arrays;

public class sort {

	 public static int heapSize;
	public static int left(int i)
    {
        return 2*i+1;
    }
    public static int right(int i)
    {
        return 2*i+2;
    }
    public static void buildMaxHeap(int A[])
    {
        heapSize = A.length; 
        for(int i=A.length/2; i>=0;i--)
        {
            maxHeapify(A, i);
        }
    }
    public static void maxHeapify(int A[],int i)
    {
        int lt=left(i);
        int rt=right(i);
        int largestElementIndex = -1;
         if(lt<heapSize && A[lt]>A[i]){
            largestElementIndex = lt;
        }
        else
        {
            largestElementIndex=i;
        }
         if(rt<heapSize && A[rt]>A[largestElementIndex])
        {
            largestElementIndex = rt;
        }
        if(largestElementIndex!=i)
        {
            int temp = A[i];
            A[i]=A[largestElementIndex];
            A[largestElementIndex]=temp;
            maxHeapify(A, largestElementIndex);
        }
    }


    public static void heapSort(int A[])
    {
    buildMaxHeap(A);
  
    for(int i=A.length-1;i>=0;i--)
    {
       int temp = A[0];
        A[0]=A[i];
        A[i]=temp;
       heapSize  = heapSize-1;
       maxHeapify(A,0);
    }
}
public static void main(String[] args) {
    int[] array = new int[]{10, 15, 8, 12, 5, 2, 20, 7, 18};
    System.out.println("Input Array");
    System.out.println(Arrays.toString(array));
    buildMaxHeap(array);
    System.out.println("The Array After buildMAxHeap method");
    System.out.println(Arrays.toString(array));  
    heapSort(array);
    System.out.println("Final Sorted Array after Heapsort Algorithm");
    System.out.println(Arrays.toString(array));
}


}
