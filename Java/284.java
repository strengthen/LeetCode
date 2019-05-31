__________________________________________________________________________________________________
sample 45 ms submission
class PeekingIterator implements Iterator<Integer> {
		
    Integer temp;
    Iterator<Integer> iterator;
    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        this.iterator = iterator;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        if (temp == null) {
            temp = iterator.next();
        }

        return temp;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        if (temp == null) {
            return iterator.next();
        } else {
            Integer result = temp;
            temp = null;
            return result;
        }
    }

    @Override
    public boolean hasNext() {
        if (temp != null) {
            return true;
        }

        return iterator.hasNext();
    }
}
__________________________________________________________________________________________________
sample 34216 kb submission
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    
    boolean peeking;
    int peeked;
    Iterator<Integer> iterator;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    peeking = false;
        this.iterator = iterator;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if (peeking) return peeked;
        else {
            peeking = true;
            peeked = iterator.next();
            return peeked;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (peeking) {
            peeking = false;
            return peeked;
        } else {
            return iterator.next();
        }
	}

	@Override
	public boolean hasNext() {
	    if (peeking) {
            return true;
        } else {
            return iterator.hasNext();
        }
	}
}
__________________________________________________________________________________________________
