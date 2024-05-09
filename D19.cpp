#include <iostream>
#include <string>
using namespace std;


struct bstNode{
    char key;
    string value;
    bstNode* left;
    bstNode* right;
};


class Avltree{
    public:

        int count = 0;

        // creating a new node
        bstNode* getNewNode(char key, string value){
            bstNode* newNode = new bstNode();
            newNode->key = key;
            newNode->value = value;
            newNode->left = newNode->right = NULL;
            return newNode;
        }

        // inserting nodes in bst
        bstNode* insert(bstNode* root, char key, string value){
            if(root == NULL){
                root = getNewNode(key, value);
            }else if(key <= root->key){
                root->left = insert(root->left, key, value);
            }else{
                root->right = insert(root->right, key, value);
            }
            return root;
        }


        // searching the key / Finding the maximum no of comparison
        bool search(bstNode* root, char key){
            if(root == NULL) return false;
            else if(root->key == key){
                count++;
                return true;
            } 
            else if(key <= root->key) return search(root->left, key);
            else return search(root->right, key);
        }


        // Update the key value
        bool update(bstNode* root, char key, string value) {
            bstNode *temp;
            temp = root;
            while (temp != NULL) {
                if (temp->key == key) {
                    temp->value = value;
                    return 1;
                } else if (temp->key < key) {
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            }
            return 0;
        }


        // displaying the nodes
        void display(bstNode* root){
            if(root == NULL)return;
            display(root->left);
            cout<<root->key<<" : "<<root->value<<endl;
            display(root->right);
        }
     
         // Deleting a node  recheck this code there is an bug
        bstNode* Delete(bstNode* root, char key){
            if(root == NULL) return root;
            else if(key < root->key) root->left = Delete(root->left, key);
            else if(key > root->key) root->right = Delete(root->right, key);
            else{

                // Found the node

                // Case 2: Node with 1 or 0 child
                if(root->left == NULL){
                    bstNode* temp = root->right;
                    delete root;
                    return temp;
                }

                else if(root->right == NULL){
                    bstNode* temp = root->left;
                    delete root;
                    return temp;
                }


                // Case 3: Node with 2 childs
                else{
                    bstNode* temp = root->right;
                    while (temp->left != NULL) {
                        temp = temp->left;
                    }
                    root->key = temp->key;
                    root->value = temp->value;
                    root->right = Delete(root->right, temp->key);
                }
            }
            return root;
        }
};

int main(){
    bstNode* root = NULL;
    Avltree tree;
    int choice, noOfKeys;

    char key, dkey, ukey, ckey, okey, nkey;
    string value, nvalue;

    do{
        cout<<"************-MENU-*************"<<endl;
        cout<<"1.Add word in a dictionary"<<endl;
        cout<<"2.Display Dictionary"<<endl;
        cout<<"3.Delete a word"<<endl;
        cout<<"4.Find the comparison"<<endl;
        cout<<"5.Update the key and word"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;

        switch(choice){

            case 1:
                cout<<"How many word do you want to add in dictonary:";
                cin>>noOfKeys;
                for(int i = 0; i < noOfKeys; i++){
                    cout<<"Enter a key:";
                    cin>>key;
                    cout<<"Enter a value:";
                    cin>>value;
                    root = tree.insert(root, key, value);
                }
                break;
            
            case 2:
                cout<<"*********-Dictionary-**********"<<endl;
                tree.display(root);
                break;
            
            case 3:
                cout<<"***********-Deleting-***********"<<endl;
                cout<<"Enter a key to delete a word: ";
                cin>>dkey;
                
                root = tree.Delete(root, dkey);
                cout<<"Deleted "<<dkey<<endl;

                break;
            
            case 4:
                cout<<"***********-No Of Comparision-**************"<<endl;
                cout<<"Enter a key to search how much comparison required:";
                cin>>ckey;

                if(tree.search(root, ckey)){
                    cout<<"The "<<ckey << " Is present"<<endl;

                };
                cout<<"Total comparision required for getting a value is "<<tree.count<<endl;
                break;
            
            case 5:

                cout<<"***********-Update the key value-************"<<endl;
                cout<<"Which key do u want to update:";
                cin>>okey;

                cout<<"Enter a new value:";
                cin>>nvalue;

                tree.update(root, okey, nvalue);
                break;

            default:
                cout<<"--------Exiting-----------"<<endl;
                break;
            
        }

    }while(choice != 6);

}