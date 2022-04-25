/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
	nextVal    int
	hasNextVal bool
	rawIt      *Iterator
}

func Constructor(iter *Iterator) *PeekingIterator {
	pi := &PeekingIterator{
		nextVal:    iter.next(),
		hasNextVal: iter.hasNext(),
		rawIt:      iter,
	}

	return pi
}

func (this *PeekingIterator) hasNext() bool {
	return this.hasNextVal
}

func (this *PeekingIterator) next() int {
	curr := this.nextVal

	this.hasNextVal = this.rawIt.hasNext()

	if this.hasNextVal {
		this.nextVal = this.rawIt.next()
	}

	return curr

}

func (this *PeekingIterator) peek() int {
	return this.nextVal
}

