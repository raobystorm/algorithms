package LCOJ_2;
import java.util.Scanner;
import javaxt.io.*;

public class Solution {
	
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
		if( l1 == null) return l2;
		if( l2 == null) return l1;
		
		ListNode curr = new ListNode(0);
		ListNode res = curr;

		int incre = 0;
		
		
		while(true){
			
			incre += l1.val + l2.val;
			curr.val = incre % 10;
			incre /= 10;
			if(l1.next == null || l2.next == null) break;
			l1 = l1.next;
			l2 = l2.next;
			curr.next = new ListNode(0);
			curr = curr.next;
		}
		
		if( l1.next != null){
			
			while(l1.next != null){
				
				l1 = l1.next;
				incre += l1.val;
				curr.next = new ListNode(incre%10);
				incre /= 10;
				curr = curr.next;
			}
		}else if ( l2.next != null){
			
			while(l2.next != null){
				
				l2 = l2.next;
				incre += l2.val;
				curr.next = new ListNode(incre%10);
				incre /= 10;
				curr = curr.next;
			}
		}
		
		if ( incre > 0){
			while(incre > 0){
				curr.next = new ListNode(incre%10);
				curr = curr.next;
				incre /= 10;
			}
		}
		return res;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int i1, i2, tmpin = 0;
		Scanner sc = new Scanner(System.in);
		i1 = sc.nextInt();
		i2 = sc.nextInt();
		ListNode l1;
		ListNode curr;
		ListNode l2;
		ListNode res;
		
		curr = new ListNode(0);
		curr.val = sc.nextInt();
		l1 = curr;
		for(int i = 1; i < i1; i++){
				
			tmpin = sc.nextInt();
			curr.next = new ListNode(tmpin);
			curr = curr.next;
		}
		
		curr = new ListNode(0);
		curr.val = sc.nextInt();
		l2 = curr;
		for(int i = 1; i < i2; i++){
				
			tmpin = sc.nextInt();
			curr.next = new ListNode(tmpin);
			curr = l2.next;
		}
		
		res = new Solution().addTwoNumbers(l1, l2);
		
		while( res != null){
			
			System.out.print(res.val);
			res = res.next;
		}
		System.out.println();
		
		sc.close();
	}
}
