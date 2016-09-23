#ifndef S_LINKED_LIST_HPP
#define S_LINKED_LIST_HPP


template<class ItemType>
class Node {
  private:
    ItemType elem;
    Node<ItemType>* next;
    friend class SLinkedList<ItemType>;
};



template <class ItemType>
class SLinkedList {
  public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const ItemType& front() const;
    void addFront(const ItemType& item);
    void removeFront();
  private:
    Node<ItemType>* head;
};

SLinkedList<ItemType>::SLinkedList()                                                      
  : head(NULL) { }                                                                        
                                                                                                 
template<class ItemType>                                                                  
bool SLinkedList<ItemType>::empty() const                                                 
{                                                                                         
  return head == NULL;                                                                    
}                                                                                         
                                                                                                           
template<class ItemType>                                                                  
const ItemType& SLinkedList<ItemType>::front() const                                      
{                                                                                         
  return head->elem;                                                                      
}                                                                                         

template<class ItemType>                                                                  
SLinkedList<ItemType>::~SLinkedList()                                                     
{                                                                                         
  while ( !empty() )                                                                      
    removeFront();                                                                        
}                                                                                         

template<class ItemType>                                                                  
void SLinkedList<ItemType>::addFront(const ItemType& item)                                
{                                                                                         
  Node<ItemType>* temp = new Node<ItemType>;                                              
  temp->elem = item;                                                                      
  temp->next = head;                                                                      
  head = temp;                                                                            
}                              

template<class ItemType>
void SLinkedList<ItemType>::removeFront()
{
  Node<ItemType>* old;
  head = old->next;
  delete old;
}

#endif
