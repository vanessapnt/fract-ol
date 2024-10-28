#include "fractol.h"

int ft_isdigit(char c) 
{
    return (c >= '0' && c <= '9');
}

static bool has_integer_part(char **s)
{
    bool has_integer_part;

    has_integer_part = false;
    if (**s == '-' || **s == '+')
        (*s)++;
    while (ft_isdigit(**s))
    {
        has_integer_part = true;       
        (*s)++;
    }
    return has_integer_part;
}

static bool    has_decimal_part(char **s)
{
    bool has_decimal_part;

    has_decimal_part = false;
    if (**s == '.')
    {
        (*s)++;            
        while (ft_isdigit(**s))
        {
            has_decimal_part = true;
            (*s)++;            
        }
    }
    return has_decimal_part;
}
/*
1) if no integer part
2) if integer part, but not the end and no decimal
3) if not the end
*/
bool is_valid_number(char *str)
{
    char *s;

    s = str;
    if (!has_integer_part(&s) || (*s != '\0' && !has_decimal_part(&s))|| *s != '\0')
        return false;
    return true;
}
