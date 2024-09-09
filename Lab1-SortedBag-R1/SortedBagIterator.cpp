#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    currentPosition = 0;
}

TComp SortedBagIterator::getCurrent() {
	return currentPosition;
}

bool SortedBagIterator::valid() {
	return currentPosition < bag.sizeBag;
}

void SortedBagIterator::next() {
    if (!valid()) {
        throw exception();
    }
    currentPosition++;
}

void SortedBagIterator::first() {
    currentPosition = 0;
}

