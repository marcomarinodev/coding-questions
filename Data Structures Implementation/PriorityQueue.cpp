#include <iostream>
#include <cmath>

using namespace std;

template <class T>

class PriorityQueue {
    T *queue;
    int dim;
    int max_size;
    
private:
    
    void swap(int pos1, int pos2) {
        T tmp = queue[pos1];
        queue[pos1] = queue[pos2];
        queue[pos2] = tmp;
    }
    
    // O(log n) because of traversing in depth the tree that has height O(log n)
    void bubble_up(int position) {
        
        // if the element we want to bubble up is the root, then return
        if (pq_parent(position) == -1) return;
        
        if (queue[position] > queue[pq_parent(position)]) {
            // the element at position has the higher priority than
            // his father
            swap(pq_parent(position), position);
            // it is not said that the bubble upped element is in the
            // right position, so we recall recursively the bubble function
            // in the parent position (where now there is the element swapped
            // before)
            bubble_up(pq_parent(position));
        }
    }
    
public:
    
    PriorityQueue(int size) {
        dim = 0;
        max_size = size;
        queue = (T *)malloc(sizeof(T) * (max_size + 1));
    }
    
    // The initial heap construction from an array has O(n logn) time complexity, where
    // O(log n) is the cost of bubbling up, and this operation is repeated for each
    // element of the array
    PriorityQueue(T *arr, int size) {
        dim = 0;
        max_size = size;
        queue = (T *)malloc(sizeof(T) * (max_size + 1));
        
        
        for (int i = 0; i < size; i++) {
            pq_insert(arr[i]);
        }
    }
    
    ~PriorityQueue() {
        free(queue);
    }
    
    int pq_parent(int position) {
        if (position == 0) return -1;
        
        // That's because I'm starting with 0
        return (floor((position + 1) / 2) - 1);
        
    }
    
    int pq_left_child(int position) {
        return (2 * position) + 1;
    }
    
    int pq_right_child(int position) {
        return pq_left_child(position) + 1;
    }
    
    void pq_insert (T x) {
        if (dim >= max_size)
            printf("Warning: priority queue overflow insert\n");
        else {
            // increase dim
            dim++;
            // insert as leaf
            queue[dim] = x;
            // call bubble_u to insert the new key at the right position
            // based on the priority (T value)
            bubble_up(dim);
        }
    }
    
    void heapify(int position) {
        int highest = position;
        int leftRootNode = (2*position) + 1;
        int rightRootNode = (2*position) + 2;
        
        // case when the left root node has the highest priority
        if (leftRootNode < dim && queue[leftRootNode] > queue[highest])
            highest = leftRootNode;
        
        // case when the roght root node has the highest priority
        if (rightRootNode < dim && queue[rightRootNode] > queue[highest])
            highest = rightRootNode;
        
        // case when the current root has not the highest priority
        if (highest != position) {
            // swap with the node with highest priority
            swap(position, highest);
            
            // recall heapify on the moved root, that now is in "highest" position
            // (bubble down) in order to mantain the heap invariant
            heapify(highest);
        }
    }
    
    T extract() {
        T highestPriority;
        
        if (dim <= 0) {
            printf("Warning: empty priority queue\n");
            return T();
        }
        
        // the element with highest priority is the root
        highestPriority = queue[0];
        // the last leaf will be temporary the root
        queue[0] = queue[dim];
        // decrease heap size
        dim--;
        // after that, we have to heapify the heap
        heapify(0);
        
        return highestPriority;
    }
    
    void pq_print () {
        cout << "Printing the priority queue..." << endl;
        for (int i = 0; i < dim; i++) {
            cout << " - " << queue[i] << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    PriorityQueue<int> *pq;
    
    int arr[] = {9, 3, 1, 2, 10, 4, 5};
    int arr_dim = sizeof(arr) / sizeof(arr[0]);
    
    pq = new PriorityQueue<int>(arr, arr_dim);
    
    cout << pq->extract() << endl;
    cout << pq->extract() << endl;
    
    pq->pq_print();
    
    delete pq;
    
    return 0;
}

