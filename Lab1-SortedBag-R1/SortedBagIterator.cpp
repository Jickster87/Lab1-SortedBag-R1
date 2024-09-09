#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    currentPosition = 0;
}

TComp SortedBagIterator::getCurrent() {
    if (currentPosition >= bag.sizeBag)
    {
        throw exception();
    }
    return bag.mainArray[currentPosition];
}

bool SortedBagIterator::valid() {
	return currentPosition < bag.sizeBag;
}

void SortedBagIterator::next() {
    if (currentPosition  >= bag.sizeBag)
        {
            throw exception();
        }
        currentPosition++;
}

void SortedBagIterator::first() {
    currentPosition = 0;
}

