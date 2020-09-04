import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.ArrayList;

public class password {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TreeMap<String, Integer> cnt = new TreeMap<String, Integer>();
        ArrayList<String> passwords = new ArrayList<String>();
        
        int n = sc.nextInt();
        assert(1 <= n && n <= 10000);
        for (int i = 0; i < n; i++) {
            String st = sc.next();

            assert(1 <= st.length() && st.length() <= 10);

            passwords.add(st);
            if (cnt.containsKey(st)) {
                cnt.replace(st, cnt.get(st) + 1);
            }
            else {
                cnt.put(st, 1);
            }
        }

        for (String password : passwords) {
            long ans = 0;
            TreeSet<String> used = new TreeSet<String>();
            for (int l = 0; l < password.length(); l++) {
                for (int r = l + 1; r <= password.length(); r++) {
                    if (!used.contains(password.substring(l, r)) && cnt.containsKey(password.substring(l, r))) {
                        ans += cnt.get(password.substring(l, r));
                        used.add(password.substring(l, r));
                    }
                }
            }

            System.out.println(ans - 1);
        }

        sc.close();
    }
}
