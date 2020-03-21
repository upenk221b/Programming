/* input = aaabbbbcddddd
output = a3b4c1d5*/
import java.util.*;
public class multipleChar{
	static Scanner scan = new Scanner(System.in);
	public static void main(String []args){
		String s;
		s = scan.nextLine();
		int freq[] = new int[26];
		for(int i = 0 ; i< 26; i++){
			freq[i] = 0;
		}
		for(int i = 0 ; i< s.length(); i++){
			freq[s.charAt(i) - 'a']++;
		}
		for(int i = 0 ; i< s.length(); i++){
			if(freq[s.charAt(i) - 'a']!=0){
			System.out.print(s.charAt(i)+Integer.toString(freq[s.charAt(i) - 'a']));
			freq[s.charAt(i) - 'a'] =0;	
			}
		}

	}
}
