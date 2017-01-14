import java.util.Scanner;
import java.math.BigInteger;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger sum = BigInteger.ZERO;
        while(true){
            String next = sc.next();
            if(next.compareTo("0") == 0)
                break;
            sum = sum.add(new BigInteger(next));
        }
        System.out.println(sum);
    }
}
