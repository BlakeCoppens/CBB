#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <MovieClass.h>
#pragma once

using namespace std;

class MaxHeap {
private:
    vector<Movie> heap;

    //heapify up method
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;

            if (heap[index].getRating() > heap[parentIndex].getRating()) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    //heapify down method
    void heapifyDown(int index) {
        int size = heap.size();

        while (true) {
            int largest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < size && heap[leftChild].getRating() > heap[largest].getRating()) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild].getRating() > heap[largest].getRating()) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:

    void insert(const Movie& movie) {
        heap.push_back(movie);
        heapifyUp(heap.size() - 1);
    }

    //takes out movie with the best rating
    Movie extractMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty.");
        }

        Movie maxMovie = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxMovie;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    //sorts movies by ranking
    vector<Movie> getSortedMovies() {
        vector<Movie> sortedMovies;

        while (!isEmpty()) {
            sortedMovies.push_back(extractMax());
        }

        return sortedMovies;
    }
};
