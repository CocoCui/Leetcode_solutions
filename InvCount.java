
//HW 1 Programming Problem
//Author: Xin Wen
//MPCS 55001
//Autumn 2016

import java.io.InputStream;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class InvCount {

	//Input: an ArrayList of distinct integers.
	//Output: the number of inversions in the array.
	public static int invCount(ArrayList<Integer> a) {
		// Insert your code here. You may also write additional functions if
		// necessary.
		if(a.size() <= 1) {
			return 0;
		}
		//int leftCount, rightCount, mergeCount;
		//ArrayList<Integer> after = new ArrayList<Integer>();
		return mergeSort(a, 0, a.size());
	}
    
    public static int merge(ArrayList<Integer> a, int l, int m, int r) {
        int a1 = l, a2 = m, inv = 0;
        ArrayList<Integer> temp = new  ArrayList<Integer>();
        while(a1 < m && a2 < r) {
            if(a.get(a1) <= a.get(a2)) temp.add(a.get(a1++));
            else {
                temp.add(a.get(a2++));
                inv += (m - a1);
            }
        }
        while(a1 < m) temp.add(a.get(a1++));
        while(a2 < r) temp.add(a.get(a2++));
        for(int i = l; i < r; i++) a.set(i, temp.get(i - l));
        return inv;
    }
    
	public static int mergeSort(ArrayList<Integer> a, int l, int r) {
        int mid = (l + r) / 2, count = 0;;
        if(r > l + 1) {
            count += mergeSort(a, l, mid);
            count += mergeSort(a, mid, r);
            count += merge(a, l, mid, r);
        }
        return count;
    }
    
	/**** DO NOT EDIT ****/
	public static void main(String[] args) throws FileNotFoundException {
		InputStream in = System.in;
		PrintStream out = System.out;
		/**** DO NOT EDIT ****/

		// If you want your test cases to be in files, you can uncomment the block of
		// four lines below and change the filenames accordingly, but when you turn in
		// your homework, make sure to comment them out again.
		// String inFilename = "invs_input.txt";
		// String outFilename = "test.txt";
		// in = new FileInputStream(inFilename);
		// out = new PrintStream(outFilename);

		/**** DO NOT EDIT ****/
		Scanner s = new Scanner(in);
		while(s.hasNextLine()) {
			if (!s.hasNextInt()) break;
			Scanner t = new Scanner(s.nextLine());
			ArrayList<Integer> a = new ArrayList<Integer>();

			while(t.hasNextInt()) {
				a.add(t.nextInt());
			}
			int invs = invCount(a);
			out.println(invs);
			/**** DO NOT EDIT ****/
		}
	}
}

