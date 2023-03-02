#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    const int INF = 1e6;

private:
    vector<int> heap;

    void sift_up(int index)
    {
        int parent = (index - 1) / 2;
        while ((index > 0) && heap[index] < heap[parent])
        {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void sift_down(int index = 0, int is_pop = true)
    {
        if (is_pop)
        {
            swap(heap[index], heap[heap.size() - 1]);
            heap.pop_back();
        }

        int child = 2 * index + 1;
        while (child < heap.size())
        {
            if ((child + 1 < heap.size()) && heap[child + 1] < heap[child])
                child++;

            if (heap[child] < heap[index])
            {
                swap(heap[index], heap[child]);
                index = child;
                child = 2 * index + 1;
            }
            else
            {
                break;
            }
        }
    }

public:
    void construct_heap(const vector<int> &nums)
    {
        heap = nums;
        for (int i = heap.size() - 1; i >= 0; --i)
            sift_down(i, false);
    }

    void push(int value)
    {
        heap.push_back(value);
        sift_up(heap.size() - 1);
    }

    int extract_min()
    {
        if (heap.empty())
            return -INF;

        int min_elem = heap[0];
        sift_down();
        return min_elem;
    }
};

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        Heap heap;
        heap.construct_heap(nums);

        for (int i = 0; i < nums.size(); ++i)
            nums[i] = heap.extract_min();

        return nums;
    }
};