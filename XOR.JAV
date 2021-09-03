import java.applet.Applet;
import java.awt.*;

public class Xor extends Applet{
 int Aheight,Awidth;
 
 public void init(){
  Dimension d=size();
  Aheight=d.height;
  Awidth=d.width;
  repaint();
  }
  
 public void paint(Graphics g) {
  Color pixcol;
  for (int nbr1=0;nbr1<Awidth;nbr1++)
   for (int nbr2=0;nbr2<Aheight;nbr2++){
     pixcol=new Color(nbr1,nbr2,nbr1^nbr2);
     g.setColor(pixcol);
     g.drawLine(nbr1,nbr2,nbr1+1,nbr2+1);     
   } 
 } 
 
 
  private int Randomize (int range)
 { double rawResult;
   rawResult=Math.random();
   return (int)(rawResult*range);
   
 }

}
