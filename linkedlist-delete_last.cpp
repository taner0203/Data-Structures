#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int size;

public:
    // Default constructor
    String() {
        size = 0;
        data = new char[1];
        data[0] = '\0';
    }

    // Copy constructor
    String(const String& other) {
        size = other.size;
        data = new char[size + 1];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        data[size] = '\0';
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
            data[size] = '\0';
        }
        return *this;
    }

    // Member function: append()
    void append(const char* str) {
        int len = strlen(str);
        char* temp = new char[size + len + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        for (int i = 0; i < len; i++) {
            temp[size + i] = str[i];
        }
        temp[size + len] = '\0';
        delete[] data;
        data = temp;
        size += len;
    }

    // Member function: concat()
    String concat(const char* str) {
        String result(*this);
        result.append(str);
        return result;
    }

    // Getter for size
    int getSize() const {
        return size;
    }

    // Getter for data
    const char* getData() const {
        return data;
    }
};

int main() {
    String str1;
    std::cout << "str1: " << str1.getData() << std::endl;

    String str2 = "Hello";
    std::cout << "str2: " << str2.getData() << std::endl;

    String str3(str2);
    std::cout << "str3: " << str3.getData() << std::endl;

    String str4;
    str4 = str3;
    std::cout << "str4: " << str4.getData() << std::endl;

    str1.append(" World!");
    std::cout << "str1 after append: " << str1.getData() << std::endl;

    String str5 = str2.concat(" World!");
    std::cout << "str5: " << str5.getData() << std::endl;

    return 0;
}
