//
// Created by Bisrat Asefaw on 1/11/20.
//

#include "polynomial.h"

//--- default constructor ------//
Polynomial::Polynomial() {
    size = 0;
    Term *dummy = new Term;
    dummy->next = dummy->prev = nullptr;
    dummy->coeff = 0.0;
    dummy->power = 0;
    head = dummy;
}

//-----destructor ---//
Polynomial::~Polynomial() {
    Term *current = head;
    while (current != nullptr) {
        current = current->next;
        delete current;
        current = nullptr;
    }
}


//---copy constructor ----//
Polynomial::Polynomial(const Polynomial &p) {
    if (p.head == nullptr) {
        return;
    }
    this->size = p.size;
    Term *dummyHead = new Term;
    dummyHead->coeff = 0.0;
    dummyHead->power = 0;

    Term *current = p.head->next;
    Term *curr = dummyHead;

    while (current != p.head) {
        Term *temp = new Term;
        temp->power = current->power;
        temp->coeff = current->coeff;
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
        current = current->next;

    }
    curr->next = dummyHead;
    dummyHead->prev = curr;
    head = dummyHead;
}

//---formated out put--//
ostream &operator<<(ostream &output, const Polynomial &p) {
    Polynomial::Term *current = p.head->next;
    while (current != p.head) {

        if (current->coeff != 1 && current->power != 1) {
            if (current->power != 0) {
                output << current->coeff << "x^" << current->power;
            } else {
                output << current->coeff;
            }

        } else {
            if (current->power == 1 && current->coeff != 1) {
                output << current->coeff << "x";
            } else if (current->coeff == 1 && current->power != 1) {
                output << "x^" << current->power;
            } else {
                output << "x";
            }
        }
        if (current->next->coeff > 0) {
            output << " + ";
        }
        current = current->next;
    }
    return output;
}

//----changeCOefficient ----//
bool Polynomial::changeCoefficient(const double newCoefficient, const int power) {

    if (head->next == nullptr) {
        Term *temp1 = new Term;
        temp1->coeff = newCoefficient;
        temp1->power = power;
        head->next = temp1;
        temp1->prev = head;
        temp1->next = head;
        head->prev = temp1;
        size++;
        return true;
    }
    Term *current = head->next;
    while (current != head) {
        if (current->power == power && newCoefficient == 0) {
            remove(current);
            return true;
        }
        if (current->power == power) {
            current->coeff = newCoefficient;
            return true;
        }
        if (current->power < power) {
            insert(current, newCoefficient, power);
            return true;
        }
        current = current->next;
    }
    if (power == 0) {
        Term *temp2 = new Term;
        temp2->power = power;
        temp2->coeff = newCoefficient;
        Term *tem3 = current->prev;
        tem3->next = temp2;
        temp2->prev = tem3;
        temp2->next = current;
        current->prev = temp2;
        return true;
    }
    return false;
}

bool Polynomial::remove(Polynomial::Term *pos) {
    if (pos == nullptr) {
        return false;
    }
    Term *temp1 = pos->next;
    Term *temp2 = pos->prev;
    temp1->prev = temp2;
    temp2->next = temp1;
    delete pos;
    pos = nullptr;
    size--;
    return true;
}

bool Polynomial::insert(Polynomial::Term *pos, const double newCoefficient, const int power) {

    if (pos != nullptr) {
        Term *temp = new Term;
        Term *temp2 = pos->prev;
        temp->power = power;
        temp->coeff = newCoefficient;

        temp2->next = temp;
        temp->prev = temp2;
        pos->prev = temp;
        temp->next = pos;
        size++;
        return true;
    }
    return false;
}

int Polynomial::degree() const {
    Term *current = head->next;
    int max = 0;
    while (current != head) {
        if (current->power > max) {
            max = current->power;
        }
        current = current->next;
    }
    return max;
}

double Polynomial::coefficient(const int power) const {
    Term *current = head->next;
    double coefficient = 0;
    while (current != head) {
        if (current->power == power) {
            coefficient = current->coeff;
        }
        current = current->next;
    }
    return coefficient;
}

//---- "+" operator overloading ----//
Polynomial Polynomial::operator+(const Polynomial &p) const {
    Polynomial temp3 = *this;

    Term *current = p.head->next;
    Term *curr = temp3.head->next;

    while (current != p.head) {

        while (curr != temp3.head && current->power < curr->power) {
            curr = curr->next;
        }
        if (curr->power == current->power) {
            double newCoefficient = curr->coeff + current->coeff;
            temp3.changeCoefficient(newCoefficient, current->power);
        } else {
            temp3.changeCoefficient(current->coeff, current->power);
        }
        current = current->next;
    }

    return temp3;
}

Polynomial Polynomial::operator-(const Polynomial &p) const {
    Polynomial temp3 = *this;

    Term *current = p.head->next;
    Term *curr = temp3.head->next;

    while (current != p.head) {

        while (curr != temp3.head && current->power < curr->power) {
            curr = curr->next;
        }
        if (curr->power == current->power) {
            double newCoefficient = curr->coeff - current->coeff;
            temp3.changeCoefficient(newCoefficient, current->power);
        } else {
            temp3.changeCoefficient(-1 * current->coeff, current->power);
        }
        current = current->next;
    }

    return temp3;
}


bool Polynomial::operator==(const Polynomial &p) const {

    Term *current = this->head->next;
    Term *curr = p.head->next;
    while (current != this->head) {
        if (curr->power != current->power || curr->coeff != current->coeff) {
            return false;
        }
        curr = curr->next;
        current = current->next;
    }
    return curr == p.head;
}

bool Polynomial::operator!=(const Polynomial &p) const {
    return !(*this == p);
}

Polynomial &Polynomial::operator=(const Polynomial &p) {
    if(&p==this){
        return *this;
    }
    Polynomial temp(p);
    std::swap(temp.head,head);
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &p) {

    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &p) {
    return *this;
}








