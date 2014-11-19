#include "texturefetch.hpp"
#include <iostream>

/*
 *  Pour la documentation de ces fonctions, se rapporter à la page "Textures" de la documentation
 */
/*
 * @brief getTexel Get a single texel from a texture.
 * This function access the texture at coordinates (row, column) and fetch the value of the corresponding texel (pixel from a texture)
 * @param pixels    The image to access, organized as a linear array of texel arranged by row
 * @param width     Width of the image
 * @param height    Height of the image
 * @param depth     Depth of the image (number of component by texel)
 * @param row       Row coordinate of the requested texel
 * @param column    Column coordinate of the requested texel
 * @return          The value of the texel
 * @todo            Transfom the 2D coordinates in a 1D index and get the corresponding texel value
 */
Color getTexel(unsigned char *pixels, int width, int height, int depth, int column, int row) {
    Color color;
    int posValue = (row*width+column)*depth;

    switch(depth) {
    case 1:
        color = Color((double)pixels[posValue]/255);
        break;
    case 3:
    case 4:
        color = Color((double)pixels[posValue]/255, (double)pixels[posValue+1]/255, (double)pixels[posValue+2]/255);
        break;
    }
    if(depth == 4) {
        color *= ((double)pixels[posValue+3]/255);
    }


    return color;
}

/*
 * @brief interpolateTexture Get a texel linearly interpolated from its neighbors
 * @param pixels    The image to access, organized as a linear array of texel arranged by row
 * @param width     Width of the image
 * @param height    Height of the image
 * @param depth     Depth of the image (number of component by texel)
 * @param s         The column coordinate of the requested texel as a floating point
 * @param t         The row coordinate of the requested texel as a floating point
 * @return          The value of the interpolated texel
 */
Color interpolateTexture(unsigned char *pixels, int width, int height, int depth, float s, float t) {
    Color q11, q12, q21, q22;
    Color r1, r2;

    // Values of four points (Q11, Q12, Q21, Q22)
    q11 = getTexel(pixels, width, height, depth, s, t);
    q12 = getTexel(pixels, width, height, depth, s, t+1);
    q21 = getTexel(pixels, width, height, depth, s+1, t);
    q22 = getTexel(pixels, width, height, depth, s+1, t+1);

    // r1 and r2 calculs
    r1 = (1-(s-std::floor(s)))*q11 + (s-std::floor(s))*q21;
    r2 = (1-(s-std::floor(s)))*q12 + (s-std::floor(s))*q22;

    return (1-(t-std::floor(t)))*r1 + (t-(std::floor(t)))*r2;
}


/*
 * @brief integrateTexture Get a texel by computing the mean of the color on a neighborood of size (deltas x deltat)
 * @param pixels    The image to access, organized as a linear array of texel arranged by row
 * @param width     Width of the image
 * @param height    Height of the image
 * @param depth     Depth of the image (number of component by texel)
 * @param s         The column coordinate of the requested texel as a floating point
 * @param t         The row coordinate of the requested texel as a floating point
 * @param deltas    The size, in the column dimension, of the neighborood
 * @param deltat    The size, in the row dimension, of the neighborood
 * @return
 */
Color integrateTexture(unsigned char *pixels, int width, int height, int depth, float s, float t, int deltas, int deltat) {
    Color color;

    for (int i=s; i < s+deltas; ++i) {
       for (int j=t; j < t+deltat; ++j) {
           color = color + getTexel(pixels, width, height, depth, i, j);
       }
   }

   return color * (1. / (deltas*deltat));
}
int gcd(int m, int n)     	// function definition
{                         	// block begin
   int  r;                	// declaration of remainder

   while (n != 0) {       	// not equal
      r = m % n;          	// modulus operator
      m = n;              	// assignment
      n = r;
   }                      	// end while loop
   return m;              	// exit gcd with value m
}

/**
 * @brief setPixel Change the value of a pixel
 * @param pixels The pixels array
 * @param coord Coordonate of pixel in vector
 * @param depth     Depth of the image (number of component by texel)
 * @param c The color of new pixel
 */
void setPixel(unsigned char *pixels, int coord, int depth, Color c) {
    if (depth == 1) {
        pixels[coord] = c[0] * 255;
    } else {
        pixels[coord] = c[0] * 255;
        pixels[coord+1] = c[1] * 255;
        pixels[coord+2] = c[2] * 255;
    }
}

/*
 * @brief prefilterTexture Compute an array of images with geometrically decreasing resolution from the original image.
 * @param imagearray The array of images to compute. element at index 0 in this array is the full resolution image and must not be modified
 * @param width     Width of the full resolution image
 * @param height    Height of the full resolution image
 * @param depth     Depth of the image (number of component by texel)
 * @param nblevels  Number of level to compute : nblevels = log2(min(width, height))
 * @return          if the array may be filled, return true, else return false
 */
bool prefilterTexture(unsigned char **imagearray, int width, int height,
                      int depth, int nblevels)
{
    int widthLevel = width;
    int heightLevel = height;
    Color buffColor;

    for (int level=1; level < nblevels; ++level) {
        widthLevel /= 2;
        heightLevel /= 2;

        try {
            imagearray[level] =  new unsigned char[width * height * depth];
        } catch(std::bad_alloc&) {
            return false;
        }

        for (int c=0; c <= widthLevel; ++c) {
            for (int r=0; r <= heightLevel; ++r) {
                buffColor.reset();
                for(int i = 2*c ; i <= 2*c+1 ; ++i) {
                    for(int j = 2*r ; j <= 2*r+1 ; ++j) {
                        buffColor += getTexel(imagearray[level-1], 2*widthLevel, 2*heightLevel, depth, i, j);
                    }
                }

                buffColor *= (1./4);
                setPixel(imagearray[level], c*depth*widthLevel + r*depth, depth, buffColor);
            }
        }

    }

    return true;
}

