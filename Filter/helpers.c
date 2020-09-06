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
    RGBTRIPLE carry;
    
    int iInv;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < trunc(width/2); j++)
        {
            iInv = width - i - 1;
            
            carry.rgbtRed = image[i][j].rgbtRed;
            carry.rgbtGreen = image[i][j].rgbtGreen;
            carry.rgbtBlue = image[i][j].rgbtBlue;
            
            image[i][j].rgbtRed = image[iInv][j].rgbtRed;
            image[i][j].rgbtGreen = image[iInv][j].rgbtGreen;
            image[i][j].rgbtBlue = image[iInv][j].rgbtBlue;
            
            image[iInv][j].rgbtRed = carry.rgbtRed;
            image[iInv][j].rgbtGreen = carry.rgbtGreen;
            image[iInv][j].rgbtBlue = carry.rgbtBlue;
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
