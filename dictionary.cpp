#include "dictionary.h"
#include <iostream>


dictionary::dictionary()
{
    Root = nullptr;
    pos = nullptr;
}

void dictionary::addWord(std::string w, std::string d)
{
    resetPos();
    if (isEmpty())
    {
        Root = new Node(w, d);
        pos = Root;
        resetPos();
        
    }
    else
        recursiveAdd(w, d, Root);
}

bool dictionary::searchWord(std::string w)
{
    resetPos();
    return recursiveSearch(w, pos);
}

void dictionary::displayWord()
{
    if (isEmpty())
    {
        std::cout << "there is nothing" << std::endl;
    }
    else
    {
        recursiveDisplay(Root);
        
    }
}

void dictionary::recursiveDisplay(Node* root)
{
   
    if (root->leftptr != nullptr)
    {
        recursiveDisplay(root->leftptr);
        std::cout << " " << std::endl;
    }
    std::cout << root->word;

    std::cout << " " << root->def << std::endl;

    if (root->rightptr != nullptr)
    {
        recursiveDisplay(root->rightptr);
        
    }
}

bool dictionary::recursiveSearch(std::string w, Node* root)
{
    if (root == nullptr)
        return false;
    if (root->word == w)
    {
        pos = root;
        std::cout << root->def << std::endl;
        return true;
    }
    if (w < root->word)
        recursiveSearch(w, root->leftptr);
    else
        recursiveSearch(w, root->rightptr);
       
    
    
    return false;
}

bool dictionary::isEmpty()
{
    if (Root == nullptr)
        return true;

    return false;
}

void dictionary::resetPos()
{
    pos = Root;
}


bool dictionary::recursiveAdd(std::string w, std::string d,Node* root)
{
    if (w < root->word)
    {
        if (root->leftptr == nullptr)
        {
            root->leftptr = new Node(w, d);
        }
        else
        {
            recursiveAdd(w, d, root->leftptr);
        }
    }
    else
    {
        if (root->rightptr == nullptr)
        {
            root->rightptr = new Node(w, d);
        }
        else
        {
            recursiveAdd(w, d, root->rightptr);
        }
    }
    return false;
}

void dictionary::recursiveClear(Node* root)
{
    if (root->leftptr != nullptr)
        recursiveClear(root->leftptr);

    if (root->rightptr != nullptr)
        recursiveClear(root->rightptr);

    delete root;

}

dictionary::~dictionary()
{
    if (isEmpty())
        recursiveClear(Root);
}









