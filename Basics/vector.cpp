#include <iostream>
#include <vector>
using namespace std;

/*
syntax:
vector<object_type> variable_name;

example:
vector<int> v1;
vector<char> v2;
vector<string> v3;

Most used funtions in vector
begin()   itr = v1.begin()
end()    itr = v2.end()
push_back()   v1.push_back(x);
insert()  insert element at specified position
auto it = v1.begin();
v1.insert(it, x);

erase()  delete a specific element
pop_back()
front()
back()
clear() delete all the elements
empty() check if the vector is empty
size() return size
*/

int main() {
  vector < int > v;

  for (int i = 0; i < 10; i++) {
    v.push_back(i); //inserting elements in the vector
  }

  cout << "the elements in the vector: ";
  for (auto it = v.begin(); it != v.end(); it++)
    cout << * it << " ";

  cout << "\nThe front element of the vector: " << v.front();
  cout << "\nThe last element of the vector: " << v.back();
  cout << "\nThe size of the vector: " << v.size();
  cout << "\nDeleting element from the end: " << v[v.size() - 1];
  v.pop_back();

  cout << "\nPrinting the vector after removing the last element:" << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  cout << "\nInserting 5 at the beginning:" << endl;
  v.insert(v.begin(), 5);
  cout << "The first element is: " << v[0] << endl;
  cout << "Erasing the first element" << endl;
  v.erase(v.begin());
  cout << "Now the first element is: " << v[0] << endl;

  if (v.empty())
    cout << "\nvector is empty";
  else
    cout << "\nvector is not empty" << endl;

  v.clear();
  cout << "Size of the vector after clearing the vector: " << v.size();

}