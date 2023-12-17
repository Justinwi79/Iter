
// *********************************************************************
// * const_iterator default constructor                                *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

#include <initializer_list>
template <typename T> 
cop4530::List<T>::const_iterator::const_iterator() : current{nullptr}
{

}

// *********************************************************************
// * Retrieval operator                                                *
// * Last updated: 6/5/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
const T & cop4530::List<T>::const_iterator::operator*() const 
{
   return retrieve(); 
}

// *********************************************************************
// * Increment and decrement operators for const_iterator class        *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::const_iterator & cop4530::List<T>::  
   const_iterator::operator++() 
{
   current = current->next; 
   return *this; 
}

template <typename T> 
typename cop4530::List<T>::const_iterator cop4530::List<T>::  
   const_iterator::operator++(int) 
{
   List<T>::const_iterator old = *this; 
   ++(*this);
   return old; 
}

template <typename T> 
typename cop4530::List<T>::const_iterator & cop4530::List<T>::  
   const_iterator::operator--() 
{
   current = current->prev; 
   return *this; 
}

template <typename T> 
typename cop4530::List<T>::const_iterator cop4530::List<T>::  
   const_iterator::operator--(int) 
{
   List<T>::const_iterator old = *this; 
   --(*this);
   return old; 
}

// *********************************************************************
// * Comparison operators for const_iterator class                     *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
bool cop4530::List<T>::const_iterator::operator==(const cop4530:: 
   List<T>::const_iterator & rhs) const
   {
      return current == rhs.current;
   }

template <typename T> 
bool cop4530::List<T>::const_iterator::operator!=(const cop4530:: 
   List<T>::const_iterator & rhs) const
   {
      return !(*this == rhs);
   }

// *********************************************************************
// * Const default constructor                                         *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::const_iterator::const_iterator(
      typename List<T>::Node *p) : current{p}
{

}

// *********************************************************************
// * Retrieve element                                                  *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
T & cop4530::List<T>::const_iterator::retrieve() const 
{
   return current->data;
}

// *********************************************************************
// * Iterator constructor.                                             *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::iterator::iterator() 
{

}

// *********************************************************************
// * Retrieval operators                                               *
// * Last updated: 6/5/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
T & cop4530::List<T>::iterator::operator*()  
{
   
   return this->current->data;
}

template <typename T> 
const T & cop4530::List<T>::iterator::operator*() const 
{
   
   return this->retrieve();
}

// *********************************************************************
// * Increment and decrement operators for iterator class              *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator & cop4530::List<T>::  
   iterator::operator++() 
{
   this->current = this->current->next; 
   return *this; 
}

template <typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::  
   iterator::operator++(int) 
{
   List<T>::iterator old = *this; 
   ++(*this);
   return old; 
}

template <typename T> 
typename cop4530::List<T>::iterator & cop4530::List<T>::  
   iterator::operator--() 
{
   this->current = this->current->prev; 
   return *this; 
}

template <typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::  
   iterator::operator--(int) 
{
   List<T>::iterator old = *this; 
   --(*this);
   return old; 
}

// *********************************************************************
// * Constructor.                                                      *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::iterator::iterator(cop4530::List<T>::Node* p) 
    :cop4530::List<T>::const_iterator{p}
{

}

// *********************************************************************
// * Initialize list.                                                  *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// *********************************************************************

template <typename T> 
cop4530::List<T>::List()
{
   init(); 
}

// *********************************************************************
// * Copy constructor.                                                 *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::List(const List & rhs) 
{
   init();
   for(auto & x : rhs) 
      push_back(x);
}

// *********************************************************************
// * Move constructor.                                                 *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::List(List<T> && rhs) 
   : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
{
   rhs.theSize = 0;
   rhs.head = nullptr; 
   rhs.tail = nullptr; 
}

