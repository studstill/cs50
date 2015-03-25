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
     
     // Create in infinite loop that checks the balls position
     while(true)
     {
        // move("This variable", "This many px on X-axis, by "This many px Y-axis")
        move(circle, velocity, 0);
        
/*        If the circle's location, plus the width of the circle itself is now*/
/*        past the edge of the window, reverse velocity.  Remember the position*/
/*        of the circle is determined by its top-left corner.*/
        
        // If, while moving left to right, the circle touches window, reverse direction
        if (getX(circle) + getWidth(circle) >= getWidth(window))
        {
            //Flip velocity from positive to negative or negative to positive
            velocity = -velocity;
        }
        
        // If, while moving right to left, the circle touches window, reverse direction
        else if (getX(circle) <= 0)
        {
            velocity = -velocity;
        }
        
        // Pause 10 milliseconds between each movement of "velocity" pixels
        pause(10);
     }
}
