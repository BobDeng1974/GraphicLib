//
//  Bitmap.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <stdio.h>
#include "Ref.hpp"
#include <string>

namespace ze {
    
    /**
     A bitmap image (i.e. a grid of pixels).
     This is not related to openGL , but can be used to make a openGL texture
     */
    class Bitmap : public Ref {
        
    public:
        
        /**
         Represents the number of channels per pixel, and the order of the channels.
         
         Each channel is one byte (unsigned char).
         */
        enum Format {
            Format_Grayscale = 1, /**< one channel: grayscale */
            Format_GrayscaleAlpha = 2, /**< two channels: grayscale and alpha */
            Format_RGB = 3, /**< three channels: red, green, blue */
            Format_RGBA = 4 /**< four channels: red, green, blue, alpha */
        };

        /**
         default constructor
         */
        Bitmap();
        
        ~Bitmap();
        
        /**
         create a image with specified width height and format
         
         */
        Bitmap(unsigned with ,
               unsigned height ,
               Format format ,
               const unsigned char * pixels = nullptr);
        
        /**
         pointer to the raw pixel of the data of the bitmap
         */
        unsigned char * getPixelBuffer() const;
        
        unsigned char * getPixel(unsigned width , unsigned height) const;
        
        void setPixel(unsigned col , unsigned row , const unsigned char * pixel);
        
        void flipVertically();
        
        void rotate90CounterClockwise();
        
        /**
         Copies a rectangular area from the given source bitmap into this bitmap.
         
         If srcCol, srcRow, width, and height are all zero, the entire source
         bitmap will be copied (full width and height).
         
         If the source bitmap has a different format to the destination bitmap,
         the pixels will be converted to match the destination format.
         
         Will throw and exception if the source and destination bitmaps are the
         same, and the source and destination rectangles overlap. If you want to
         copy a bitmap onto itself, then make a copy of the bitmap first.
         */
        void copyRectFromBitmap(const Bitmap& src,
                                unsigned srcCol,
                                unsigned srcRow,
                                unsigned destCol,
                                unsigned destRow,
                                unsigned width,
                                unsigned height);
        
        static Bitmap loadFromFile(std::string filePath);
        
        /** Copy constructor */
        Bitmap(const Bitmap& other);
        
        /** Assignment operator */
        Bitmap& operator = (const Bitmap& other);
        
        /**
         init a image with specified width height and format
         
         */
        bool init(unsigned with ,
                  unsigned height ,
                  Format format ,
                  const unsigned char * pixels = nullptr);
        
        /**
         width in pixels
         */
        inline unsigned getWidth() const {
            return _width;
        }
        
        /**
         height in pixels
         */
        inline unsigned getHeight() const {
            return _height;
        }
        
        /**
         the pixels format of the bitmap
         */
        inline Format getFormat() const {
            return _format;
        }
        
    protected:
        
        unsigned _width;
        
        unsigned _height;
        
        Format _format;
        
        unsigned char * _pixels;
    };
    
}

#endif /* Bitmap_hpp */
















