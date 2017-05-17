
//
//  polynomial.h
//  Spr17_Midterm
//
//

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#ifndef polynomial_h
#define polynomial_h

/**************************************************************
 A Term is a coefficient and exponent pair of ints
 */
class Term {
    friend std::ostream& operator<<(std::ostream& output, const Term& t){
        output << t.toString();
        return output;
    }
public:
    Term(int co, int ex)
    : coef{co}, expo{ex}
    { /* no code */ }

    int getCoef() const { return coef; }
    void setCoef(int co) { coef = co; }
    int getExpo() const { return expo; }
    void setExpo(int ex) { expo = ex; }
    void print() const {
        std::cout << coef << "x^" << expo;
    }

    std::string toString() const{
        std::ostringstream out{};
        out << getCoef() << "x^" << getExpo();
        return out.str();
    }

    bool operator==(const Term& t) const{
        return getCoef() == t.getCoef() && getExpo() == t.getExpo();
    }

    bool operator!=(const Term& t) const{
        return getCoef() != t.getCoef() && getExpo() != t.getExpo();
    }

    Term& operator=(const Term& t){
       setCoef(t.getCoef());
       setExpo(t.getExpo());
    }

private:
    int coef;
    int expo;
};

/****************************************************************
 Polynomials are stored in: vector<Term>.
 The Terms are stored lowest degree term first
 in standard form.
 A term with zero coef must include the zero
 in the initial vector of coefficients.
 3x^2 + -2x^1 + 4 <--> {3, -2, 4}
 1x^2 + -6        <--> {1, 0, -6}
 Polynomials have only one variable, x.
 */
class Polynomial {
    //**** Overload the stream insertion (<<) operation for Polynomial
    //     Consider "borrowing" from the print() function below
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p){
        out << p.toString();
        return out;
    }

public:
    // Pass in coefficients highest order term
    //   first down to lowest order
    Polynomial(const std::vector<int>& coefs) {
        int high{static_cast<int>(coefs.size() - 1)};

        // Create the terms from the vector of coefficients
        // Lowest degree term (x^0) is stored first
        for (int expo{0}, i{high}; i >= 0; i -= 1, expo += 1) {
            Term term{coefs.at(i), expo};
            poly.push_back(term);
        }
    }

    // Print highest degree term first down to lowest
    void print() const {
        for (std::size_t i{poly.size() - 1}; i > 0; i -= 1) {
            Term term{poly.at(i)};
            term.print();  // cannot do this with overloaded <<, hmmmm....?
            std::cout << " + ";
        }
        std::cout << poly.at(0).getCoef() << std::endl;
    }

    std::string toString() const{
        std::ostringstream out{};

        for (std::size_t i{poly.size() - 1}; i > 0; i -= 1) {
            Term term{poly.at(i)};
            out << term;
            out << " + ";
        }
        out << poly.at(0).getCoef();

        return out.str();
    }

    //**** Overload the + operation for Polynomial
    Polynomial operator+(const Polynomial& p){
        //return this->poly + p.poly;
    }

    //**** Overload the == operation for Polynomial
    bool operator==(const Polynomial& p){
        return this->poly == p.poly;
    }

    //**** Overload the != operation for Polynomial
    bool operator!=(const Polynomial& p){
        return this->poly != p.poly;
    }

private:
    std::vector<Term> poly{};
};

#endif /* polynomial_h */
