package others;

import java.util.Scanner;

public class digits_to_numbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		int[] array = new int[4];
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter numbers : ");
		
		for (int i=0;i<array.length;i++)
		{
			array[i]=scan.nextInt();
		}
		
		String result = "";
		
		for (int i=0;i<array.length;i++)
		{
			int x = array[i];
			result = result + String.valueOf(array[i]);
		}
		
		int output = Integer.parseInt(result);
		
		System.out.println("Number formed : "+output);
		System.out.println(output + " + 1 = " + (output+1));
		
		
		int[] array2= new int[array.length];
		
		String number = String.valueOf(output);
		
		for(int i = 0; i < number.length(); i++) 
		{
		    int j = Character.digit(number.charAt(i), 10);
		    array2[i]=j;
		}
		
		System.out.println("In array again :");
		for (int i=0;i<array2.length;i++)
		{
			System.out.println(array2[i]);
		}
		
	}

}
