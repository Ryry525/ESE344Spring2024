#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <list>

using namespace std;

template <typename Object>
class List
{
private:
    // The basic singly linked list node.
    // Nested inside of List, can be public
    // because the Node is itself private
    struct Node
    {
        Object  data;
        Node* next;

        Node(const Object& d = Object{ }, Node* n = nullptr)
            : data{ d }, next{ n } { }

        Node(Object&& d, Node* n = nullptr)
            : data{ std::move(d) }, next{ n } { }
    };

public:
    class const_iterator
    {
    public:

        // Public constructor for const_iterator.
        const_iterator() : theList{ init() }, current{ nullptr }
        { }

        // Return the object stored at the current position.
        // For const_iterator, this is an accessor with a
        // const reference return type.
        const Object& operator* () const
        {
            return retrieve();
        }

        const_iterator& operator++ ()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++ (int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator== (const const_iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!= (const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }

        const_iterator& operator-- ()
		{
        Node* ptr = this->theList->head->next;
        while (ptr->next != this->current) { 
            // check for other boundary conditions here
            ptr = ptr->next;
        }
        this->current = ptr;
        return *this;
        }

        const_iterator operator-- (int)
        {
            const_iterator old = *this;
            --(*this);
            return old;
        }

    protected:
        const List<Object>* theList;
        Node* current;
        Node* head;

        // Protected helper in const_iterator that returns the object
        // stored at the current position. Can be called by all
        // three versions of operator* without any type conversions.
        Object& retrieve() const
        {
            return current->data;
        }

        // Protected constructor for const_iterator.
        // Expects a pointer that represents the current position.
        const_iterator(const List<Object>& lst, Node* p) : theList{ &lst }, current{ p }, head{ lst.head } {}

        friend class List<Object>;
    };

    class iterator : public const_iterator
    {
    public:

        // Public constructor for iterator.
        // Calls the base-class constructor.
        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.
        iterator()
        { }

        Object& operator* ()
        {
            return const_iterator::retrieve();
        }

        // Return the object stored at the current position.
        // For iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        const Object& operator* () const
        {
            return const_iterator::operator*();
        }

        iterator& operator++ ()
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++ (int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }
        
        iterator& operator-- ()
        {
			this->current = this->theList->find_previous(this->current);
			return *this;
		}
        iterator operator-- (int)
        {
			iterator old = *this;
			--(*this);
			return old;
		}

    protected:
        // Protected constructor for iterator.
        // Expects the current position.
        iterator(List<Object>& lst, Node* p) : const_iterator(lst, p) {}

        friend class List<Object>;
    };

public:
    List()
    {
        init();
    }

    ~List()
    {
        clear();
        delete head;
    }

    List(const List& rhs)
    {
        init();
        for (auto& x : rhs)
            push_back(x);
    }

    List& operator= (const List& rhs)
    {
        if(this != &rhs)
		{
			List copy = rhs;
			std::swap(*this, copy);
		}
        return *this;
    }

    List(List&& rhs)
        : theSize{ rhs.theSize }, head{ rhs.head }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
    }

    List& operator= (List&& rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);

        return *this;
    }

    Node* find_previous(Node* current) const
    {
        Node* prev = nullptr;
        Node* temp = head;
        while (temp != current)
        {
            prev = temp;
            temp = temp->next;
        }
        return prev;
    }

    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin()
    {
        return iterator(*this, head->next);
    }

    const_iterator begin() const
    {
        const_iterator itr{ *this, head };   // const_iterator itr{ head, head };   
        return ++itr;
    }

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end()
    {
        return iterator(*this,nullptr);
    }

    const_iterator end() const
    {
        return const_iterator(*this, nullptr);
    }

    // Return number of elements currently in the list.
    int size() const
    {
        return theSize;
    }

    // Return true if the list is empty, false otherwise.
    bool empty() const
    {
        return size() == 0;
    }

    void clear()
    {
        while (!empty())
            pop_front();
        // Delete the head node after clearing the list
    }

    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic queue operations.
    Object& front()
    {
        return *begin();
    }

    const Object& front() const
    {
        return *begin();
    }

    void push_front(const Object& x)
    {
        insert(begin(), x);
    }

    void push_back(const Object& x)
    {
        insert(end(), x);
    }

    void push_front(Object&& x)
    {
        insert(begin(), std::move(x));
    }

    void push_back(Object&& x)
    {
        insert(end(), std::move(x));
    }

    void pop_front()
    {
        erase(begin());
    }

    void pop_back()
	{
		erase(--end());
	}

    // Insert x before itr.
    iterator insert(iterator itr, const Object& x)
    {
		Node* p = itr.current;
		++theSize;
        p->next = new Node{ x, p->next };
        return iterator(*this,p->next);
	}

    // Insert x before itr.
    iterator insert(iterator itr, Object&& x)
    {
        Node* p = itr.current;
        ++theSize;
        p->next = new Node{std::move(x), p->next};
        return iterator(*this, p->next);
    }

    // Erase item at itr.
    iterator erase(iterator itr)
    {
        Node* p = itr.current;
        iterator retVal{*this, p->next };
        p->next = p->next->next;
        delete p;
        --theSize;

        return retVal;
    }
private:
    int theSize;
    Node* head;

    void init()
    {
        theSize = 0;
        head = new Node;
    }
};  


class Square
{
public:
    explicit Square(int s = 0) : side{ s }
    { }

    void setSide(int s = 1)
    {
        side = s;
    }
    int getSide() const
    {
        return side;
    }
    int getArea() const
    {
        return side * side;
    }
    int getPerimeter() const
    {
        return 4 * side;
    }

    void print(ostream& out = cout) const
    {
        out << "(square " << getSide() << ")" << endl;
    }
    bool operator< (const Square& rhs) const
    {
        return getSide() < rhs.getSide();
    }

private:
    int side;
};

// Define an output operator for Square
ostream& operator<< (ostream& out, const Square& rhs)
{
    rhs.print(out);
    return out;
}



/**
* Return the maximum item in array a.
* Assumes a.size( ) > 0.
* Comparable objects must provide operator< and operator=
*/
template <typename Comparable>
const Comparable& findMax(const vector<Comparable>& a)
{
    int maxIndex = 0;

    for (int i = 1; i < a.size(); ++i)
        if (a[maxIndex] < a[i])
            maxIndex = i;

    return a[maxIndex];
}

#endif
