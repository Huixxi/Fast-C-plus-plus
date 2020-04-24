class String {
    char* str;

public:
    String() : str(new char[1]) { *str = '\0'; }
    
    String(String&& movestr) : str(movestr.str) {
        movestr.str = nullptr;
    }
    
    String(const char* initstr) {
        if(initstr != nullptr) {
            str = new char[strlen(initstr) + 1];
            strcpy(str, initstr);
        }
    }
    
    String(const String& Copystr) {  // Copy Constructor
        if(Copytstr.str != nullptr) {
            str = new char[strlen(Copystr.str) + 1];
            strcpy(str, Copystr.str);
        }
        else
            str = nullptr;
    }
    
    String& operator= (const String& Copystr) {
        if(this != &Copystr) {
            swap(Copystr);
        }
        return *this;   
    }
    
    const char* c_str() const {
        return str;
    }
    
    void swap(String& rhs) {
        std::swap(str, rhs.str);
    }
    
    virutal ~String() { delete[] str}
}
