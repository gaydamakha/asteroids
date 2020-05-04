#ifndef SIMPLEX_CHAR_H
#define SIMPLEX_CHAR_H

#include <Utils.h>
#include <Geometry.h>

using Symbol = ShapeWithVertices;
using Symbols = IterableCollection<Symbol>;

class SimplexChar
{
    static const unsigned short desc_chars = 112;
    const unsigned short width;
    Symbols symbols;
public:
    SimplexChar(const int desc[desc_chars]);

    inline Symbols getSymbols() const { return symbols; }

    inline unsigned short getWidth() const { return width; }
};

#endif