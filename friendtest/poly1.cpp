//Name:        
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   4

#include "poly1.h"

main_savitch_3::polynomial::polynomial()
{
    coef = new double[size];
    for(int i = 0; i < size; i++)
    {
        coef[i] = 0;
    }

}

main_savitch_3::polynomial::polynomial(double a0)
{
    coef = new double[size];
    coef[0] = a0;
    for(int i = 1; i < size; i++)
    {
        coef[i] = 0;
    }
}

main_savitch_3::polynomial::polynomial(const polynomial &source)
{
    coef = new double[source.size];
    size = source.size;
    std::copy(source.coef, source.coef+size, coef);
}

main_savitch_3::polynomial::~polynomial()
{
    delete [ ] coef;
}

void main_savitch_3::polynomial::add_to_coef(double amount, unsigned int k)
{
    if(k > size - 1)
    {

    }
    else
    {
        coef[k] += amount;
    }
}

void main_savitch_3::polynomial::assign_coef(double coefficient, unsigned int k)
{
    if(k > size - 1)
    {

    }
    else
    {
        coef[k] = coefficient;
    }
}

void main_savitch_3::polynomial::clear()
{
    for(int i = 0; i < size; i++)
    {
        coef[i] = 0;
    }
}

void main_savitch_3::polynomial::reserve(size_t number)
{
    double *larger_array;

    if (number == size)
    {
        return;
    }

    if (number < size)
    {
        number = size;
    }

    larger_array = new double[number];
    for(int i = 0; i < number; i++)
    {
        larger_array[i] = 0;
    }
    std::copy(coef, coef + size, larger_array);
    delete [ ] coef;
    coef = larger_array;
    size = number;
}

main_savitch_3::polynomial & main_savitch_3::polynomial::operator=(const polynomial &source)
{
    if (this == &source) {
        return *this;
    }

    else {
        delete [ ] coef;
        coef = new double[source.size];
        size = source.size;
        for (int i = 0; i < size; i++) {
            coef[i] = source.coef[i];
        }
    }
    return *this;
}

double main_savitch_3::polynomial::coefficient(unsigned int k) const
{
    if(k > size - 1)
    {
        return 0;
    }
    else
    {
        return coef[k];
    }
}

unsigned int main_savitch_3::polynomial::degree() const
{
    int k = 0;

    for(int i = 0; i < size; i++)
    {
        if(coef[i] != 0)
        {
            k = i;
        }
        else
        {

        }
    }

    return k;
}

unsigned int main_savitch_3::polynomial::next_term(unsigned int k) const
{
    if(k > size)
    {
        return 0;
    }

    for(int i = k; i < size; i++)
    {
        if(coef[i] != 0)
        {
            k = i;
        }
        else
        {

        }
    }

    return k;
}

double main_savitch_3::polynomial::eval(double x) const
{
    double base = x;
    double power;
    double ans = coef[0];
    for(int i = 1; i < size; i++)
    {
        power = i;
        ans += coef[i] * (pow(base,power));
    }

    return ans;
}

main_savitch_3::polynomial main_savitch_3::operator+(const main_savitch_3::polynomial& p1, const main_savitch_3::polynomial& p2) {
    int size1 = p1.degree();
    int size2 = p2.degree();
    if(size1 > size2)
    {
        main_savitch_3::polynomial answer(p1);
        for(int i = 0; i < size1 + 1; i++)
        {
            answer.add_to_coef(p2.coefficient(i), i);
        }
        return answer;
    }

    else if(size2 > size1)
    {
        main_savitch_3::polynomial answer(p2);
        for(int i = 0; i < size2 + 1; i++)
        {
            answer.add_to_coef(p1.coefficient(i), i);
        }
        return answer;
    }

    else
    {
        main_savitch_3::polynomial answer(p1);
        for(int i = 0; i < size1 + 1; i++)
        {
            answer.add_to_coef(p2.coefficient(i), i);
        }
        return answer;
    }
}

main_savitch_3::polynomial main_savitch_3::operator-(const main_savitch_3::polynomial& p1, const main_savitch_3::polynomial& p2) {
    int size1 = p1.degree();
    int size2 = p2.degree();
    if(size1 > size2)
    {
        main_savitch_3::polynomial answer(p1);
        for(int i = 0; i < size1 + 1; i++)
        {
            answer.add_to_coef(-(p2.coefficient(i)), i);
        }
        return answer;
    }

    else if(size2 > size1)
    {
        main_savitch_3::polynomial answer(p2);
        int number = 0;
        for(int i = 0; i < size1 + 1; i++)
        {
            number = p1.coefficient(i) - p2.coefficient(i);
            answer.assign_coef(number, i);
        }
        for(int i = size1 + 1; i < size2 + 2; i++)
        {
            number = -1 * (answer.coefficient(i));
            answer.assign_coef(number, i);

        }
        return answer;
    }

    else
    {
        main_savitch_3::polynomial answer(p1);
        for(int i = 0; i < size1 + 1; i++)
        {
            answer.add_to_coef(-(p2.coefficient(i)), i);
        }
        return answer;
    }
}

