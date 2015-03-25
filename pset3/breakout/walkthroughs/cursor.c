#include <stdio.h>
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

int main(void)
{
     GWindow window = newGWindow(320,240);
     
/*     Create oval called circle, whose top left corner is set at 0 on the */
/*     Y-axis and 110 on the X-axis, with a width 20 and a height of 20.*/
/*     So, with a diameter of 20 (and a radius of 10) and a starting position */
/*     of 110 on the X-axis, as defined by its top-left corner, the ball */
/*     will be centered in the window at 130 px.*/
             
     
     // Grapical Oval called "circle" get a starting position of 0 on Y-axis
     // and 110 on X-axis, width 20, height 20  
     
     GOval circle = newGOval(0,110, 20, 20);
     setColor(circle, "BLACK");
     setFilled(circle, true);
     
     // Add the object "circle" to the object "window"
     add(window, circle);
     
     double velocity = 2.0;
     
     // Create in infinite loop that listens for mouse events, in this case
     //  mouse movements
     while(true)
     {
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {

                // Get the X-coordinate of where the mouse was moved to, then 
                // subtract the radius of the circle to ensure the ball is centered
                // on the cursor 
                double x = getX(event) - getWidth(circle) / 2;
                double y = gety(event) - getWidth(circle);
                
                // Set location of variable "circle" to X-coordinate as defined by
                // variable "x" and Y-coordinate as defined by variable "y" above                
                setLocation(circle, x, y);
            }
        }
     }
}
