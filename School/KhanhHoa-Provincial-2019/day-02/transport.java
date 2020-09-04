import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class transport {
    private static final int INF = (int) 1e9;

    private static boolean check_connected(int n, ArrayList<ArrayList<Integer>> adj) {
        Queue<Integer> q = new LinkedList<Integer>();
        boolean visited[] = new boolean[n + 1];
        Arrays.fill(visited, false);

        int visit_cnt = 0;
        q.add(1);
        visited[1] = true;
        while (!q.isEmpty()) {
            int u = q.poll();
            visit_cnt += 1;
            for (int v : adj.get(u)) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.add(v);
                }
            }
        }

        return visit_cnt == n;
    }

    private static int calculate_depth(int u, int depth[], boolean visited[], ArrayList<ArrayList<Integer>> adj) {
        visited[u] = true;
        depth[u] = 0;
        for (int v : adj.get(u)) {
            if (!visited[v]) {
                depth[u] = Math.max(depth[u], calculate_depth(v, depth, visited, adj) + 1);
            }
        }
        return depth[u];
    }

    private static void transfer(int u, int got_file_at[], ArrayList<ArrayList<Integer>> adj) {
        int cnt = 1;
        for (int v : adj.get(u)) {
            if (got_file_at[v] > got_file_at[u] + cnt) {
                got_file_at[v] = got_file_at[u] + cnt;
                cnt += 1;
                transfer(v, got_file_at, adj);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        int n = sc.nextInt();
        assert(1 <= n && n <= 100000);

        int s = sc.nextInt();
        assert(1 <= s && s <= n);

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();

            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        assert(check_connected(n, adj));

        int depth[] = new int[n + 1];
        boolean visited[] = new boolean[n  + 1];
        Arrays.fill(visited, false);
        calculate_depth(s, depth, visited, adj);

        for (int i = 1; i <= n; i++) {
            // System.out.printf("%d (%d) - Before: %s\n", i, depth[i], adj.get(i).toString());
            Collections.sort(adj.get(i), new Comparator<Integer>() {
                @Override
                public int compare(Integer a, Integer b) {
                    return Integer.compare(depth[b], depth[a]);
                }
            });
            // System.out.printf("%d (%d) - After: %s", i, depth[i], adj.get(i).toString());
        }

        int got_file_at[] = new int[n + 1];
        Arrays.fill(got_file_at, INF);
        got_file_at[s] = 0;
        transfer(s, got_file_at, adj);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, got_file_at[i]);
        }

        System.out.println(ans);

        sc.close();
    }
}
