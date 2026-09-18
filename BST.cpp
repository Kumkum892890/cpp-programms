#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left ;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;

    }
};
Node* insert(Node* root , int val){
if(root == NULL){
return new Node(val);
}
if(val<root-> data){
    root-> left = insert(root->left , val);
}
else{
    root->right = insert(root-> right , val);

}
return root;
}
Node* buildBST(vector<int> arr){
Node* root = NULL;
for(int val : arr){
    root = insert(root, val);
}
return root;
}
void inorderformerge(Node* root , vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorderformerge(root-> left , arr);
    arr.push_back(root->data);
    inorderformerge(root->right, arr);

}
Node* buildBSTFromsorted(vector<int> arr, int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTFromsorted(arr, st, mid-1);
    root->right = buildBSTFromsorted(arr,mid+1, end);
    return root;
}
Node* BST2merge(Node* root1, Node*root2){
    vector<int> arr1, arr2;
    inorderformerge(root1 , arr1);
     inorderformerge(root2 , arr2);
     vector<int>temp; 
     int i=0, j=0;
     while (i<arr1.size() && j<arr2.size()){
        if(arr1[i] <arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else {
            temp.push_back(arr2[j++]);  
        }
     }

   while(i<arr1.size()){
     temp.push_back(arr1[i++]);
   }
   while(j<arr2.size()){
     temp.push_back(arr1[j++]);
   } 
  return  buildBSTFromsorted(temp , 0, temp.size()-1); // sorted order ,st,end  

}

// void inorder(Node* root){
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left);
//     cout<<root-> data <<" ";
//     inorder(root->right);
// }
// bool search(Node* root, int key){
//     if(root == NULL){
//         return false;
//     }
//     if(root-> data == key){
//         return true;
//     }
//     if(root-> data > key){
//         return search(root->left , key);
//     }
//     else{
//         return search(root->right , key);
//     }
// }
// Node* getInorderSuccessor(Node* root){
//     while(root != NULL && root->left != NULL){
//         root = root-> left;
//     }
//     return root;
// }
// Node* delNode(Node* root , int key){
//     if(root == NULL){
//         return NULL;
//     }
//     if(key < root-> data){
//         root-> left = delNode(root->left , key);
        
//     }
//     else if(key > root -> data){
//         root->right = delNode(root-> right , key);
//     }
//     else{
//         if(root-> left == NULL){
//             Node* temp = root-> right;
//             delete root;
//             return temp;
//         }
//         else if (root-> right ==NULL)
//         {
//             /* code */Node* temp = root->left;
//             delete root;
//     return  temp;
//         }
//         else{
//             Node* IS  = getInorderSuccessor(root-> right );
//             root-> data= IS-> data;
//             root->right = delNode(root->right , IS->data);
//         }
        
//     }
//     return root;
// }
// class Info{
    // public:
    // int min, max, sz;
    // Info(int mi , int ma , int size){
        // min = mi;
        // max = ma;
        // sz = size;
    // }

// };
// info helper(Node* root){
// if(root == NULL){
    // return Info(INT_MAX , INT_MAX, 0);
// }
// Info left = helper(root->left);
// Info right = helper(root->right);
// if(root->data > left.max && root->data <right.min){
    // int currMin =min(root->data , left.min);
    // int currMax = max(root->data , right.max);
//     int currSize =left.sz+right.sz+1;
//     return Info(currMin , currMax , currSize)
// }
// else Info(INT_MIN, INT_MAX, max(left.sz , right.sz));
// }
// int largestBSTinBT(Node* root){
//     Info info = helper(root);
//     return info.sz;
// }
//find the predecessor and succesor
Node* rightMostInleftsubtree(Node* root){
    Node* ans;
    while(root!= NULL){
        ans = root;
        root= root->right;
    }
    return ans;
}
Node* leftMostInrightsubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans =root;
        root= root->left;
    }
    return ans;
}
vector<int> getpredecessor(Node* root , int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;
    while(curr != NULL){
        if(key < curr->data){
            succ= curr;
            curr = curr->left;
        }
        else if( key > curr->data){
pred = curr ;
curr = curr->right;
        }
        else{
            if(curr->left != NULL){
                //inorder pred
                pred = leftMostInrightsubtree(curr->left);
                }
            
            if(curr-> right != NULL){
                //inorder succc
                succ= rightMostInleftsubtree(curr->right);

            }
            break;
        }

    }
            return {pred->data, succ->data};

}
 int main(){
    // vector<int> arr1 ={ 8,2,1,10};
// vector<int> arr2 ={ 5,3,0};
    // Node* root1 = buildBST(arr1);
    //   Node* root2 = buildBST(arr2);
    //   Node* root = BST2merge(root1, root2);
    //   inorderformerge(root, seq);
    //   for(int v: seq){
        // cout<<v <<" ";
    //   }
    //   cout<<endl;    //   vector<int> seq;

    // Node* root = new Node(10);
    // root->left = new Node(5);
    // root->right = new Node(15);
        // root->left->left = new Node(1);
            // root->left->right = new Node(8);
                // root->left->right = new Node(7);
Node* root = new Node(6);
root->left = new Node(4);
root->right = new Node(8);
root->left->left = new Node(1);
root->left ->right = new Node(5);
root->right ->left =new Node(7);
root->right->right = new Node(8);
int key =3;
vector<int> ans = getpredecessor(root, key);
cout<<"predecessor:" << ans[0] <<endl;
cout<<"successor:"<<ans[1]<<endl;

    return 0;
 }
