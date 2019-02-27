
////////////////////////////////////////////////////////////////////////////////
//////////                    Constructors                            //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
HashTable_Open<T>::HashTable_Open(int size)
{
    numKeys = 0;
    numBuckets = size;
    array = new LinkedList<T>*[size];
    for(int i=0; i<numBuckets; i++)
    {
        array[i] = new LinkedList<T>();
    }

}


////////////////////////////////////////////////////////////////////////////////
//////////                     Destructor                             //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
HashTable_Open<T>::~HashTable_Open()
{
    for(int i=0; i<numBuckets; i++)
    {
        delete array[i];
    }
    delete[] array;
}


////////////////////////////////////////////////////////////////////////////////
//////////                       Methods                              //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
bool HashTable_Open<T>::insert(T key)
{
    // Exception: empty array
    if(numBuckets==0)
    {
        numBuckets = 3;
        LinkedList<T> ** newArray = new LinkedList<T>*[numBuckets];
        for(int i=0; i<numBuckets; i++)
        {
            newArray[i] = new LinkedList<T>();
        }
        delete[] array;
        array = newArray;
    }

    // hash the key
    int h = hash(key);

    // insert if not duplicate
    if(!array[h]->findEntry(key))
    {
        numKeys++;
        array[h]->insert(key);
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
bool HashTable_Open<T>::remove(T key)
{
    if(numBuckets>0)
    {
        if(array[hash(key)]->remove(key))
        {
            numKeys--;
            return true;
        }
    }
    return false;
}

// Assumes T is an int
template<class T>
int HashTable_Open<T>::hash(T key)
{
    return (key%numBuckets);
}


template<class T>
void HashTable_Open<T>::print()
{
    for(int i=0; i<numBuckets; i++)
    {
        std::cout << i << ":" ;
        array[i]->print();
    }
}


template<class T>
int HashTable_Open<T>::find(T key)
{
    if(numBuckets>0)
    {
        // hash the key
        int h = hash(key);
        // insert if not duplicate
        if(array[h]->findEntry(key))
        {
            return true;
        }
    }
    return false;
}
