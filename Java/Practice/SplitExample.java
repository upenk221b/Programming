import java.util.*;

public class SplitExample{
	static Scanner scan = new Scanner(System.in);
	public static void main(String[] args){
		StringBuilder sb = new StringBuilder();
		sb.append(scan.nextLine());
		String A = sb.toString().trim();
		String[] Arr = A.split("[\\s]+");

	System.out.println(sb +"      "+A);
		
	for(String str :Arr){	
	System.out.println(str);
	}
	}

}
