/*
ID: mark29s1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.*;

class test {
    public static void main (String[] args) throws IOException {

        // Use BufferedReader rather than RandomAccessFile; it's much faster
        BufferedReader f = new BufferedReader(new FileReader("test.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
        // Use StringTokenizer vs. readLine/split -- lots faster
        // Get line, break into tokens
        StringTokenizer st = new StringTokenizer(f.readLine());
        // first integer
        int i1 = Integer.parseInt(st.nextToken());
        // second integer
        int i2 = Integer.parseInt(st.nextToken());
        // output result
        out.println(i1+i2);
        // close the output file
        out.close();

        System.exit(0);
    }
}