// *********************************************************************
// * Constructor.                                                      *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::List(typename List<T>::const_iterator start, 
   typename List<T>::const_iterator end) 
{
   init();
   for(auto itr = start; itr != end; ++itr)
   {
      push_back(itr.current->data);
   }
}

// *********************************************************************
// * Initializer                                                       *
// * Last updated: 6/11/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// * Same as Copy Constructor                                          *
// *********************************************************************

template <typename T> 
cop4530::List<T>::List(std::initializer_list<T> ilist) 
{
    init(); 
    for(auto & x : ilist) 
      push_back(x);
}


// *********************************************************************
// * Destructor                                                        *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos and office hours            *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T>::~List()
{
   clear();
   delete head; 
   delete tail; 
}

// *********************************************************************
// * Num elements of val.                                              *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T>
cop4530::List<T>::List(int num, const T & val) 
{
   init();
	for(int i = 0; i < num; i++)
    	push_back(val);
}

// *********************************************************************
// * Initializer assignment operator                                   *
// * Last updated: 6/12/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T> & cop4530::List<T>::operator= (std::initializer_list<T> iList)
{
   init(); 
   for(auto & i : iList) 
   {
      push_back(i); 
   }
   return *this; 
    
}

// *********************************************************************
// * Returns size of the list.                                         *
// * Last updated: 6/1/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// *********************************************************************

template <typename T> 
int cop4530::List<T>::size() const 
{
   return theSize; 
}

// *********************************************************************
// * Returns true if the list is empty.                                *
// * Last updated: 6/1/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// *********************************************************************

template <typename T> 
bool cop4530::List<T>::empty() const 
{
   if(theSize==0) 
      return true; 
   else  
      return false; 
}

// *********************************************************************
// * Delete all elements of list.                                      *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::clear()
{
   while(!empty())
      pop_front();
}

// *********************************************************************
// * Reverse list                                                      *
// * Last updated: 6/11/22                                             *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * https://dev.to/educative/tutorial-how-to-reverse-a-linked-list    *
// *********************************************************************

template <typename T> 
void cop4530::List<T>::reverse()
{
   Node *current = head;
   head = tail;
   tail = current;
   Node *cead = head;
   while(cead != NULL)
   {
      current = cead->prev;
      cead->prev = cead->next; 
      cead->next = current; 
      cead = cead->next; 
   }
}

// *********************************************************************
// * Return front of list                                              *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
T & cop4530::List<T>::front() 
{
   return *begin();
}

// *********************************************************************
// * Return front of list (const)                                      *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
const T & cop4530::List<T>::front() const 
{
   return *begin();
}

// *********************************************************************
// * Return back of list                                               *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
T & cop4530::List<T>::back() 
{
   return *--end();
}

// *********************************************************************
// * Return back of list (const)                                       *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
const T & cop4530::List<T>::back() const 
{
   return *--end(); 
}

// *********************************************************************
// * Initialize list.                                                  *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// *********************************************************************

template <typename T> 
void cop4530::List<T>::init() 
{
   theSize = 0; 
   head = new List::Node; 
   tail = new List::Node; 
   head->next = tail; 
   tail->prev = head; 
   head->prev = nullptr; 
   tail->next = nullptr; 
}

// *********************************************************************
// * Copy assignment constructor.                                      *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
const cop4530::List<T> & cop4530::List<T>::operator=(const List<T> & rhs) 
{
   List<T> copy = rhs;
   std::swap(*this, copy); 
   return *this; 
}

// *********************************************************************
// * Move assignment constructor.                                      *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
cop4530::List<T> & cop4530::List<T>::operator=(List<T> && rhs) 
{
   std::swap(theSize, rhs.theSize); 
   std::swap(head, rhs.head); 
   std::swap(tail, rhs.tail); 
   return *this; 
}

// *********************************************************************
// * Insert at beginning                                               *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::push_front(const T & val) 
{
   insert(begin(), val);
}

// *********************************************************************
// * Move beginning                                                    *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::push_front(T && val) 
{
   insert(begin(),std::move(val));
}

