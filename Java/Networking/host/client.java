import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class client {

    public static void main(String args[])
    { 
        if(args.length != 2){
            System.out.println("usage: java client <port> <something>");
            System.exit(1);
        }
        
        int port = isParseInt(args[0]);
        if(port == -1){
            System.out.println("usage: java client <port> <something>");
            System.out.println("<port>: integer");
            System.exit(1);
        }
        
        try{
            //IP is hard coded, Local Loopback = "127.0.0.1"
            //port is user entry
            Socket socket = new Socket("127.0.0.1", port);

            
            //Send msg to server
            OutputStream outputStream = socket.getOutputStream();
            PrintStream printStream = new PrintStream(outputStream);
            printStream.print(args[1]);
                
            socket.close();

        }catch(UnknownHostException e){
            System.out.println(e.toString());
        }catch(IOException e){
            System.out.println(e.toString());
        }

    }
    
    private static int isParseInt(String str){
        
        int num = -1;
        try{
             num = Integer.parseInt(str);
        } catch (NumberFormatException e) {
        }
        
        return num;
    }
    
}
