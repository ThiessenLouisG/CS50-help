#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Setting up the variables in the loops!
    float average;
    int avg;
    
    // Loops!
    for (int i = 0; i < height; i++)
    {
        // More loops!!
        for (int j = 0; j < width; j++)
        {
            // Sets up the average of all three RGB values
            average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            
            // Rounds it to an int
            avg = round(average);
            
            
            // Sets the average of the three values to the new values
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    
    return;
}

int overflowCorrect(int);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loops!
    for (int i = 0; i < width; i++)
    {
        // More loops!
        for (int j = 0; j < height; j++)
        {
            // Puts the red, green and blue values through the given sepia equations
            int sepiaR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            // Sets the values from the equations to the RGB values for the pixel
            image[i][j].rgbtRed = overflowCorrect(sepiaR);
            image[i][j].rgbtGreen = overflowCorrect(sepiaG);
            image[i][j].rgbtBlue = overflowCorrect(sepiaB);
        }
    }
    
    /*
    Aforementioned equations
    
    sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */
    
    return;
}

int overflowCorrect(int in)
{
    if (in > 255) return 255;
    else return in;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width /2); j++)
        {
            // Stores the A values in holding
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            
            // Switches B to A
            image[i][j].rgbtRed = image[i][width - j -1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j -1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j -1].rgbtGreen;
            
            // Switches holding to B
            image[i][width - j -1].rgbtRed = red;
            image[i][width - j -1].rgbtBlue = blue;
            image[i][width - j -1].rgbtGreen = green;
            
            // Loops the entire image
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Holding holds a copy of image to carry the unchanged values as a reference
    RGBTRIPLE holding[height][width];

    // Goes through holding and measures values changing them on image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avgRed = 0;
            float avgBlue = 0;
            float avgGreen = 0;
            
            float counter = 0.00;
            
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if (i + a < 0 || i + a > height -1 || j + b > 0 || j + b < 0 || j + b > width -1)
                    {
                        continue;
                    }
                    
                    avgRed += image[i + a][j + b].rgbtRed;
                    avgBlue += image[i + a][j + b].rgbtBlue;
                    avgGreen += image[i + a][j + b].rgbtGreen;
                    
                    counter++;
                    
                }
            }
            
            if (counter != 0)
            {
                holding[i][j].rgbtRed = round(avgRed/counter);
                holding[i][j].rgbtGreen = round(avgGreen/counter);
                holding[i][j].rgbtBlue = round(avgBlue/counter);
            }
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = holding[i][j].rgbtRed;
            image[i][j].rgbtGreen = holding[i][j].rgbtGreen;
            image[i][j].rgbtBlue = holding[i][j].rgbtBlue;
        }
    }
    
    return;
}
