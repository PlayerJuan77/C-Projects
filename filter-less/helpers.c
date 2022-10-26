#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h=0; h < height; h++)
    {
        for (int w=0; w < width; w++){
        int av = (image[h+1][w+1].rgbtRed * image[h+1][w+1].rgbtBlue * image[h+1][w+1].rgbtGreen) / 3.0;
        if (av > 255){
        image[h+1][w+1].rgbtRed = 255;
        image[h+1][w+1].rgbtGreen = 255;
        image[h+1][w+1].rgbtBlue = 255;
        }
        else {
        image[h+1][w+1].rgbtRed = av;
        image[h+1][w+1].rgbtGreen = av;
        image[h+1][w+1].rgbtBlue = av;
        }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int ored = image[height][width].rgbtRed;
    int oblue = image[height][width].rgbtBlue;
    int ogreen = image[height][width].rgbtGreen;
    for (int h=0; h<height; h++){

        for (int w=0; w<width; w++){
            int sred = (ored * .393) + (ogreen * .769) + (oblue * .189);
            int sgreen = (ored * .349) + (ogreen * .686) + (oblue * .168);
            int sblue = (ored * .272) + (ogreen * .534) + (oblue * .131);
        if (sred > 255){
            image[h][w].rgbtRed = 255;
        }
        else {image[h][w].rgbtRed = sred;}
        if (sblue > 255){
            image[h][w].rgbtBlue = 255;
        }
        else {image[h][w].rgbtBlue = sblue;}
        if (sgreen > 255){
            image[h][w].rgbtGreen = 255;
        }
        else {image[h][w].rgbtGreen = sgreen;}
        }
            }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < (width / 2); w++)
        {
            RGBTRIPLE swap = image[h][w];
            image[h][w] = image[h][width - w - 1];
            image[w][width - h - 1] = swap;
    }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){
    int sred = 0;
    int sblue = 0;
    int sgreen = 0;
    float counter = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++){

        if (h + i < 0 || h + i > height - 1 || w + j < 0 || w + j > width - 1){
        continue;
    }

             sred += image[h + i][w + j].rgbtRed;
             sblue += image[h + i][w + j].rgbtBlue;
             sgreen += image[h + i][w + j].rgbtGreen;
             counter++;
    }
    }
    temp[h][w].rgbtBlue = round(sblue/counter);
    temp[h][w].rgbtGreen = round(sgreen/counter);
    temp[h][w].rgbtRed = round(sred/counter);
           }
        }
        for (int h = 0; h < height; h++){
            for (int w =0; w <width; w++){
                image[h][w].rgbtRed = temp[h][w].rgbtRed;
                image[h][w].rgbtGreen = temp[h][w].rgbtGreen;
                image[h][w].rgbtBlue = temp[h][w].rgbtBlue;

        }
    }
    return;
}
