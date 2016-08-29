import java.util.Scanner;

public class Main{
	static Scanner scnr=new Scanner(System.in);
	public static void main(String[] args){
		int n=scnr.nextInt();
		if(n>2 && n%2==0) System.out.println("YES");
		else System.out.println("NO");
	}
}
