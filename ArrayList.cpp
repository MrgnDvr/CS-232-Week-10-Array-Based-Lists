
#include<string>
#include<iostream>
#include"ArrayList.h"
using namespace std;
ArrayList::ArrayList() { //constructor
itemCount = 0;
maxItems = DEFAULT_CAPACITY;
}
bool ArrayList::isEmpty() const {
return itemCount == 0;
}
int ArrayList::getLength() const {
return itemCount;
}
bool ArrayList::insert(int newPosition, const int& newEntry) {
//if the newPosition entered by the user is 1 or greater
//if the newPosition is assigned within the existing list (i.e., newPosition
<= itemCount + 1). So if I have five items in the list and the user want to insert
it in position 10, you can't do that.
//if the itemCount (number of current items in the list) can be fit into the
array list (i.e., itemCount < maxItems)
bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1) &&
(itemCount < maxItems);
if (ableToInsert) {
//make room for new entry by shifting all entries at
//positions >= newPosition towards the end of the array
//(no shift if newPosition == itemCount + 1)
for (int pos = itemCount; pos >= newPosition; pos -= 1) {
items[pos] = items[pos - 1];
}
//insert new entry
items[newPosition - 1] = newEntry;
itemCount += 1; //increase count of items
}
return ableToInsert;
}
bool ArrayList::remove(int position) {
bool ableToRemove = (position >= 0) && (position <= itemCount - 1);
if (ableToRemove) {
//remove entry by shifting all entries after the one at
//position toward the beginning of the array
//(no shift if position == itemCount)
for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex <
itemCount; fromIndex += 1, toIndex += 1) {
items[toIndex] = items[fromIndex];
}
itemCount -= 1;
}
return ableToRemove;
}
void ArrayList::clear() {
itemCount = 0;
}
int ArrayList::getEntry(int position) const {
//decrement position because it represents 1 as the starting point
//but from an array perspective the 1st position starts at index 0
position -= 1;
bool ableToGet = (position >= 0) && (position <= itemCount - 1);
if (ableToGet) {
return items[position];
}
else {
cout << "getEntry() called with an empty list or invalid position" <<
endl;
}
return -1;
}
void ArrayList::setEntry(int position, const int& newEntry) {
bool ableToSet = (position >= 0) && (position <= itemCount - 1);
if (ableToSet) {
items[position] = newEntry;
}
else {
cout << "setEntry() called with an invalid position";
}
}
