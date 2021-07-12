//Gavin Garner CS 372
// Trees and those within
// We will be creating and manipulating trees

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// CONSTANTS & STRUCTS
ifstream inf;
ofstream outf;

struct Tree
{
    Tree *GoLeft; // a pointer to take us left
    Tree *GoRight; // a pointer to take us right

    int val;
};
    Tree *root; // This is the beginning of the tree
    int NumNodes = 0; // Total Nodes in tree
void Write(string message)
{
    cout << message << "\n";
    outf << message << "\n";
    return;
}

Tree* MakeNewNode() // Making empty nodes for the tree
{
    Tree *T;
    T = new Tree;
    T->val = 0;
    T->GoLeft = NULL;
    T->GoRight = NULL;

    return T;
}

void Insert(Tree *current, int number) // Put a node into the tree
{
    current = root; // start at the root
    Tree *prev; // follow our pointer so we can link the tree
    prev = NULL;


    while (current != NULL) // while there is something to read
    {
        prev = current; // update our following pointer

        if (number > current->val)
            current = current->GoRight; // Bigger numbers go right
        else
            current = current->GoLeft; // Smaller numbers go left
    }

    // Create the new node and input the value
    current = MakeNewNode();
    current->val = number; // populate the new node
    current->GoLeft = NULL;
    current->GoRight = NULL;

    // Now let's add it to the list
    if(prev != NULL)
    {
        if (number > prev->val)// If bigger then its on right else its on the left
            prev->GoRight = current;
        else
            prev->GoLeft = current;
    }
    else
        root = current; // if previous DNE then we need to establish our root

    return;
}



void PrintInOrderTree(Tree *node, int &nbr) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf
    nbr++;
    if (nbr < 20)
    {
    PrintInOrderTree(node->GoLeft, nbr);
    }

    cout << node->val << " ";
    outf << node->val << " ";

    if (nbr < 20)
    {
    PrintInOrderTree(node->GoRight, nbr);
    }

    return;
}

void PrintPreOrderTree(Tree *node, int &nbr) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf

    nbr++;
    if( nbr < 21 )
    {
    cout << node->val << " ";
    outf << node->val << " ";

    PrintPreOrderTree(node->GoLeft, nbr);
    PrintPreOrderTree(node->GoRight, nbr);
    }

    return;
}

void PrintPostOrderTree(Tree *node, int &nbr) // Let's use some recursion
{

    if (node ==  NULL)
        return; // We have reached a leaf

        nbr++;
    if(nbr < 21)
    {
    PrintPostOrderTree(node->GoLeft, nbr);
    PrintPostOrderTree(node->GoRight, nbr);
    cout << node->val << " ";
    outf << node->val << " ";
    }

    return;
}

void TreeSum(Tree *node, float &total)
{
    if (node == NULL)
        return;
    total = total + node->val;

    TreeSum(node->GoLeft, total);
    TreeSum(node->GoRight, total);

    return;
}

void LeafNum(Tree *node, float &total, float &NumLeaf)
{
    if (node == NULL)
        return;
    if (node->GoLeft == NULL && node->GoRight == NULL)
        {
            total = total + 1;
            NumLeaf++;
        }
    LeafNum(node->GoLeft, total, NumLeaf);
    LeafNum(node->GoRight, total, NumLeaf);

    return;
}

void Dig(Tree *node, int depth, int &maxDepth, int &res)
{
    if (node != NULL)
    {
        Dig(node->GoLeft, ++depth, maxDepth, res);

        // Update depth and resue
        if (depth > maxDepth)
        {
            res = node->val;
            maxDepth = depth;
        }

        Dig(node->GoRight, depth, maxDepth, res);
    }
    return;
}

// Returns value of deepest node
int deepestNode(Tree *node)
{
    // Initialze result and max depth
    int res = -1;
    int maxDepth = -1;

    // Updates value "res" and "maxDepth"

    Dig(node, 0, maxDepth, res);
    return res;
}


