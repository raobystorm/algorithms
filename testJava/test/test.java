package test;

import java.util.*;
import java.io.*;

public class test {
    public static void main(String args[]) {

        int n = 0, m;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s;
        try{
            s = in.readLine();
            n = Integer.parseInt(s);
            int dp[][] = new int[n + 1][20];

            for (int i = 0; i < n; i++) {
                s = in.readLine();
                dp[i][0] = Integer.parseInt(s);
            }

            for (int j = 1; (1 << j) <= n; j++)
                for (int i = 0; i + (1 << j) - 1 < n; i++) {
                    dp[i][j] = Math.min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
                }

            s = in.readLine();
            m = Integer.parseInt(s);
            for(; m > 0; m--){
                int l, r;
                s = in.readLine();
                l = Integer.parseInt(s.substring(0, s.indexOf(' ')));
                r = Integer.parseInt(s.substring(s.indexOf(' ')+1));
                l--;
                r--;
                int k = 0;
                while ((1 << (k + 1)) <= r - l + 1) k++;
                System.out.println(Math.min(dp[l][k], dp[r - (1 << k) + 1][k]));
            }

        }catch (IOException ie){
            System.out.println("Ye shi la!");
        }
    }
}