import java.util.*;
import java.io.*;

class Main {
    private static InputReader br = new InputReader(System.in);
    private static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) {
        String st = br.next();
        int n = st.length(), a[] = new int[256];


        for(int i=0; i<n; i++)
            a[(int)st.charAt(i)]++;

        Arrays.sort(a,0,256);

        int cnt = 0, ans = 0;
        for(int i=255; i >= 0 && a[i] != 0; i--, cnt++)
            if(cnt >= 2) ans += a[i];

        pr.println(ans);
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
