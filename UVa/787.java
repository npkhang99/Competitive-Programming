import java.util.Scanner;
import java.math.BigInteger;

class Main{
    static int n;
    static BigInteger[] a = new BigInteger[109];

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            n = 0;
            while(sc.hasNextInt()){
                int next = sc.nextInt();
                if(next == -999999) break;
                a[n++] = BigInteger.valueOf(next);
            }

            BigInteger ans = a[0];
            for(int i=0; i<n; i++){
                if(a[i].intValue() == 0){
                    ans = ans.max(a[i]);
                    continue;
                }
                BigInteger temp = BigInteger.ONE;
                for(int j=i; j<n; j++){
                    temp = temp.multiply(a[j]);
                    ans = ans.max(temp);
                    if(a[j].intValue() == 0) continue;
                }
            }
            System.out.println(ans);
        }
    }
}
