package algorithms_week2;

import java.io.*;
import java.util.Scanner;


@SuppressWarnings("unused")
public class insertion_sort {

	@SuppressWarnings("resource")
	public static void main(String args[])
	{
		
		Scanner scan = new Scanner(System.in);
		int n;
		
		System.out.println("Enter number of elements you want to insert : ");
		n = scan.nextInt();
		
		int[] array= new int[n];
	
		System.out.println("Enter elements : ");
		
		for (int i=0; i<array.length; i++)
		{
			array[i] = scan.nextInt();
		}
		
		System.out.println("Unsorted list");
		for (int i=0; i<array.length; i++)
		{
			System.out.println(array[i]);
		}
		
		int i,j,index;

		for (i=1; i<n; i++)
		{
			index = array[i];
			j=i;

			while(j>0 && array[j-1] > index)
			{
				array[j] = array[j-1];
				j--;
			}
			array[j]= index;
		}
		
		System.out.println("Sorted list");
		
		for (int a=0; a<array.length; a++)
		{
			System.out.println(array[a]);
		}
	}
}