// *********************************************************************
// * Insert at end                                                     *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::push_back(const T & val) 
{
   insert(end(), val);
}
// *********************************************************************
// * Move insertion                                                    *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::push_back(T && val) 
{
   insert(end(), std::move(val));
}

// *********************************************************************
// * Delete first element                                              *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::pop_front() 
{
   erase(begin());
}

// *********************************************************************
// * Delete last element                                               *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::pop_back() 
{
   erase(--end());
}

// *********************************************************************
// * Remove elements val                                               *
// * Last updated: 6/6/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::remove(const T & val) 
{
      for(auto itr = begin(); itr != end(); ++itr) 
      {
         if(*itr == val) 
         erase(itr); 
      }
}

// *********************************************************************
// * Predicate remove_if                                               *
// * Last updated: 6/17/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Ryan Faulkenberry office hours                                    *
// * cplusplus.com/reference/list/list/remove_if/                      *
// *********************************************************************

template <typename T> 
template <typename PREDICATE> 
void cop4530::List<T>::remove_if(PREDICATE pred)
{
   iterator itr = begin();
   while(itr != tail) 
   {                       
      if(pred(*itr))
         {
            erase(itr); 
         }
         itr++;      
   }
}

// *********************************************************************
// * Print function                                                    *
// * Last updated: 6/7/22                                              *
// * By: Harold Windham                                                * 
// * References: Ryan Faulkenberry office hours                        *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
void cop4530::List<T>::print(std::ostream& os, char ofc) const 
{
   for(auto itr = begin(); itr != end(); itr++) 
   os << *itr << ofc; 
}

// *********************************************************************
// * Iterator to first element                                         *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::begin() 
{
   return {head->next}; 
}

// *********************************************************************
// * Iterator to first element                                         *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::const_iterator cop4530::List<T>::begin() const 
{
   return {head->next}; 
}

// *********************************************************************
// * Iterator to last element                                          *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::end()
{
   return {tail}; 
} 

// *********************************************************************
// * Iterator to last element                                          *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::const_iterator cop4530::List<T>::end() const 
{
   return {tail}; 
}

// *********************************************************************
// * Insert val ahead of itr                                           *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator 
   cop4530::List<T>::insert(List<T>::iterator itr, const T & val)
{
   Node *p = itr.current; 
   theSize++; 
   return {p->prev = p->prev->next = new Node {val, p->prev, p}};
}

// *********************************************************************
// * Move insert                                                       *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator 
   cop4530::List<T>::insert(List<T>::iterator itr, T && val)
{
   Node *p = itr.current; 
   theSize++; 
   return {p->prev = p->prev->next = new Node {std::move(val), p->prev, p}};
}

// *********************************************************************
// * Erase an element.                                                 *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator itr) 
{
   List<T>::Node * p = itr.current; 
   List<T>::iterator retval(p->next); 
   p->prev->next = p->next; 
   p->next->prev = p->prev; 
   delete p; 
   --theSize; 
   return retval; 
}

// *********************************************************************
// * Erase iterator                                                    *
// * Last updated: 6/4/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
typename cop4530::List<T>::iterator cop4530::List<T>::
   erase(iterator start, iterator end)
{
   for(iterator itr = start; itr != end;)
      itr = erase(itr); 
   return end;
} 

// *********************************************************************
// * Comparison operators                                              *
// * Last updated: 6/12/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
bool operator==(const 
    List<T> & lhs, const List<T> & rhs) 
{   
    return true;
}

template <typename T> 
bool operator!=(const 
    List<T> & lhs, const List<T> & rhs) 
{
    return false;
}

// *********************************************************************
// * os operator overload                                              *
// * Last updated: 6/6/22                                              *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 1*
// *********************************************************************

template <typename T>
std::ostream & operator<<(std::ostream & os, const cop4530::List<T> & l)
{
   l.print(os);
   return os;
}


