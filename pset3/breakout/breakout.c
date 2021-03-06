//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//
// Modified by Jason Studstill
//
// standard libraries

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// height of brick's total footprint, including white space
#define BHFOOT 24

// width of brick's total footprint, including white space
#define BWFOOT 40

// radius of ball in pixels
#define RADIUS 10

// height and width of paddle
#define PHEIGHT 8
#define PWIDTH 60

// lives
#define LIVES 3

// ball starting point on y-axis
#define BSP 475

// paddle starting point on y-axis
#define PSP 520

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    
    // set ball's velocity
    double x_velocity = (double) drand48() * -3;
    double y_velocity = -3;

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    initScoreboard(window);
   
    // add paddle to window at starting coordinates
    add(window, paddle);
    
    // add ball to window at starting coordinates
    add(window, ball);
    
    // instantiate scoreboard and "update it" to starting value
    updateScoreboard(window, label, points); 
    
    waitForClick();
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // instatiate scoreboard and "update it" to starting value
        updateScoreboard(window, label, points);

        // determine paddle's movement
        GEvent event = getNextEvent(MOUSE_EVENT);
       
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) / 2;
                double y = PSP;
                if (x > (WIDTH - getWidth(paddle)))
                {
                    setLocation(paddle, WIDTH - getWidth(paddle), y);
                }
                else if (x < 0)
                {
                    setLocation(paddle, 0, y);
                }
                else
                {
                    setLocation(paddle, x, y);
                }
            }
        } 

        // listen for collision
        GObject object = detectCollision(window, ball); 

        
        // if ball touches window, while moving left to right, reverse direction
        if (getX(ball) + getWidth(ball) >= WIDTH)
        {
            x_velocity = -x_velocity;
        }
        
        // if ball touches window, while moving left to right, reverse direction
        else if (getX(ball) <= 0)
        {
            x_velocity = -x_velocity;
        }

        // if ball is touching bottom of window: lose a life, start over       
        else if (getY(ball) + getWidth(ball) >= HEIGHT)
        {
            lives--;
            waitForClick();
 
            // reposition ball and paddle in the center of window
            if (lives > 0)
            {
                setLocation(ball, (WIDTH / 2) - RADIUS, BSP);
                setLocation(paddle, (WIDTH - PWIDTH) / 2, PSP);
                y_velocity = -y_velocity;
                waitForClick();
            }
  
        }
        
        // bounce off top of window
        else if (getY(ball) <= 0)
        {
            y_velocity = -y_velocity;
        }
        
        // bounce off paddle
        else if (object == paddle)
        {
            y_velocity = -y_velocity;
        }

        // react to objects
        else if (object != NULL)
        {
            // do nothing if ball touches scoreboard
            if (strcmp(getType(object), "GLabel") == 0)
            {
                // do nothing
            }
            // remove the brick, add point, and change bounce direction
            else
            {
                removeGWindow(window, object);
                y_velocity = -y_velocity;
                points++;
                bricks--;
            }
        }       

               
        // move ball "x_velocity" px  on x-axis and y_velocity px on y-axis
        move(ball, x_velocity, y_velocity);
                
        // pause 10 ms between each movement of velocity px
        pause(10);   
    }

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // define brick's actual dimensions, providing space between bricks
    int bheight = BHFOOT - 2 ;
    int bwidth = BWFOOT - 2;
    
    // declare variables for determining each new bricks starting position
    int nbrick_y = 20;
    int nbrick_x = 20;
    
    for (int i = 0; i < ROWS; i++)
    {
        nbrick_x = 0;
        
        for (int j = 0; j < COLS; j++)
        {
            // create a brick at the start of the first brick's 
            // footprint or 0,0
            GRect brick = newGRect(nbrick_x, nbrick_y, bwidth, bheight);
            setColor(brick, "RED");
            setFilled(brick, true);
            
            add(window, brick);
            nbrick_x += BWFOOT;
        }
                
        nbrick_y += BHFOOT;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    
    GOval ball = newGOval((WIDTH / 2) - RADIUS, BSP, RADIUS * 2, RADIUS * 2);
    setColor(ball, "BLUE");
    setFilled(ball, true);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // create paddle centered in the middle of the screen
    GRect paddle = newGRect((WIDTH - PWIDTH) / 2, PSP, PWIDTH, PHEIGHT);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
