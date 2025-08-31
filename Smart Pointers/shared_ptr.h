template <typename T>
class Shared_ptr
{
    struct block
    {
        T *ptr;
        int count;
        block(T *p) : count(1), ptr(p) {}
    };
    block *ctrl;

public:
    Shared_ptr(T *ptr = nullptr)
    {
        ctrl = new block(ptr);
    }
    Shared_ptr(const Shared_ptr &other)
    {
        ctrl = other.ctrl;
        if (ctrl)
        {
            ctrl->count++;
        }
    }

    Shared_ptr &operator=(const Shared_ptr &other)
    {
        if (this != &other)
        {
            this->~Shared_ptr();

            ctrl = other.ctrl;
            if (ctrl)
            {
                ctrl->count++;
            }
        }
        return *this;
    }

    Shared_ptr(Shared_ptr &&other)
    {
        ctrl = other.ctrl;
        other.ctrl = nullptr;
    }

    Shared_ptr &operator=(Shared_ptr &&other)
    {
        if (this != &other)
        {
            this->~Shared_ptr();
            ctrl = other.ctrl;
            other.ctrl = nullptr;
        }
        return *this;
    }

    T *operator->()
    {
        return (ctrl ? *ctrl->ptr : 0);
    }

    int count()
    {
        return (ctrl ? ctrl->count : 0);
    }
    T *get()
    {
        return (ctrl ? ctrl->ptr : 0);
    }
    ~Shared_ptr()
    {
        if (ctrl)
        {
            // cout << "Decresing\n";
            ctrl->count--;
            if (ctrl->count == 0)
            {
                // cout << "Deleting\n";
                delete ctrl->ptr;
                delete ctrl;
            }
        }
    }
};

template <typename T, typename arg>
Shared_ptr<T> make_shareptr(arg value)
{
    return Shared_ptr<T>(new T(value));
}
