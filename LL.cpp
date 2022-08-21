#include <iostream>
using namespace std;

class linked_list
{
    public:
        struct node
        {
            int data;
            struct node *next,*prev;
        }*head=NULL,*ptr,*nn;

        struct node * create_node(int x)
        {
            nn = new node;
            nn->data=x;
            nn->prev=NULL;
            nn->next=NULL;
            return nn;
        }
};

class sll
{
    public:

        public:
        struct node
        {
            int data;
            struct node *next;
        }*head=NULL,*ptr,*nn;

        struct node * create_node(int x)
        {
            nn = new node;
            nn->data=x;
            nn->next=NULL;
            return nn;
        }

        void insert_beg(int x)
        {
            nn = create_node(x);
            if (head == NULL)
                head=nn;
            else
            {
                nn->next=head;
                head=nn;
            }
            //cout<<"insert_beg\n";
        }

        void insert_end(int x)
        {
            nn = create_node(x);
            if (head == NULL)
                head=nn;
            else
            {
                ptr=head;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=nn;
            }
            //cout<<"insert_end\n";
        }

        void insert_atpos(int x, int pos)
        {
            if(pos<=0)
            {
                cout<<"ERROR : The position can only be greater than 0\n";
            }
            else
            {
                if(pos==1)
                    insert_beg(x);
                else if (pos==count()+1)
                {
                    insert_end(x);
                }
                else if (pos>count()+1)
                {
                    cout<<"ERROR : The position exceeds the total elements in the list\n";
                }
                else
                {
                    nn = create_node(x);
                    int i=1;
                    struct node *prev;
                    ptr=head;
                    while(i!=pos)
                    {
                        prev=ptr;
                        ptr=ptr->next;
                        i++;
                    }
                    nn->next=ptr;
                    prev->next=nn;
                }
            }
            //cout<<"insert_atpos\n";
        }

        void delete_beg()
        {
            if(head==NULL)
            {
                cout<<"ERROR: The list is already empty so no deletion\n";
                return;
            }
            ptr=head;
            head=ptr->next;
            free(ptr);
        }

        void delete_end()
        {
            if(head==NULL)
            {
                cout<<"ERROR: The list is already empty so no deletion\n";
                return;
            }
            ptr=head;
            struct node *prev;
            while(ptr->next!=NULL)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            prev->next=NULL;
            free(ptr);
        }

        void delete_atpos(int pos)
        {
            if(head==NULL)
                cout<<"ERROR: The list is already empty so no deletion\n";
            else if(pos<=0)
                cout<<"ERROR : The position can only be greater than 0\n";
            else if(pos==1)
                delete_beg();
            else if(pos==count())
                delete_end();
            else if(pos>count())
                cout<<"ERROR : The position exceeds the total elements in the list\n";
            else
            {
                int i=1;
                ptr=head;
                struct node *prev;
                while(i!=pos)
                {
                    prev=ptr;
                    ptr=ptr->next;
                    i++;
                }
                prev->next=ptr->next;
                free(ptr);
            }
            
        }
        
        int count()
        {
            //cout<<"1\n";
            int i=0;
            ptr=head;
            while(ptr!=NULL)
            {
                ptr=ptr->next;
                i++;
            }
            //cout<<"count = "<<i<<"\n";
            return i;
        }

        void display()
        {
            ptr=head;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
            //cout<<"display\n";
        }
};

class dll : public linked_list
{
    public:

        void insert_beg(int x)
        {
            nn = create_node(x);
            if (head==NULL)
            {
                head=nn;
                return;
            }
            nn->next=head;
            head->prev=nn;
            head=nn;
        }

        void insert_end(int x)
        {
            nn = create_node(x);
            if (head==NULL)
            {
                head=nn;
                return;
            }
            ptr=head;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=nn;
            nn->prev=ptr;
        }
        
        void insert_atpos(int x,int pos)
        {
            if(pos<=0)
            {
                cout<<"ERROR : The position can only be greater than 0\n";
            }
            else
            {
                if(pos==1)
                    insert_beg(x);
                else if (pos==count()+1)
                {
                    insert_end(x);
                }
                else if (pos>count()+1)
                {
                    cout<<"ERROR : The position exceeds the total elements in the list\n";
                }
                else
                {
                    nn = create_node(x);
                    int i=1;
                    struct node *ptr1;
                    ptr=head;
                    while(i!=pos)
                    {
                        ptr1=ptr;
                        ptr=ptr->next;
                        i++;
                    }
                    ptr1->next=nn;
                    nn->prev=ptr1;
                    nn->next=ptr;
                    ptr->prev=nn;
                }
            }
        }

        int count()
        {
            //cout<<"1\n";
            int i=0;
            ptr=head;
            while(ptr!=NULL)
            {
                ptr=ptr->next;
                i++;
            }
            //cout<<"count = "<<i<<"\n";
            return i;
        }

        void display()
        {
            ptr=head;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
            //cout<<"display\n";
        }

};

int main()
{
    sll sl1,sl2;
    sl1.insert_beg(3); // 3
    sl1.insert_end(4); // 3 4
    sl1.insert_end(7); // 3 4 7
    sl2.insert_beg(5); // 5
    sl1.insert_beg(5); // 5 3 4 7
    sl1.insert_atpos(8,2); // 5 8 3 4 7
    sl2.insert_atpos(5,3); // ERROR
    sl2.insert_end(7); // 5 7
    sl2.insert_end(9); // 5 7 9
    sl2.insert_atpos(4,3); // 5 7 4 9
    sl1.display(); // 5 8 3 4 7
    sl2.display(); // 5 7 4 9
    sl1.delete_beg(); // 8 3 4 7
    sl2.delete_end(); // 5 7 4
    sl1.delete_atpos(3); // 8 3 7
    sl2.delete_beg(); // 7 4
    sl2.delete_atpos(2); // 7
    sl1.delete_end();// 8 3
    cout<<"sl1 count = "<<sl1.count()<<endl;
    sl1.display();
    cout<<"sl2 count = "<<sl2.count()<<endl;
    sl2.display();
    
    
    cout<<"DLL\n\n\n";
    
    
    dll dl1,dl2;
    dl1.insert_beg(3); // 3
    dl1.insert_end(4); // 3 4
    dl1.insert_end(7); // 3 4 7
    dl2.insert_beg(5); // 5
    dl1.insert_beg(5); // 5 3 4 7
    dl1.insert_atpos(8,2); // 5 8 3 4 7
    dl2.insert_atpos(5,3); // ERROR
    dl2.insert_end(7); // 5 7
    dl2.insert_end(9); // 5 7 9
    dl2.insert_atpos(4,3); // 5 7 4 9
    dl1.display(); // 5 8 3 4 7
    dl2.display(); // 5 7 4 9
    return 0;
}