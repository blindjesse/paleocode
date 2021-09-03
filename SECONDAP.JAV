import java.applet.*;
import java.awt.*;

public class SecondApplet extends Applet{
	static final String message = "Hello World";
	private Font font;
	private Color col;	
	private int rd;
	private int gr;
	private int bl;	
	public void init(){
           font = new Font("TimesRoman",Font.BOLD,48);	
           col=null;
           rd=0;
	   gr=0;
	   bl=0;	
            	
	}
	
public void paint(Graphics g){
for (int nbr=1;nbr<200;nbr++){
  rd=(rd+nbr)%64;
  gr=(gr+nbr)%64;
  bl=(bl+nbr)%64;
  col=new Color(rd,gr,bl);
  g.setColor(col);
  g.setFont(font);
  g.drawString(message,nbr,nbr);
 
  }
  g.setColor(Color.white);
  g.drawString(message,200,200);
 } 
 
}  	