void OneChild(Tree *node, float &total)
{
    if (node == NULL)
        return;

        if(node->GoLeft != NULL && node->GoRight == NULL )
            {
              total = total + 1;
            }

        if(node->GoLeft == NULL && node->GoRight != NULL )
            {
              total = total + 1; 
            }

    OneChild(node->GoLeft, total);
    OneChild(node->GoRight, total);

    return;
}

void PrintSubTreeInOrder(Tree *node, int subRoot, int &isRoot)
{
  if (node == NULL)
    return; // We have reached a leaf
  if (node->val == subRoot)
  {
    isRoot = 1;
  }

  PrintSubTreeInOrder(node->GoLeft, subRoot, isRoot);

  if (isRoot == 1)
  {
    cout << node->val << " ";
    outf << node->val << " ";
  }

  PrintSubTreeInOrder(node->GoRight, subRoot, isRoot);  
  
  if (node->val == subRoot)
  {
    isRoot = 0;
  }
}

void PrintSubTreePostOrder(Tree *node, int subRoot, int &isRoot)
{
  if (node == NULL)
    return; // We have reached a leaf
  if (node->val == subRoot)
  {
    isRoot = 1;
  }

  PrintSubTreePostOrder(node->GoLeft, subRoot, isRoot);


  PrintSubTreePostOrder(node->GoRight, subRoot, isRoot);  
  
  if (isRoot == 1)
  {
    cout << node->val << " ";
    outf << node->val << " ";
  }
  
  if (node->val == subRoot)
  {
    isRoot = 0;
  }
}

void PrintLeftTree(Tree *node, float &total) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf

    if (node->val > root->val)
        return;

    PrintLeftTree(node->GoLeft, total);

    if (node->val != root->val)
    {
      total = total + 1;
    }

    PrintLeftTree(node->GoRight, total);

    return;
}

void PrintRightTree(Tree *node, float &total) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf

    if (node->val < root->val)
        return;

    PrintRightTree(node->GoLeft, total);

    if (node->val != root->val)
    {
      total = total + 1;
    }

    PrintRightTree(node->GoRight, total);

    return;
}

void deleteNode(Tree *node, int search)
{
  Tree *prev;
  Tree *prev2ElectricBoogaloo;
  prev = NULL;
  prev2ElectricBoogaloo = NULL;

  while(node != NULL && search != node->val)
  {
    prev = node; // update our following pointer
    if (search > node->val)
      node = node->GoRight; // Bigger numbers go right
    else
      node = node->GoLeft; // Smaller numbers go left
    
  }
  if (node == NULL)
    return;
  // if its a leaf
  if(node->GoLeft == NULL && node->GoRight == NULL)
    {
      if(prev->GoRight == node)
      {
        prev->GoRight = NULL;
      }
      else
      {
        prev->GoLeft = NULL;
      }
      delete node;
      return;
    }

  //if it has a child on the left
  if(node->GoLeft != NULL && node->GoRight == NULL)
    {
      if(prev->GoRight == node)
        {
          prev->GoRight = node->GoLeft;
        }
      else
        {
          prev->GoLeft = node->GoLeft;
        }
      delete node;
      return;
    }
  
  // it it has a child on the right
  if(node->GoLeft == NULL && node->GoRight != NULL)
    {
      if(prev->GoRight == node)
        {
          prev->GoRight = node->GoRight;
        }
      else
        {
          prev->GoLeft = node->GoRight;
        }
      delete node;
      return;
    }
  // node has 2 children
  if(node->GoLeft != NULL && node->GoRight != NULL)
    {
      //go left and get the largest value from that sub tree
      prev2ElectricBoogaloo = node;
      prev = node;
      node = node->GoLeft;
      while(node->GoRight !=NULL)
        {
          prev = node;
          node = node->GoRight;
        }
      prev2ElectricBoogaloo->val = node->val;
      // if its a leaf
      if(node->GoLeft == NULL && node->GoRight == NULL)
        {
          if(prev->GoRight == node)
          {
            prev->GoRight = NULL;
          }
          else
          {
            prev->GoLeft = NULL;
          }
          delete node;
          return;
        }

      //if it has a child on the left
      if(node->GoLeft != NULL && node->GoRight == NULL)
        {
          if(prev->GoRight == node)
            {
              prev->GoRight = node->GoLeft;
            }
          else
            {
              prev->GoLeft = node->GoLeft;
            }
          delete node;
          return;
        }
      
      // it it has a child on the right
      if(node->GoLeft == NULL && node->GoRight != NULL)
        {
          if(prev->GoRight == node)
            {
              prev->GoRight = node->GoRight;
            }
          else
            {
              prev->GoLeft = node->GoRight;
            }
          delete node;
          return;
        }
    }
  
}

