import java.util.*;
import java.io.*;

class Main {
    private static InputReader br = new InputReader(System.in);
    private static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) {
        int n = br.nextInt();
        int a[] = new int[1000009];
        for(int i=0; i<n; i++)
            a[i] = br.nextInt();

        Arrays.sort(a,0,n);
        int ans = (int)1e9;
        for(int i = 0, j = n-1; i < j; i++, j--)
            ans = Math.min(ans, a[j] + a[i]);
        pr.printf("%d\n", ans);
        pr.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return line;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
