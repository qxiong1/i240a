#ifndef	PRIORITY_QUEUE_HH
#define	PRIORITY_QUEUE_HH

#include <iostream>

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "job.hh"
using namespace std;


class MaxHeap {
public:
  MaxHeap();
  void enqueue(Job value);
  Job dequeue();
  int size();

private:
  vector<Job> heap; 
  int nElements; 

  void siftDown(int pos);
  void swap(int pos1, int pos2);
  bool isLeaf(int pos) const;
  int leftChild(int pos);
  int rightChild(int pos);
  int parent(int pos);
  friend std::ostream& operator<<(std::ostream& out, const MaxHeap& heap);
};



class MinHeap {
public:
  MinHeap();
  void enqueue(Job value);
  Job dequeue();
  int size();

private:
  vector<Job> heap; 
  int nElements;

  void siftDown(int pos);
  void swap(int pos1, int pos2);
  bool isLeaf(int pos) const;
  int leftChild(int pos);
  int rightChild(int pos);
  int parent(int pos);
  friend std::ostream& operator<<(std::ostream& out, const MinHeap& heap);
};

#endif