int SumOfDigits(int x)
  {
    if (x == 0)
     return 0;
    
    return SumOfDigits(x/10) + x%10;
  }

void DeleteAllNodesLessThan(Tree *node, int num)
  {
    if (node ==  NULL)
        return; 

    DeleteAllNodesLessThan(node->GoLeft, num);
  
    DeleteAllNodesLessThan(node->GoRight, num);

    if(SumOfDigits(node->val) < (num + 1))
    {
      deleteNode(root, node->val);
      NumNodes--;
    }
    return;
    
  }

int main()
{

    inf.open("TreeRandNbrs.dat");
    outf.open("Results.txt");
    int temp = 0;
    float NumLeaf = 0;
    float total = 0;

    while(inf >> temp)
    {
        NumNodes++;
        Insert(root, temp);
    }

    temp = 0;
    Write("In Order Tree List(20 entires):");
    PrintInOrderTree(root, temp);
    Write("\n");

    temp = 0;
    Write("Pre Order Tree List(20 entires):");
    PrintPreOrderTree(root, temp);
    Write("\n");

    temp = 0;
    Write("Post Order Tree List(20 entires):");
    PrintPostOrderTree(root, temp);
    Write("\n");

    Write("Number of Nodes Values in Tree: ");
    cout << NumNodes;
    outf << NumNodes;
    Write("\n");

    Write("Sum and Average of All Values");
    TreeSum(root, total);
    cout << "Sum: " << total << endl;
    cout << "Average: " << setprecision(3) << fixed << total/NumNodes << endl;
    outf << "Sum: " << total << endl;
    outf << "Average: " << setprecision(3) << fixed << total/NumNodes << endl;

    Write("\nNumber of Leafs");
    total=0;
    LeafNum(root, total, NumLeaf);
    cout << "Total Leafs: " << setprecision(0) << fixed << total << endl;
    outf << "Total Leafs: " << setprecision(0) << fixed << total << endl;

    Write("\nDeepest Node Value:");
    total = deepestNode(root);
    cout << total << endl;
    outf << total << endl;


    Write("\nNumber of nodes that have One Child: ");
    total = 0;
    OneChild(root, total);
    outf << total;
    cout << total;
    Write("\n");

    Write("\nSubtree with root as node 195 inorder:");
    temp = 0;
    PrintSubTreeInOrder(root, 195, temp);
    Write("\n");

    Write("\nSubtree with root as node 450 postorder:");
    temp = 0;
    PrintSubTreePostOrder(root, 450, temp);
    Write("\n");

    Write("Amount of numbers to the Left of the Root");
    total = 0;
    PrintLeftTree(root, total);
    outf << total;
    cout << total;
    Write("\n");

    Write("Amount of numbers to the Right of the Root");
    total = 0;
    PrintRightTree(root, total);
    outf << total;
    cout << total;
    Write("\n");

    Write("Deleting all nodes whose sum of digits is less than 12:\n");
    DeleteAllNodesLessThan(root, 12);
    temp = 0;
    Write("In Order Tree List (20 entires):");
    PrintInOrderTree(root, temp);
    Write("\n");  

    Write("Number of Nodes Values in Tree: ");
    cout << NumNodes;
    outf << NumNodes;
    Write("\n");  

    Write("Sum and Average of All Values");
    TreeSum(root, total);
    cout << "Sum: " << total << endl;
    cout << "Average: " << setprecision(3) << fixed << total/NumNodes << endl;
    outf << "Sum: " << total << endl;
    outf << "Average: " << setprecision(3) << fixed << total/NumNodes << endl;   

    inf.close();
    outf.close();
    return 0;
}