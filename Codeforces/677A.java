import java.util.*;

public class Main {
	static Scanner inp = new Scanner(System.in);
	public static void main(String[] args) {
		int n = inp.nextInt();
		int h = inp.nextInt();
		int ans = 0;
		for(int i=0; i<n; i++){
			int x;
			x = inp.nextInt();
			if(x>h) ans+=2;
			else ans+=1;
		}
		System.out.print(ans);
	}
}
