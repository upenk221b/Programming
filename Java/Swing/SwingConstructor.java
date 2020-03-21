import javax.swing.*;
public class SwingConstructor {

	JFrame f;
	SwingConstructor(){
	f = new JFrame();
	
	JButton b = new JButton("click");
	b.setBounds(100,120,80,40);
	
	f.add(b);

	f.setSize(400,500);
	f.setLayout(null);
	f.setVisible(true);
	




	public static void main(String [] args){

	

	new SwingConstructor();


	}









}
