#pragma once

template<typename T>
class Node
{
    T data;
    Node<T>* next;

    template <typename T>
    friend class List;

public:
    Node(T data) : data(data), next(nullptr) {}
    ~Node() = default;
};

template<typename T>
class List {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t len = 0;

    template <typename T>
    friend class Node;

    void check4empty() const {
        if (this->empty()) throw std::invalid_argument("List is empty.");
    }

public:
    class Iterator {
        Node<T>* ptr = nullptr;
        template <typename T>
        friend class List;

    public:
        //Constructors
        Iterator() = default;

        Iterator(Node<T>* ptr) {
            this->ptr = ptr;
        }

        //Overloaded operators
        Iterator operator ++() noexcept {
            ptr = ptr->next;
            return *this;
        }
        
        bool operator !=(const Iterator iterator) const noexcept {
            return iterator.ptr != ptr;
        }

        const T& operator *() noexcept {
            return ptr->data;
        }
    };

    //Getters
    size_t size() const noexcept {
        return len;
    }

    //Methods
    Iterator begin() const {
        check4empty();
        return Iterator(head);
    }

    Iterator end() const noexcept {
        return Iterator();
    }

    T front() const {
        check4empty();
        return head->data;
    }

    T back() const {
        check4empty();
        return tail->data;
    }

    bool empty() const noexcept {
        return len == 0;
    }

    void push_back(T const& element) noexcept {
        auto* newel = new Node<T>(element);

        if (empty()) head = tail = newel;
        else
        {
            tail->next = newel;
            tail = tail->next;
        }

        len++;
    }

    void pop_back() {
        check4empty();

        if (head == tail) head = tail = nullptr;

        else {
            Node<T>* new_tail = find(len - 2).ptr;
            new_tail->next = nullptr;
            delete tail;
            tail = new_tail;
        }

        len--;
    }

    void push_front(T const& element) noexcept {
        auto* newel = new Node<T>(element);

        if (empty()) head = tail = newel;
        else
        {
            newel->next = head;
            head = newel;
        }

        len++;
    }

    void pop_front() {
        check4empty();

        if (head == tail) head = tail = nullptr;

        else {
            Node<T>* new_head = head->next;
            delete head;
            head = new_head;
        }

        len--;
    }

    void clear() {
        if (empty()) return;

        while (head != nullptr)
        {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }

        len = 0;
    }

    Iterator insert(Iterator where, T const& element) {
        check4empty();

        auto* new_element = new Node<T>(element);
        new_element->next = where.ptr->next;
        where.ptr->next = new_element;

        len++;
        return Iterator();
    }

    Iterator erase(Iterator where) {
        check4empty();

        Node<T>* temp = where.ptr->next->next;
        delete where.ptr->next;
        where.ptr->next = temp;

        len--;
    	return Iterator();
    }

    Iterator find(size_t const& index) const {
        if (index >= len) throw std::invalid_argument("Index is out of range.");

		Node<T>* result = nullptr;
		size_t i = 0;
        for (auto el = begin(); el != nullptr; ++el)
            if (i++ == index) result = el.ptr;

        return Iterator(result);
    }

    //Overloaded operators
    T operator [] (size_t const& index) const {
        return find(index).ptr->data;
    }

    List<T>& operator = (List const& new_list) {
        if (this == &new_list) return *this;
        clear();

        for (auto el = new_list.begin(); el != nullptr; ++el)
            push_back(el.ptr->data);

        return *this;
    }

    bool operator == (List const& other) const noexcept {
        if (len != other.len) return false;
        
	    for (size_t i = 0; i < other.len; ++i)
            if ((*this)[i] != other[i]) return false;

        return true;
    }

    bool operator != (List const& other) const noexcept {
    	return !(*this == other);
    }
};