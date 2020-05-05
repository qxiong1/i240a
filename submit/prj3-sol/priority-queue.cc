#include <iostream>

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>

#include "priority-queue.hh"

	MaxHeap::MaxHeap(){
		nElements = 0;
	}

  void MaxHeap::enqueue(Job value) {
    heap.push_back(value); //add value at end
    nElements++;
    for (int pos = nElements - 1; //pos of added value
	 (pos != 0 && heap[pos].priority0 > heap[parent(pos)].priority0)
	 || (heap[pos].priority0 == heap[parent(pos)].priority0 && heap[pos].id > heap[parent(pos)].id);
	 pos = parent(pos)) {
      swap(pos, parent(pos));
    }
  }

  Job MaxHeap::dequeue() {
    assert(nElements > 0 && "heap is empty");
    Job value = heap[0];
    heap[0] = heap[nElements - 1]; //put last element at root
    --nElements; //delete it
    heap.pop_back();
    if (nElements > 0) siftDown(0);  //move it to correct position
    return value;
  }

  int MaxHeap::size() { return nElements; }

  void MaxHeap::siftDown(int pos) {
    assert(0 <= pos && pos < nElements);
    while (!isLeaf(pos)) {
      int leftKidPos = leftChild(pos);
      //there must be a left kid since pos is not a leaf
      assert(0 <= leftKidPos && leftKidPos < nElements);
      int rightKidPos = rightChild(pos);
      int maxKidPos =
	(rightKidPos >= 0 && heap[rightKidPos].priority0 > heap[leftKidPos].priority0)
	? rightKidPos
	: (heap[rightKidPos].priority0 < heap[leftKidPos].priority0) 
	? leftKidPos 
	: (heap[rightKidPos].id > heap[leftKidPos].id)
	? rightKidPos 
	: leftKidPos;
      if (heap[pos].priority0 >= heap[maxKidPos].priority0) return;
      swap(pos, maxKidPos);
      pos = maxKidPos;
    }
  }

  void MaxHeap::swap(int pos1, int pos2) {
    assert(0 <= pos1 && pos1 < nElements);
    assert(0 <= pos2 && pos2 < nElements);
    
    Job tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
  }

  //tree accessors
  bool MaxHeap::isLeaf(int pos) const {
    return (pos >= nElements/2) && (pos < nElements);
  }

  int MaxHeap::leftChild(int pos) {
    return (2*pos + 1 < nElements) ? 2*pos + 1 : -1;
  }

  int MaxHeap::rightChild(int pos) {
    return (2*pos + 2 < nElements) ? 2*pos + 2 : -1;
  }

  int MaxHeap::parent(int pos) {
    return (pos > 0) ? (pos - 1)/2 : -1;
  }











	MinHeap::MinHeap(){
		nElements = 0;
	}

  void MinHeap::enqueue(Job value) {
    heap.push_back(value); //add value at end
    nElements++;
    for (int pos = nElements - 1; //pos of added value
	 (pos != 0 && heap[pos].priority1 < heap[parent(pos)].priority1)
 	 || (heap[pos].priority1 == heap[parent(pos)].priority1 && heap[pos].id < heap[parent(pos)].id);
	 pos = parent(pos)) {
      swap(pos, parent(pos));
    }
  }

  Job MinHeap::dequeue() {
    assert(nElements > 0 && "heap is empty");
    Job value = heap[0];
    heap[0] = heap[nElements - 1]; //put last element at root
    --nElements; //delete it
    heap.pop_back();
    if (nElements > 0) siftDown(0);  //move it to correct position
    return value;
  }

  int MinHeap::size() { return nElements; }

  void MinHeap::siftDown(int pos) {
    assert(0 <= pos && pos < nElements);
    while (!isLeaf(pos)) {
      int leftKidPos = leftChild(pos);
      //there must be a left kid since pos is not a leaf
      assert(0 <= leftKidPos && leftKidPos < nElements);
      int rightKidPos = rightChild(pos);

      int minKidPos =
	(rightKidPos >= 0 && heap[rightKidPos].priority1 < heap[leftKidPos].priority1)
	? rightKidPos
	: (heap[rightKidPos].priority1 > heap[leftKidPos].priority1) 
	? leftKidPos 
	: (heap[rightKidPos].id < heap[leftKidPos].id)
	? rightKidPos 
	: leftKidPos;
      if (heap[pos].priority1 <= heap[minKidPos].priority1) return;
      swap(pos, minKidPos);
      pos = minKidPos;
    }
  }

  void MinHeap::swap(int pos1, int pos2) {
    assert(0 <= pos1 && pos1 < nElements);
    assert(0 <= pos2 && pos2 < nElements);
    Job tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
  }

  //tree accessors
  bool MinHeap::isLeaf(int pos) const {
    return (pos >= nElements/2) && (pos < nElements);
  }

  int MinHeap::leftChild(int pos) {
    return (2*pos + 1 < nElements) ? 2*pos + 1 : -1;
  }

  int MinHeap::rightChild(int pos) {
    return (2*pos + 2 < nElements) ? 2*pos + 2 : -1;
  }

  int MinHeap::parent(int pos) {
    return (pos > 0) ? (pos - 1)/2 : -1;
  }



std::ostream&
operator<<(std::ostream& out, const MaxHeap& heap) {
  out << "[ ";
  for (int i = 0; i < heap.nElements; i++) {
    out << heap.heap[i] << " ";
  }
  out << "]";
  return out;
}

std::ostream&
operator<<(std::ostream& out, const MinHeap& heap) {
  out << "[ ";
  for (int i = 0; i < heap.nElements; i++) {
    out << heap.heap[i] << " ";
  }
  out << "]";
  return out;
}


/***************MAX HEAP
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " INT... [+INT|-]" << std::endl;
    exit(1);							       
  }
  std::ostream& out = std::cout;
  int array[16];
  int argvIndex;
  int nElements = 0;
  for (argvIndex = 1; argvIndex < argc; argvIndex++) {
    const char* arg = argv[argvIndex];
    if (!isdigit(arg[0])) break;
    array[nElements++] = atoi(arg);
  }
  MaxHeap heap;
  out << "initial heap: " << heap << std::endl;
  for (; argvIndex < argc; ++argvIndex) {
    const char* arg = argv[argvIndex];
    if (arg[0] == '+') {
      int value = atoi(&arg[1]);
      heap.enqueue(value);
      out << "enqueued " << value << ": " << heap << std::endl;
    }
    else {
      assert(strcmp(arg, "-") == 0 && "invalid argv[] value");
      int value = heap.dequeue();
      out << "dequeued " << value << ": " << heap << std::endl;
    }
  }
}


//*/
/***************MIN HEAP
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " INT... [+INT|-]" << std::endl;
    exit(1);							       
  }
  std::ostream& out = std::cout;
  int array[16];
  int argvIndex;
  int nElements = 0;
  for (argvIndex = 1; argvIndex < argc; argvIndex++) {
    const char* arg = argv[argvIndex];
    if (!isdigit(arg[0])) break;
    array[nElements++] = atoi(arg);
  }
  MinHeap heap;
  out << "initial heap: " << heap << std::endl;
  for (; argvIndex < argc; ++argvIndex) {
    const char* arg = argv[argvIndex];
    if (arg[0] == '+') {
      int value = atoi(&arg[1]);
      heap.enqueue(value);
      out << "enqueued " << value << ": " << heap << std::endl;
    }
    else {
      assert(strcmp(arg, "-") == 0 && "invalid argv[] value");
      int value = heap.dequeue();
      out << "dequeued " << value << ": " << heap << std::endl;
    }
  }
}
//*/