#include "MySet.h"


 MySet::MySet()
 {
 }

 void MySet::addItem(int item)
 {
	 if (!isItemOf(item))
	 {
		 items.push_back(item);
	 }
 }

 void MySet::removeItem(int item )
 {
	 if (isItemOf(item))
	 {
		 for (int i = 0; i < items.size(); i++)
		 {
			 items.erase(items.begin() + 1);
		 }
	 }
 }

 bool MySet::isItemOf(int item)
 {
	 for (int i = 0; i < items.size(); i++)
	 {
		 if (items.at(i) == item)
		 {
			 return true;
		 }
		 
	 }
	 return false;
 }

 bool MySet:: isSubSetOf(MySet Mysub)
 {
	 for (int i = 0; i < size(); i++)
	 {
		 if (!Mysub.isItemOf(items.at(i)))
		 {
			 return false;
		 }
	 }
	 return true;
 }

 int MySet::size()
 {
	 return items.size();

 }

