//add eetsize

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <vector>

    /**
     * @class Vector
     * @brief Minimal vector class. wraps the STL vector inside.
     * @author Mitchell Wilson - 34497163
     */
template <class T>
class Vector
{
public:
        /**
        * @brief vector assignment operator
        *Copies arrays over, moves the pointer to new array, deletes old array, copies variables.
        * @param two vectors
        */
    Vector & operator = (const Vector & t);

        /**
        * @brief vector equality operator
        * @return bool - true if the same, false if not
        * @param two vectors
        */
    bool operator == (const Vector & t);
         /**
         * @brief vector [] operator
         Does not allow writing.
         * @param int n - index location
         * @return returns the array at index n
         * @pre n needs to be in bounds
         */
     const T & operator [](const int n)const;

        /**
         * @brief default constructor
         */
    Vector();
        /**
         * @brief default destructor
         */
    ~Vector();
        /**
         * @brief constructor with size
         * @param int n - size of the vector
         */
    Vector(const int & n);
        /**
         * @brief Copy Constructor
         * @param Vector & t - Vector to be copied
         */
    Vector(const Vector & t);

        /**
         * @brief Adds to the vector
         * @param t - an object of the class
         * @return void
         */
    void pushBack(const T & t); //needs to be &??

        /**
         * @brief Getter for length
         * @return int - value of length
         */
    int GetLength() const;

        /**
         * @brief Empties the array
         * @return void
         */
    void Empty();
        /**
         * @brief increases the size of the vector
         * @return void
         * @pre n must be larger than length
         */
    void SetSize(int n);
        /**
         * @brief checks if the vector is empty
         * @return bool, true if vector is empty, false if it is not
         */
    bool IsEmpty();

private:
    std::vector<T> Vect;
};


template<class T>
Vector<T>::Vector()
{
}
template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & vect)
{
    if (this->Vect != vect.Vect)
    {
        this->Vect = vect.Vect;
    }
    return *this;
}

template<class T>
bool Vector<T>:: operator == (const Vector<T> & vect)
{
    return this->Vect == vect.Vect;
}

template <class T>
const T & Vector<T>::operator [](const int n) const
{
    return Vect[n];
}

template<class T>
Vector<T>::Vector(const int & n)
{
    if (n < 0)
        throw "Must be more than 0";
    this->Vect.reserve(n);
}

template<class T>
Vector<T>::Vector(const Vector & t)
{
    this->Vect = t.Vect;
}

template<class T>
Vector<T>::~Vector()
{
}

template <class T> //needs to be &??
void Vector<T>::pushBack(const T & t)
{
    Vect.push_back(t);
}

template <class T>
int Vector<T>::GetLength() const
{
    return Vect.size();
}
template <class T>
void Vector<T>::Empty()
{
    this->Vect.clear();
}

template <class T>
void Vector<T>::SetSize(int n)
{
    Vect.reserve(n);
}

template<class T>
bool Vector<T>::IsEmpty()
{
    return Vect.empty();
}
#endif // VECTOR_H_INCLUDED
