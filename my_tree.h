#ifndef MY_TREE_H
#define MY_TREE_H
#include"my_tree.h"
#include<cmath>
#include<algorithm>
#include <vector>
#include<queue>
#include<stack>
using namespace std;
// note that any function helper is private
template <class T>
struct Node {
    T data;
    Node<T> *left =NULL;
    Node<T> *right =NULL;

   // Node<T>(T data) : data(data) {

    //}
    // Add the constructors you want
};

template <class T>
class MyTree{

    private:
    Node<T>*root;
    int size;
    /////////////////////////////////////////////////////
    void inorder_helper(vector<T>&m,Node<T>*temp){
    if(temp==NULL) return;
    else{
         inorder_helper(m,temp->left);
        m.push_back(temp->data);
        inorder_helper(m,temp->right);
         }
 }
 //////////////////////////////////////////////////////
  void preoreder_helper(vector<T>&l,Node<T>*t){

    if(t==NULL) return;
    else{
        l.push_back(t->data);
         preoreder_helper(l, t->left );
          preoreder_helper(l, t->right );
    }
 }
 //////////////////////////////////////////////////////////
  void postoreder_helper(vector<T>&j,Node<T>*h){

    if(h==NULL) return;
    else{

         postoreder_helper(j,h->left);
          postoreder_helper(j,h->right);
          j.push_back(h->data);
    }
 }
///////////////////////////////////////////////////////////////
   int get_helper_hight(Node<T> *temp){
        if(temp==NULL) return -1;
        else
        {
            int l=get_helper_hight(temp->left);
            int r=get_helper_hight(temp->right);
              if(l>r)
              return (l+1);
              else
              return (r+1);

        }

       }

       //////////////////////////////////////////////////
        void insert_helper(Node<T>*temp,T value){
        if(value<temp->data){
            if(temp->left==NULL){
             Node<T>*new_leaf=new Node<T>;
                new_leaf->data=value;

                temp->left=new_leaf;
            }
            else{

                insert_helper(temp->left,value);
            }
        }
             else{
                  if(temp->right==NULL){
             Node<T>*new_leaf=new Node<T>;
                new_leaf->data=value;

                temp->right=new_leaf;
            }
            else{

                insert_helper(temp->right,value);
            }
        }
        }
  /////////////////////////////////////////////////////////////////
      Node<T>*searsh_helper(Node<T>*ptr, T k){
         if(ptr==NULL){
            return NULL;
         }
             if(k==ptr->data){
            return ptr;
             }
             else if(k<ptr->data){
            return  searsh_helper(ptr->left,k);
            }
          else if(k>ptr->data){
            return searsh_helper(ptr->right,k);
          }

             }
           // return NULL;

            //////////////////////////////////////////////
           Node<T>*maxi(Node<T>*pp){
          if(pp==NULL)return NULL;
          else if(pp->right==NULL)return pp;
          else
          maxi(pp->right);
           }
           //////////////////////////////
            void delete_helper(Node<T>*ptr,T value){
                if(ptr==NULL)return ;
                if (value<ptr->data)
                {
                delete_helper(ptr->left,value);
                }
                else if(value>ptr->data)
                delete_helper(ptr->right,value);

                else
                {
                   if(ptr->left==NULL && ptr->right==NULL)
                    return ;

                else if (ptr->left==NULL &&ptr->right!=NULL){
                      ptr->data=ptr->right->data;
                      delete_helper(ptr->right,ptr->data);
                  }
                  else if(ptr->right==NULL &&ptr->left!=NULL){
                 ptr->data=ptr->left->data;
                 delete_helper(ptr->left,ptr->data);
                  }
                  {
                  Node<T>*temp=maxi(ptr->left);
                  ptr->data=temp->data;
                 delete_helper(ptr->left,temp->data);
                }

      }
            }
      ////////////////////////////////////////////////////////
 void clear_helper(Node<T>*temp){
    if(temp==NULL)return ;
    else{
    clear_helper(temp->left);
     clear_helper(temp->right);
     delete temp;
     }
}
  ///////////////////////////////////////////////////////////
      Node<T>*creat_tree(vector<T>v,int start,int end){
        if(start>end)
        return NULL;
        int midle=(start+end)/2;
        if((start+end)%2!=0)
        midle=midle+=1;
        Node<T>*new_one=new Node<T>;
        new_one->data=v[midle];
        new_one->left=creat_tree(v,start,midle-1);
        new_one->right=creat_tree(v,midle+1,end);

        return new_one;
      }
      //////////////////////////////////////////////////////
      vector<T>r_help(Node<T>*ptr){
     std::vector<T>vv;
        Node<T>*curr=ptr;
        stack<Node<T>*>ss;
        while(true){
            if(curr!=NULL){
                ss.push(curr);
                curr=curr->left;
            }
            else{
                if(ss.empty())
                break;
                vv.push_back(ss.top()->data);
                curr=ss.top()->right;
                ss.pop();
            }
        }
        return vv;
      }
/////////////////////////////////////////////////////
vector<T>post_order_help(Node<T>*pp){
    vector<T>vs;
    if(pp==NULL)
    return vs;
    stack<Node<T>*> st;
    stack<Node<T>*>res;
    st.push(pp);

    while(!st.empty()){
     Node<T>*curr=st.top();
     st.pop();
     res.push(curr);

       if(curr->left!=NULL)
       st.push(curr->left);

       if(curr->right!=NULL)
       st.push(curr->right);
    }
    while(!res.empty()){
        vs.push_back(res.top()->data);
        res.pop();
    }
      return vs;
}

