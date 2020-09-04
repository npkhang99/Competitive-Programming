import java.util.ArrayList;
import java.util.Scanner;

public class checkin {
    private static boolean can_serve_with_max_time(ArrayList<Integer> time_to_serve, long upper_bound, int m) {
        long served = 0;
        for (int i = 0; i < time_to_serve.size(); i++) {
            served += upper_bound / time_to_serve.get(i);
        }
        return served >= m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> time_to_serve = new ArrayList<Integer>();
        int n = sc.nextInt();
        assert(1 <= n && n <= 100000);
        int m = sc.nextInt();
        assert(1 <= m && m <= 1000000000);
        for (int i = 0; i < n; i++) {
            int time = sc.nextInt();
            
            assert(1 <= time && time <= 1000000000);
            
            time_to_serve.add(time);
        }

        long ans = 0;
        long l = 1, r = 1000000000000000000L;
        while (l <= r) {
            long mid = (l + r) / 2;
            if (can_serve_with_max_time(time_to_serve, mid, m)) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }

        System.out.println(ans);
        sc.close();
    }
}
