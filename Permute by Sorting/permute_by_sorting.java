package algorithms_homework3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class permute_by_sorting {
	
	
	public static void main(String args[])
	{
		
		int[] array = new int[20];
		Scanner scan = new Scanner(System.in);
		
		
		for (int i=0;i<array.length;i++)
			array[i]= scan.nextInt();
		
		System.out.println("Original array");
		for (int i=0;i<array.length;i++)
			System.out.println(array[i]);
		
		permute_by_sorting_method(array);
		
	}
	
	public static void permute_by_sorting_method(int[] array)
	{
		
		int[] priorities = {23,45,6,65,77,12,34,24,48,11,34,50,70,59,22,15,19,28,54,94};
		
		List<prioritized<Integer>> list = new ArrayList<prioritized<Integer>>(array.length);
		
		
		
		
		for (int i=0;i<array.length;i++)
			list.add(new prioritized<Integer>(array[i], priorities[i]));
		
		
		Collections.sort(list);
		
		int[] permuted = new int[array.length];
		
		for (int i=0;i<array.length;i++)
			permuted[i] = list.get(i).value;
		
		System.out.println(Arrays.toString(permuted));
	
	}
}
		
	class prioritized<T> implements Comparable<prioritized<T>>
	{
		
		final T value;
		final int priority;
		
		prioritized(T value, int priority)
		{
			this.value=value;
			this.priority= priority;
		}
		
		@Override
		public int compareTo(prioritized other) {
			// TODO Auto-generated method stub
			return Integer.valueOf(this.priority).compareTo(other.priority);
		}
		
	}
		
		
		
	
	