    public:
        MyTree(){
            size=0;
            root=NULL;
        }

        MyTree(std::vector<T> elements){
            size=elements.size();
            root=NULL;
             sort(elements.begin(),elements.end());
           root=creat_tree(elements,0,elements.size()-1);
        }


        void insert(T key){

            if(root==NULL){
                Node<T>*new_one=new Node<T>;
                new_one->data=key;
                size++;
                root=new_one;
            }
            else{
                size++;
            insert_helper(root,key);
            }
        }

        void insert(const Node<T> node ){

            if(root==NULL){
                size++;
                Node<T>*pt=new Node<T>;
                pt->data=node->data;
                root=pt;
            }
            else{
                size++;
                insert_helper(root,node->data);
            }


        }

        const Node<T>* search(T key){

          return  searsh_helper(root,key);
        }

        const Node<T>* delete_node(T key){

         if(root==NULL) return NULL;
         if(search(key)!=NULL){
            size--;
            Node<T>*nod=new Node<T>;
            nod->data;
            delete_helper(root,key);
            return nod;
         }
        }
        const Node<T>* delete_node(const Node<T> node){
             if(root==NULL)
            return root;
            if(search(node->data)!=NULL){
                size--;
                Node<T>*temp=new Node<T>;
                temp->data=node->data;
                delete_helper(root,node->data);
                return temp;
            }

    
        }
        

        bool isBST(){
          std::vector<T> check =inorder_it();
            bool is=true;
            for(int i=0;i<check.size()-1;i++){
                if(check[i]>check[i+1]){
               is=false;
                break;
                }
            }
            return is;
        }

        std::vector<T> inorder_rec(){
            vector<T> v;
            if(root==NULL)
            return v;
            else{
            inorder_helper(v,root);
            return v;
            }
        }

        std::vector<T> preorder_rec(){
            vector<T>f;
            if(root==NULL)
            return f;
            else{
            preoreder_helper(f,root);
            return f;
            }
        }


        std::vector<T> postorder_rec(){
            vector<T>g;
            if(root==NULL)
            return g;
            else{
            postoreder_helper(g,root);
            return g;
            }

        }

        std::vector<T> inorder_it(){
            return r_help(root);


        }

        std::vector<T> preorder_it(){
            stack<Node<T>*>nod;
            vector<T> k;
            if(root==NULL)return k;
            nod.push(root);
            while(!nod.empty()){
                Node<T>*curr=nod.top();
                k.push_back(curr->data);
                nod.pop();
            if(curr->right!=NULL)
            nod.push(curr->right);

            if(curr->left!=NULL)
            nod.push(curr->left);
            }
            return k;

        }

        std::vector<T> postorder_it(){
            return post_order_help(root);

        }

        std::vector<T> breadth_traversal(){
            vector<T> v;

            if(root==NULL)return v;
             queue<Node<T>*>q;
             q.push(root);
             while(!q.empty()){
                Node<T> *curr=q.front();
                q.pop();
                v.push_back(curr->data);

                if(curr->left!=NULL)
                q.push(curr->left);

                if(curr->right!=NULL)
                q.push(curr->right);
             }
             return v;
        }

        int get_size(){
            return size;
        }

        int get_height(){
            return get_helper_hight(root);

        }

        void clear(){
            clear_helper(root);
            root =nullptr;
        }

        ~MyTree(){

        }
      };

#endif
