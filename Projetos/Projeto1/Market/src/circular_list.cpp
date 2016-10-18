#include "circular_list.h"

CircularList::CircularList()
{
    size_ = 0u;
    Performance* perform_sentinel = new Performance(10u, 1);
    MarketBox* box_sentinel = new MarketBox("sentinel", perform_sentinel, 0);
    sentinel = new Node(box_sentinel);
    pointer = new Node();
    pointer->next(sentinel);
}

CircularList::~CircularList()
{
    clear();
    delete pointer;
    delete sentinel;
}

void CircularList::clear()
{
    while (!empty()) {
        pop_front();
    }
}

void CircularList::push_back(MarketBox* data)
{
    insert(data, size());
}

void CircularList::push_front(MarketBox* data)
{
    Node* new_Node = new Node(data);

    if (!empty()) {
        new_Node->next(sentinel->next());
    } else {
        new_Node->next(sentinel);
    }
    sentinel->next(new_Node);
    size_++;
}

void CircularList::insert(MarketBox* data, std::size_t index)
{
    Node *new_Node;
    Node *previous;

    if (index > size() || index < 0) {
        throw std::out_of_range("Invalid_position_Exception");
    } else {
        if (index == 0) {
            push_front(data);
        } else {
            new_Node = new Node(data);
            previous = sentinel->next();
            for (auto i = 0u; i < index -1; i++) {
                previous = previous->next();
            }
            if (index != size()) {
                new_Node->next(previous->next());
            } else {
                new_Node->next(sentinel);
            }
            previous->next(new_Node);
            size_++;
        }
    }
}

MarketBox* CircularList::at(std::size_t index) const
{
    Node *data_ = sentinel->next();

    if (empty()) {
        throw std::out_of_range("Full_list_Exception");
    } else {
        if (index > size() || index < 0) {
            throw std::out_of_range("Invalid_position_Exception");
        } else {
            for (auto i = 0u; i < index; i++) {
                data_ = data_->next();
            }
            return data_->data();
        }
    }
}

MarketBox* CircularList::pop(std::size_t index)
{
    Node* previous;
    Node* to_eliminate;
    MarketBox* to_back;

    if (index > size()-1 || index < 0) {
        throw std::out_of_range("Invalid_position_Exception");
    } else {
        if (index == 0) {
            return pop_front();
        } else {
            previous = sentinel->next();
            for (auto i = 0u; i < index -1; i++) {
                previous = previous->next();
            }
            to_eliminate = previous->next();
            to_back = to_eliminate->data();
            previous->next(to_eliminate->next());
            size_--;
            delete to_eliminate;

            return to_back;
        }
    }
}

MarketBox* CircularList::pop_back()
{
    if (empty()) {
        throw std::out_of_range("Empty_list_Exception");
    } else {
        return pop(size()-1);
    }
}

MarketBox* CircularList::pop_front()
{
    Node *quit;
    MarketBox* to_back;

    if (empty()) {
        throw std::out_of_range("Empty_list_Exception");
    } else {
        quit = sentinel->next();
        to_back = quit->data();
        sentinel->next(quit->next());
        size_--;
        delete quit;

        return to_back;
    }
}

bool CircularList::empty() const
{
    return size_ == 0;
}

std::size_t CircularList::size() const
{
    return size_;
}

void CircularList::passes_forward()
{
    pointer->next(pointer->next()->next());
}

MarketBox* CircularList::get_data_pointer_element()
{
    return pointer->next()->data();
}
