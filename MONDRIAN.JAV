import java.applet.*;
import java.awt.*;

public class Mondrian3 extends Applet {
 int height, width;

int AppletHeight;
int AppletWidth;
int RectLeft;
int RectWidth;
int RectTop;
int RectHeight;
Color RectColor;
int numRects=100;
 
 public void init() {
  Dimension d = size();
  AppletHeight = d.height;
  AppletWidth = d.width;
  String s = getParameter("Number");
  if (s!=null){
    numRects = Integer.valueOf(s).intValue();  
  }
  repaint();
  
  }
   
public void paint(Graphics g) {
 for (int nbr=0;nbr<numRects;nbr++){ 
  g.setColor(RectColor);
  RectHeight=Randomize(AppletHeight);
  RectWidth=Randomize(AppletWidth);
  RectLeft=Randomize(AppletWidth - RectWidth);
  RectTop=Randomize(AppletHeight - RectHeight);
  RectColor=new Color(Randomize(255),Randomize(255),Randomize(255));  
  g.drawRect(0,0,AppletHeight-1,AppletWidth-1);
  g.fillRect(RectLeft,RectTop,RectWidth-1,RectHeight-1);
 }
}

 private int Randomize ( int range)
 { double rawResult;
   rawResult=Math.random();
   return (int)(rawResult*range);
   
 }
 
}
