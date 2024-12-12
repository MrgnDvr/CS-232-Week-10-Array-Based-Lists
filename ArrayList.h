
#ifndef _ARRAY_LIST
#define _ARRAY_LIST
#include"ListInterface.h"
class ArrayList : public ListInterface {
private:
static const int DEFAULT_CAPACITY = 100;
int items[DEFAULT_CAPACITY]; //array of list items
int itemCount; //current count of list items
int maxItems; //maximum capacity of the list
public:
ArrayList(); //default
bool isEmpty() const;
int getLength() const;
bool insert(int newPosition, const int& newEntry);
bool remove(int position);
void clear();
int getEntry(int position) const;
void setEntry(int position, const int& newEntry);
};
#endif // !_ARRAY_LIST
