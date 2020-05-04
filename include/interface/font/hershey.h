#ifndef HERSHEY_FONT_H
#define HERSHEY_FONT_H

#include <Utils.h>
#include <string>
#include "simplex_char.h"

using Font = IterableCollection<SimplexChar>;

class Hershey
{
private:
    static const unsigned short first_code = 32;
    static const unsigned short nb_chars = 95;
    static const unsigned short desc_chars = 112;
    static const unsigned short min_code = 32;
    static const unsigned short max_code = 126;
    static const int raw[nb_chars][desc_chars];
    Font letters;
public:
    Hershey();

    Font getFont() const { return letters; }

    SimplexChar get(char) const;
    Font get(std::string) const;
};

#endif