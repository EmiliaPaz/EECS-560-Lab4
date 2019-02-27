#include <iostream>
////////////////////////////////////////////////////////////////////////////////
//////////                    Constructors                            //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
HashTable_Closed<T>::HashTable_Closed(int size, char t, int R_value, int k_value)
{
    numKeys = 0;
    numBuckets = size;
    type = t;
    R = R_value;
    k = k_value;
    array = new T[size];

    for(int i=0; i<numBuckets; i++)
    {
        array[i] = 0;
    }

}


////////////////////////////////////////////////////////////////////////////////
//////////                     Destructor                             //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
HashTable_Closed<T>::~HashTable_Closed()
{
    delete[] array;
}


////////////////////////////////////////////////////////////////////////////////
//////////                       Methods                              //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
bool HashTable_Closed<T>::insert(T key)
{
    // Exception: empty array
    if(numBuckets==0)
    {
        numBuckets = 3;
        T* newArray = new T[numBuckets];
        for(int i=0; i<numBuckets; i++)
        {
            newArray[i]=0;
        }
        delete[] array;
        array = newArray;
    }

    // hash the key
    int h = hash(key);
    int e = 1;

    // Check for duplicates
    if(array[h]!=key)
    {
        numKeys++;

        // Quadratic Probing
        if(type=='q')
        {
            while(array[h]!=0)
            {
                h = (key + e*e)% numBuckets;
                if (e==k)
                {
                    numKeys--;
                    return false;
                }
                e++;
            }
        }
        // Double Hashing
        else if (type=='d')
        {
            // Second hashing function
            int h2 = R - (key % R);
            int h0 = h;
            int i=1;
            while(array[h]!=0)
            {
                h = (h0 + (h2*i)) % numBuckets;
                i++;
                if(i==k)
                {
                    numKeys--;
                    return false;
                }
            }
        }

        // Insert key at correct position
        array[h] = key;
        return true;
    }
    return false;
}

template<class T>
bool HashTable_Closed<T>::remove(T key)
{
    if(numBuckets>0)
    {
        // hash the key
        int h = hash(key);

        // Delete key if found at the hashed position
        if(array[h]==key)
        {
            numKeys --;
            array[h]=0;
            return true;
        }
        ////// Check other possible hashed positions
        // Quadratic Probing
        else if(type=='q')
        {
            // Quadratic probing redo
            int e = 1;
            while(array[h]!=key)
            {
                // Quadratic probing
                h = (key + e*e)% numBuckets;
                if (e==k)
                {
                    return false;
                }
                e++;
            }
            numKeys--;
            array[h]=0;
            return true;
        }
        // Double Hashing
        else if (type=='d')
        {
            // Second hashing function
            int h2 = R - (key % R);
            int h0 = h;
            int i=1;
            while(array[h]!=key)
            {
                h = (h0 + (h2*i)) % numBuckets;
                i++;
                if(i==k)
                {
                    return false;
                }
            }
            numKeys--;
            array[h]=0;
            return true;
        }
    }
    return false;

}

template<class T>
bool HashTable_Closed<T>::find(T key)
{
    if(numBuckets>0)
    {
        // hash the key
        int h = hash(key);

        // Return position if found at the hashed position
        if(array[h]==key)
        {
            return h;
        }
        ///////// Check other possible hashed positions
        // Quadratic Probing
        else if(type=='q')
        {
            // Quadratic probing redo
            int e = 1;
            while(array[h]!=key)
            {
                h = (key + e*e)% numBuckets;
                if (e==k)
                {
                    return false;
                }
                e++;
            }
            return h;
        }
        // Double Hashing
        else if (type=='d')
        {
            // Second hashing function
            int h2 = R - (key % R);
            int h0 = h;
            int i=1;
            while(array[h]!=key)
            {
                h = (h0 + (h2*i)) % numBuckets;
                i++;
                if(i==k)
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}


template<class T>
void HashTable_Closed<T>::print()
{
    for(int i=0; i<numBuckets; i++)
    {
        std::cout << i << ": " << array[i] << "\n";
    }
}


////////////////////////////////////////////////////////////////////////////////
//////////                    Helper Methods                          //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
int HashTable_Closed<T>::hash(T key)
{
    return (key%numBuckets);
}
