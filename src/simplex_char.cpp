#include "interface/font/simplex_char.h"

SimplexChar::SimplexChar(const int desc[desc_chars]) : width(desc[1])
{
    int nb_vertices = desc[0]*2;
    bool is_pen_up = true;
    for (int i = 2; i < nb_vertices + 2; i += 2)
    {
        Symbol s;
        while (desc[i] != -1)
        {
            s.addVertice(Vec2d(desc[i], desc[i+1]));
            i += 2;
        }
        symbols.push(s);
    }
}