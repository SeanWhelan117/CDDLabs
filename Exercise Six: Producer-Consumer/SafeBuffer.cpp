#include "SafeBuffer.h"

template <typename T>
SafeBuffer<T>::SafeBuffer(int t_size) : size(t_size), spaces(t_size), mutex(1), items(0)
{

}


template <typename T>
void SafeBuffer<T>::put(T item)
{
  spaces.Wait();
  mutex.Wait();

  
  buffer.push_back(item);


  
  mutex.Signal();
  items.Signal();
}

template <typename T>
T SafeBuffer<T>::get()
{
  items.Wait();
  mutex.Wait();


  
  T item = buffer.front();
  buffer.erase(buffer.begin());




  
  mutex.Signal();
  spaces.Signal();


  return item;
}

template class SafeBuffer<char>;
