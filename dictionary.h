
#include <string>

struct Node
{
public:
   
    std::string word;
    std::string def;
    Node* leftptr;
    Node* rightptr;

    Node(std::string w, std::string d)
    {
        word = w;
        def = d;
        rightptr = nullptr;
        leftptr = nullptr;
    }

};

class dictionary
{
private:

    Node* Root;
    Node* pos;
    std::string def;
    bool recursiveAdd(std::string, std::string, Node*);
    void recursiveClear(Node*);
    void recursiveDisplay(Node*);
    bool recursiveSearch(std::string, Node*);
public:
    dictionary();
    void addWord(std::string, std::string);
    bool searchWord(std::string);
    void displayWord();
    bool isEmpty();
    void resetPos();
    ~dictionary();
};









