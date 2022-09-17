#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) 
{       
    int maxLI = 0;
    int maxRI = height.size() - 1;
    int maxArea = std::min(height[maxLI], height[maxRI]) * (height.size() - 1);
    
    int i = 0;
    int j = height.size() - 1;
    
    while(i != j)
    {
        int newArea = std::min(height[i], height[j]) * (j - i);
        
        if(newArea >= maxArea)
        {   
            maxArea = newArea;
            maxLI = i;
            maxRI = j;
        }
        
        if(height[maxLI] > height[maxRI])
        {
            j--;
        }
        else if (height[maxLI] < height[maxRI])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    
    return maxArea;
}


int main()
{
    vector<int> height = (2,3,4,5,18,17,6);

    cout<<maxArea(height)<<endl;

    return 0;
}