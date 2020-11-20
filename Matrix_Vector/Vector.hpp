#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <cmath>
#include <vector>

template<typename T> class Vector
{
private:
	std::vector<T> mData; // data stored in vector
	int mSize; // size of vector

public:

	Vector(int size)
    {
        assert(size > 0);

        mData.reserve(size);
        for (int i = 0; i < size; i++)
        {
            mData.push_back(0);
        }
        mSize = mData.size();
    }

    Vector(){  // overridding default constructor
        mSize = mData.size();
    }

	int size() const
    {
        return mSize;
    }

	T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

	T const& operator[] (int i)const
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

    // overloading the unary - operator
	Vector<T> operator-() const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }

    // overloading the binary + operator
	Vector<T> operator+(const Vector<T>& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
	Vector<T> operator-(const Vector<T>& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	// scalar multiplication
	Vector<T> operator*(T a) const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

	// p-norm method
	T CalculateNorm(int p = 2) const
    {
        T sum = 0;
        for (int i = 0; i < mSize; i++)
        {
            sum += pow(std::abs(mData[i]), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
    }

    // const reference to mData
    std::vector<T> const& getStorage() const{
        std::vector<T> const& storage = mData;
        return storage;
    }


};


#endif
