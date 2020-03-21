import java.util.*;

// Write your Checker class here
class Checker implements Comparator<Player>{
    public int compare(Player a, Player b) 
    { 
        if(a.lastName.compareTo(b.lastName) == 0){
            return (a.firstName.compareTo(b.firstName));
        }
        return a.lastName.compareTo(b.lastName); 
    }  
}
class Player{
    String firstName;
    String lastName;
    
    Player(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }
}

public class Compare {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();
        
        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.nextLine(), scan.nextLine());
        }
        scan.close();

        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].firstName, player[i].lastName);
        }
    }
}
