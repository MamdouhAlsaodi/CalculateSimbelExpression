#pragma once
#include "clsDblLinkedList.h"

template <typename T>
class clsStack {
private:
    clsDblLinkedList<T> _list;
public:
    void push(T item) {
        _list.InsertAtBeginning(item);
    }

    void pop() {
        if (!isEmpty())
            _list.DeleteFirstNode();
    }

    T top() {
        return  _list.GetItem(0);
    }

    bool isEmpty() {
        return _list.IsEmpty();
    }

    int size() {
        return _list.Size();
    }

    void clear() {
        _list.Clear();
    }
};
