import java.util.Scanner;
import java.util.Arrays;
public class Anagram {
    static boolean isAnagram(String a, String b) {
        String s1 = a.replaceAll("\\s","");//remove white spaces
        String s2 = b.replaceAll("\\s","");

        //check if length is same
        if(s1.length()!=s2.length()){
            return false;
        }
        else{
            char[] CharArr1 = s1.toLowerCase().toCharArray();
            char[] CharArr2 = s2.toLowerCase().toCharArray();

            Arrays.sort(CharArr1);  
            Arrays.sort(CharArr2);  
            
            if(Arrays.equals(CharArr1,CharArr2))
            {
                return true;
            }
            else{
                return false;
            }
        }
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.nextLine();
        String b = scan.nextLine();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
