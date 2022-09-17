#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

class BinaryWordTree
{
  private:
    struct node
    {
        node *childLeft;
        node *childRight;
        string word;

        node()
        {
            childLeft = nullptr;
            childRight = nullptr;
            word = "-";
        }
        node(string _word)
        {
            childLeft = nullptr;
            childRight = nullptr;
            word = _word;
        }
        node(node *left, node *right, string _word)
        {
            childLeft = left;
            childRight = right;
            word = _word;
        }
    };

    node *root;
    string wordEnd;
    string wordBeg;

  public:
    BinaryWordTree(const string &beg, const string &end)
    {
        wordBeg = beg;
        wordEnd = end;
        root = new node(wordBeg);
    };

    void InitTreeFromVector(const vector<string> &wordList)
    {
        for (string word : wordList)
        {
            cout << "Adding word: " << word << endl;
            this->AddWord(word);
        }
    }

    void AddWord(const string &word)
    {
        node *tmp = root;
        while (tmp->word != word)
        {
            cout << tmp->word << endl;
            if (tmp->word > word)
            {
                if (tmp->childLeft == nullptr)
                    tmp->childLeft = new node(word);
                tmp = tmp->childLeft;
            }
            else
            {
                if (tmp->childRight == nullptr)
                    tmp->childRight = new node(word);
                tmp = tmp->childRight;
            }
        }
    }

    void CountWords(node *head);

    //    bool wordCMP(string w1, string w2)
    //    {
    //        int for (int i = 0; i < w1.size(); ++i) {}
    //    }

    void BFS() // node *beg, node *end)
    {
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();

            cout << curr->word << " ";

            if (curr->childLeft)
                q.push(curr->childLeft);

            if (curr->childRight)
                q.push(curr->childRight);
        }
    }
};

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int distance = 0;
    return distance;
}

int main()
{
    vector<string> wordList({"hot", "dot", "dog", "lot", "log", "cog"});
    string beginWord = "hit";
    string endWord = "cog";

    BinaryWordTree tree(beginWord, endWord);
    tree.InitTreeFromVector(wordList);

    tree.BFS();
    return 0;
}
