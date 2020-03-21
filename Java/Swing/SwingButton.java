import javax.swing.*;
public class SwingButton{
	public static void main(String [] args){
	JFrame j = new JFrame();

	JButton b = new JButton("click");
	
	j.add(b);
	b.setBounds(100,100,100,30);

	j.setSize(500,400);
	j.setLayout(null);
	j.setVisible(true);


	}


}
