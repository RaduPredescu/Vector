#include <iostream>
#include <vector>
template<class T>
class Vector {
    int len;
    int maxSize{1};
    std::unique_ptr<T[]> elem{new T[1]};

    void memChange() {
        if (len == maxSize) {
            std::unique_ptr<T[]> aux{new T[maxSize * 2]};
            for (auto i = 0; i < len; i++)
                aux[i] = elem[i];
            elem = move(aux);
            maxSize *= 2;

        } else if (len < maxSize / 2) {
            std::unique_ptr<T[]> aux{new T[maxSize / 2]};
            for (auto i = 0; i < len; i++)
                aux[i] = elem[i];
            elem = move(aux);
            maxSize /= 2;
        }
    }

public:
    Vector()=default;
    Vector(int length, T const & e)
            : len(length),
              maxSize(length),
              elem(new T[length]) {
        for(int i = 0; i < length; i++) {
            elem[i] = e;
        }
    };

    virtual ~Vector() = default;

    T const &operator[](int index) const {
        if (index < 0 or index >= len)
            throw 69;
        return elem[index];
    }

    int size() const {
        return len;
    }

    void push(T const &e) {
        memChange();
        elem[len] = e;
        ++len;
    }

    void insert(int index, T const &e) {
        memChange();
        for (auto i = len; i > index; --i)
            elem[i] = elem[i - 1];
        elem[index] = e;
        ++len;
    }

    void pop()
    {
        if(len==0)
            throw 0;
        --len;
        memChange();
    }
    void erase(int index)
    {
        for(auto i=index;i<len;++i)
            elem[i]=elem[i+1];
        --len;
        memChange();
    }
    void clear()
    {
        len=0;
        maxSize=1;
        elem.reset(new T[1]);
    }
    void print()
    {
        for(auto i=0;i<len;++i)
            std::cout<<elem[i]<<" ";
        std::cout<<'\n';
    }
};
int main()
{
    int n;
    std::cout<<"Enter no. of elements: ";
    std::cin>>n;
    std::cout<<"Enter "<<n<<" Elements: ";
    Vector<int> v{0,0};
    for(auto i=0;i<n;++i){
        int x;
        std::cin>>x;
        v.push(x);
    }
    while(true)
    {
        std::cout<<"Enter operation: ";
        std::string op;
        std::cin>>op;
        if(op=="SIZE" or op=="size"){
            std::cout<<v.size()<<'\n';
        }
        if(op=="PUSH" or op=="push"){
            int x;
            std::cout<<"Enter number: ";
            std::cin>>x;
            v.push(x);
        }
        if(op=="INSERT" or op=="insert"){
            int ind,x;
            std::cout<<"Enter index and number: ";
            std::cin>>ind>>x;
            v.insert(ind,x);
        }
        if(op=="POP" or op=="pop"){
            v.pop();
        }
        if(op=="ERASE" or op=="erase"){
            int ind;
            std::cout<<"Enter index: ";
            v.erase(ind);
        }
        if(op=="CLEAR" or op=="clear"){
            v.clear();
        }
        if(op=="PRINT" or op=="print"){
            v.print();
        }
        if(op=="EXIT" or op=="exit"){
            std::cout<<"Are you sure you want to?!";
            std::cout<<'\n';
            std::string dec;
            std::cin>>dec;
            if(dec=="yes" or dec=="YES"){
                std::cout<<"Go away";
                exit(0);
            }
            else continue;
        }
    }
    return 0;
}
