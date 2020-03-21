import java.util.*;

public class hacker{

public static void main(String []args){
		int id=0,n; 
		Scanner scan = new Scanner(System.in);
		n=scan.nextInt();
		int t[] = new int[n];
		System.out.println("lenth= "+t.length);
		for(int i=0; i<n; i++){
			t[i] = scan.nextInt();
		}
	int start =0;
	for(int k=0; k<n;k++){
		if(t[k]==0){
		start = k;
		break;
		}
		}
     for(int j=start; j<t.length; j++){
	
	     
	     
             int i = j;System.out.println("i= "+i);
             int count =0;
             do{
                	System.out.println(t[(i+1)%(t.length)]+"< "+(t[i]+1));
			if(t[(i+1)%(t.length)] <= (t[i]+1) ){
                     i=(i+1)%(t.length);
                      count++;
		System.out.println("count= "+count);
                 }else{System.out.println("Break");
                     break;
                 }
                
		
                }while(i!=j);
		System.out.println("Out of While");
                if(count == t.length){
                    id = j+1;
			System.out.println("ANSWER= "+id);
                    break;
               }        
        
    
    }
System.out.println(id);
}	

}
         
