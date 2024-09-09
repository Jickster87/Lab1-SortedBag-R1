#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    arrayCapacity = 32;
    mainArray = new TComp[arrayCapacity]();
    sizeBag = 0;
    rel = r;
}

//
//bool lessorEqual(TComp e1, TComp e2){
//    return e1<=e2;
//}


void SortedBag::add(TComp e) {
	//resize
    if (sizeBag == arrayCapacity) {
        arrayCapacity *=2;
        TComp* tempArray = new TComp[arrayCapacity]();
        for (int i = 0; i < sizeBag; i++) {
            tempArray[i] = mainArray[i];
        }
        delete [] mainArray;
        mainArray = tempArray;
    }
    
    //find index in main array and store value;
    int elemPos = 0;
    while (elemPos < sizeBag && rel(mainArray[elemPos], e)) {
        elemPos++;
    }
    //shift from elemPos to end of bag;
    for (int i = sizeBag; i > elemPos; i--) {
        mainArray[i] = mainArray[i-1];
    }
    //insert elem at elemPos
    mainArray[elemPos] = e;
    //and add one more empty slot
    sizeBag++;
}


bool SortedBag::remove(TComp e) {
    // If the bag is empty, return false
      if (sizeBag == 0) {
          return false;
      }
    
	//find elem
    int elemPos = -1;
    for (int i = sizeBag; i >= 0; i--) {
        if (mainArray[i] == e) {
            elemPos = i;
            break;
        }
    }
    // not found get out
    if (elemPos == -1) {
            return false;
        }
    
    //shift all to overwrite
    for (int i = elemPos; i < sizeBag-1; i++) {
        mainArray[i] = mainArray[i+1];
    }
    sizeBag--;
	return true;
}


bool SortedBag::search(TComp elem) const {
    for (int i = 0; i < sizeBag; i++) {
        if (mainArray[i] == elem) {
            return  true;
        }
    }
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
    int counter = 0;
    for (int i = 0; i < sizeBag; i++) {
        if (mainArray[i] == elem) {
            counter++;
        }
    }
	return counter;
}



int SortedBag::size() const {
	return sizeBag;
}


bool SortedBag::isEmpty() const {
	return sizeBag == 0;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    delete [] mainArray;
}
