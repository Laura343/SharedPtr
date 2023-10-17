template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr = nullptr) : data(ptr), refCount(new std::size_t(1)) {}

    SharedPtr(const SharedPtr& other) : data(other.data), refCount(other.refCount) {
        (*refCount)++;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            decrementRefCount();
            data = other.data;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    ~SharedPtr() {
        decrementRefCount();
    }

    T& operator*() const {
        return *data;
    }

    T* operator->() const {
        return data;
    }

    T* get() const {
        return data;
    }

    bool isNull() const {
        return data == nullptr;
    }

private:
    T* data;
    std::size_t* refCount;

    void decrementRefCount() {
        (*refCount)--;
        if (*refCount == 0) {
            delete data;
            delete refCount;
        }
    }
};
