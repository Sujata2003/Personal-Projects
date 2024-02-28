#include<iostream>
using namespace std;
struct node
{
	string company;
    string location;
    string post;
    float salary;
    string email;
    string mob;
    string offeredto;
    int id;
	node *link,*down;
};
struct node* create()
{
	struct node *parent,*child,*ptrp,*ptrc,*root=NULL;
	char ch,choice;
	int ch1=1;
	ptrp=new node;
	cout<<"Enter the first node in Graph:";
	cout<<"\nEnter the parent node:\n";
	cout<<"\nEnter the Job ID:";
	cin>>ptrp->id;
	cout<<"\nEnter the company name:";
	cin>>ptrp->company;
	cout<<"\nEnter the location:";
	cin>>ptrp->location;
	cout<<"\nEnter the post:";
	cin>>ptrp->post;
	cout<<"\nEnter the salary(in Rs.):";
	cin>>ptrp->salary;
	cout<<"\nEnter the Email:";
	cin>>ptrp->email;
	cout<<"\nEnter the Mobile no.:";
	cin>>ptrp->mob;
	cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
	cin>>ptrp->offeredto; 
	ptrp->down=NULL;
	ptrp->link=NULL;
	parent=ptrp;
	child=ptrp;
	if(root==NULL)
	{
		root=ptrp;
	}
	do
	{
		ptrc=new node;
		cout<<"\nEnter adjacent node for Job Id "<<ptrp->id<<':';	
		cout<<"\n\nEnter the Job ID:";
		cin>>ptrc->id;
		cout<<"\nEnter the company name:";
		cin>>ptrc->company;
		cout<<"\nEnter the location:";
		cin>>ptrc->location;
		cout<<"\nEnter the post:";
		cin>>ptrc->post;
		cout<<"\nEnter the salary(in Rs.):";
		cin>>ptrc->salary;
		cout<<"\nEnter the Email:";
		cin>>ptrc->email;
		cout<<"\nEnter the Mobile no.:";
		cin>>ptrc->mob;
		cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
		cin>>ptrc->offeredto; 	
		ptrc->link=NULL;
		ptrc->down=NULL;
		child->link=ptrc;
		child=ptrc;
		cout<<"Want to add more adjacent node(y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	cout<<"\nEnter Another Parent nodes in Graph:";
	while(ch1==1)
	{
		ptrp=new node;
		cout<<"\nEnter the parent node:\n";
		cout<<"\nEnter the Job ID:";
		cin>>ptrp->id;
		cout<<"\nEnter the company name:";
		cin>>ptrp->company;
		cout<<"\nEnter the location:";
		cin>>ptrp->location;
		cout<<"\nEnter the post:";
		cin>>ptrp->post;
		cout<<"\nEnter the salary(in Rs.):";
		cin>>ptrp->salary;
		cout<<"\nEnter the Email:";
		cin>>ptrp->email;
		cout<<"\nEnter the Mobile no.:";
		cin>>ptrp->mob;
		cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
		cin>>ptrp->offeredto;
		ptrp->down=NULL;
		ptrp->link=NULL;
		parent->down=ptrp;
		parent=ptrp;
		child=ptrp;
		do
		{
			ptrc=new node;
			cout<<"\nEnter adjacent node for "<<ptrp->id<<':';
			cout<<"\nEnter the Job ID:";
			cin>>ptrc->id;
			cout<<"\nEnter the company name:";
			cin>>ptrc->company;
			cout<<"\nEnter the location:";
			cin>>ptrc->location;
			cout<<"\nEnter the post:";
			cin>>ptrc->post;
			cout<<"\nEnter the salary(in Rs.):";
			cin>>ptrc->salary;
			cout<<"\nEnter the Email:";
			cin>>ptrc->email;
			cout<<"\nEnter the Mobile no.:";
			cin>>ptrc->mob;
			cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
			cin>>ptrc->offeredto;
			ptrc->link=NULL;
			ptrc->down=NULL;
			child->link=ptrc;
			child=ptrc;
			cout<<"\nWant to add more adjacent node(y/n):";
			cin>>choice;
		}while(choice=='y' || choice=='Y');
		cout<<"\nWant to add more parent node(1/0):";
		cin>>ch1;
	}
	return root;
}

node *findlastp(node *root)
{
	node *temp;
	temp=root;
	while(temp->down!=NULL)
	{
		temp=temp->down;
	}	
	return temp;
}

void display(node *root)
{
	struct node *temp,*temp1;
	temp=root;
	cout<<"\n\n---------------------------JOB BOARD--------------------------------------:\n\n"<<endl;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->id<<',';
		cout<<temp->company<<',';
		cout<<temp->location<<',';
		cout<<temp->post<<',';
		cout<<temp->salary<<',';
		cout<<temp->email<<',';
		cout<<temp->mob<<',';
		cout<<temp->offeredto<<"|";
		temp1=temp->link;
		cout<<"------->";
		while(temp1!=NULL)
		{
			cout<<"|"<<temp1->id<<',';
			cout<<temp1->company<<',';
			cout<<temp1->location<<',';
			cout<<temp1->post<<',';
			cout<<temp1->salary<<',';
			cout<<temp1->email<<',';
			cout<<temp1->mob<<',';
			cout<<temp1->offeredto<<"|";
			temp1=temp1->link;
		}

		temp=temp->down;
		if(temp!=NULL)
		{
			cout<<endl;
		}
	}
	cout<<"\n------------------------------------------------------------------------------------";
}
node *insert(node *root)
{
	node *ptrp,*ptrc,*temp,*temp1;
	char ch,choice,pa;
	cout<<"\n\nDo you want to enter parent node or adjacent node(P/A):";
	cin>>pa;
	if(pa=='P' || pa=='p')
	
	{
		ptrp=new node;
		temp=findlastp(root);
		cout<<"\nEnter the parent node:\n";
		cout<<"Enter the Job ID:";
		cin>>ptrp->id;
		cout<<"\nEnter the company name:";
		cin>>ptrp->company;
		cout<<"\nEnter the location:";
		cin>>ptrp->location;
		cout<<"\nEnter the post:";
		cin>>ptrp->post;
		cout<<"\nEnter the salary(in Rs.):";
		cin>>ptrp->salary;
		cout<<"\nEnter the Email:";
		cin>>ptrp->email;
		cout<<"\nEnter the Mobile no.:";
		cin>>ptrp->mob;
		cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
		cin>>ptrp->offeredto; 
		temp->down=ptrp;
		ptrp->down=NULL;
		ptrp->link=NULL;
		temp1=ptrp;
	do
	{
		ptrc=new node;	
		cout<<"\nEnter adjacent node for Job Id "<<ptrp->id<<':';	
		cout<<"\nEnter the Job ID:";
		cin>>ptrc->id;
		cout<<"\nEnter the company name:";
		cin>>ptrc->company;
		cout<<"\nEnter the location:";
		cin>>ptrc->location;
		cout<<"\nEnter the post:";
		cin>>ptrc->post;
		cout<<"\nEnter the salary(in Rs.):";
		cin>>ptrc->salary;
		cout<<"\nEnter the Email:";
		cin>>ptrc->email;
		cout<<"\nEnter the Mobile no.:";
		cin>>ptrc->mob;
		cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
		cin>>ptrc->offeredto; 	
		ptrc->link=NULL;
		ptrc->down=NULL;
		temp1->link=ptrc;
		temp1=ptrc;
		
		cout<<"Want to add more adjacent node(y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return root;
}
}
node *delnode(node *root)
{
	int key;
	node *link,*down;
	struct node *ptr,*prev;
	cout<<"\nEnter the Job id you want to delete : ";
	cin>>key;
	if(key==root->id)
	{
		ptr=root;
		root=ptr->down;
		ptr->down=NULL;
		delete ptr;
		return root;
	}
	else
	{
		ptr=root;
		while(ptr!=NULL && ptr->id!=key)
		{
			prev=ptr;
			ptr=ptr->down;
		}
		prev->down=ptr->down;
		ptr->down=NULL;
		delete ptr;
		return root;
	}
}

void search(node *root)
{
	int check;
	node *temp, *temp1;
	cout<<"\n\nEnter the JOB ID you want to search: ";
	cin>>check;
	temp=root;
	while(temp!=NULL && temp->id!=check)
	{ 
		temp=temp->down;
	}
	
	if(temp!=NULL)
	{
		if(temp->id==check)
		{
			cout<<"JOB ID: ";
			cout<<temp->id<<',';
			cout<<temp->company<<',';
			cout<<temp->location<<',';
			cout<<temp->post<<',';
			cout<<temp->salary<<',';
			cout<<temp->email<<',';
			cout<<temp->mob<<',';
			cout<<temp->offeredto<<endl;
			temp1=temp->link;
			while(temp1!=NULL)
			{
				cout<<"JOB ID:"<<temp1->id<<',';
				cout<<temp1->company<<',';
				cout<<temp1->location<<',';
				cout<<temp1->post<<',';
				cout<<temp1->salary<<',';
				cout<<temp1->email<<',';
				cout<<temp1->mob<<',';
				cout<<temp1->offeredto<<endl;	
				temp1=temp1->link;
			}
		}
	}
	
}
void modify(node *root)
{
	int check;
	node *temp, *temp1;
	cout<<"\n\nEnter the JOB ID you want to modify: ";
	cin>>check;
	temp=root;
	while(temp!=NULL && temp->id!=check)
	{ 
		
		temp1=temp->link;
		while(temp1!=NULL && temp1->id!=check)
		{
				
			temp1=temp1->link;
		}
		temp=temp->down;
		
	
	}
	if(temp!=NULL)
	{
		if(temp->id==check)
		{
			cout<<"\nEnter The New Job Details:";
		
			cout<<"\nEnter the new company name:";
			cin>>temp->company;
			cout<<"\nEnter the new location:";
			cin>>temp->location;
			cout<<"\nEnter the new post:";
			cin>>temp->post;
			cout<<"\nEnter the new salary(in Rs.):";
			cin>>temp->salary;
			cout<<"\nEnter the new Email:";
			cin>>temp->email;
			cout<<"\nEnter the new Mobile no.:";
			cin>>temp->mob;
			cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
			cin>>temp->offeredto; 

		}
	}
	
	if(temp1!=NULL)
	{
		if(temp1->id==check)
		{
			cout<<"\nEnter The New Job Details:";
			
			cout<<"\nEnter the new company name:";
			cin>>temp1->company;
			cout<<"\nEnter the new location:";
			cin>>temp1->location;
			cout<<"\nEnter the new post:";
			cin>>temp1->post;
			cout<<"\nEnter the new salary(in Rs.):";
			cin>>temp1->salary;
			cout<<"\nEnter the new Email:";
			cin>>temp1->email;
			cout<<"\nEnter the new Mobile no.:";
			cin>>temp1->mob;
			cout<<"\nEnter the Offer to(fresher/Experienced one/both):";
			cin>>temp1->offeredto; 

		}
	}
}
int main()
{
	struct node *temp=create();
	display(temp);
	//modify(temp);
	//display(temp);
	search(temp);
	search(temp);
	insert(temp);
	//delnode(temp);
	display(temp);
	
	
	return 0;
}
