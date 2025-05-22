#include <iostream> 
#include <string> 

using namespace std;

class vectorInt {
    
    private:
        
        int* data = NULL;
        int* copyData = NULL;
        int dim = 0;
        
        void createCopy();
        void createMain();
        

    public:
        vectorInt();
        vectorInt(int size);
        
        ~vectorInt();
        
        void add_back(int enteredValue); // push_back()
        void remove_back(); // pop_back()
        void fill_slot(int slot, int enteredValue);
        
        int get_size(); // size()
        void print_screen();
};