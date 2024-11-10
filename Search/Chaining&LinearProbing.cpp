//Chaining and Linear probing
#include<bits/stdc++.h>
using namespace std;

struct hashChain{
	int data;
	struct hashChain *next;
};

void insertChain(struct hashChain* chain[], int n, int x)
{
	int hash = x%n;
	struct hashChain* node;
	node = (struct hashChain*)malloc(sizeof(struct hashChain));
	node ->data = x;
	node ->next = NULL;
	if(chain[hash] == NULL)
	{
		chain[hash] = node;
	}
	else{
		struct hashChain* temp;
		temp = chain[hash];
		while(temp ->next != NULL)
		{
			temp = temp ->next;
		}
		temp ->next = node;
	}
}

void printChain(struct hashChain* chain[], int n) 
{
	cout<<"HASH TABLE: \n";
	for(int i=0; i<n; i++)
	{
		struct hashChain* temp;
		temp = chain[i];
		cout<<"ROW "<<i<<" : ";
		while(temp != NULL)
		{
			cout<<temp ->data<<" ";
			temp = temp ->next;
		}
		cout<<endl;
	}
}

void deleteChain(struct hashChain* chain[], int n, int x)
{
	int hash = x%n;
	struct hashChain *temp, *node;
	temp = chain[hash];
	if(temp != NULL)
	{
		if(temp ->data == x)
		{
			temp = temp ->next;
			chain[hash] = temp;
		}
		else{
			while(temp ->next != NULL)
			{
				if(temp ->next ->data == x)
				{
					node =temp ->next;
					temp->next = temp ->next ->next;
					free(node);
					break;
				}
				temp = temp ->next;
			}
		}	
	}
}

int searchChain(struct hashChain* chain[], int n, int x)
{
	int hash = x%n;
	struct hashChain* temp;
	temp = chain[hash];
	int point = 0;
	while(1)
	{
		if(temp ->data == x)
		{
			point = 1;
			break;
		}
		if(temp ->next == NULL)
		{
			break;
		}
		temp = temp ->next;
	}
	return point;
}

int collisionChain(struct hashChain* chain[], int n)
{
    int collisions = 0;
    
    for (int i = 0; i < n; i++) {
        struct hashChain* temp = chain[i];
        int size = 0;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        if (size > 1) {
            collisions += size - 1;
        }
    }
    return collisions;
}


void insertTable(int table[], int n, int x)
{
	int hash = x%n;
	if(table[hash] == -2 || table[hash] == -1)
	{
		table[hash] = x;
	}
	else{
		for(int i= hash; ;)
		{
			if(table[i] == -2 || table[i] == -1)
			{
				table[i] = x;
				break;
			}
			i = (i+1)%n;
			if(i == hash)
			{
				break;
			}
		}
	}
}

void printTable(int table[], int n)
{
	cout<<"HASH TABLE: ";
	for(int i=0; i<n; i++)
	{
		if(table[i] != -2 && table[i] != -1)
		{
			cout<<table[i]<<" ";
		}
		else{
			cout<<"_ ";
		}
	}
	cout<<endl;
}

void deleteTable(int table[], int n, int x)
{
	int hash = x%n;
	for(int i= hash; ;)
	{
		if(table[i] == x)
		{
			table[i] = -1;
			break;
		}
		i= (i+1)%n;
		if(i == hash)
		{
			break;
		}
	}
}

int searchTable(int table[], int n, int x)
{
	int hash = x%n;
	int point =0;
	for(int i= hash; ;)
	{
		if(table[i] == x)
		{
			point = 1;
			break;
		}
		if(table[i] == -2)
		{
			break;
		}
		i= (i+1)%n;
		if(i == hash)
		{
			break;
		}
	}
	return point;
}

int collisionTable(int table[], int n)
{
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		if(table[i]%n != i && table[i] >= 0)
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	int n;
	cout<<"Enter the size of hash table: ";
	cin>>n;
	int val;
	cout<<"Enter 1 for implementing collision resolution using chaining and 0 for linear probing: ";
	cin>>val;



	if(val == 1)
	{
		struct hashChain* chain[n];
		for(int i=0; i<n; i++)
		{
			chain[i] = NULL;
		}
		insertChain(chain, n, 1);
		insertChain(chain, n, 2);
		insertChain(chain, n, 5);
		insertChain(chain, n, 4);
		insertChain(chain, n, 9);
		insertChain(chain, n, 7);
		deleteChain(chain, n, 3);
		printChain(chain, n);
		cout<<"2 is present in the list: "<<searchChain(chain, n, 2)<<endl;
		cout<<"Number of collisions in the chain: "<<collisionChain(chain, n)<<endl;
	}
	else{
		int table[n];
		for(int i=0; i<n; i++)
		{
			table[i] = -2;
		}
		insertTable(table, n, 1);
		insertTable(table, n, 9);
		insertTable(table, n, 5);
		insertTable(table, n, 3);
		deleteTable(table, n, 9);
		cout<<"5 is present in the table :"<<searchTable(table, n, 5)<<endl;
		printTable(table, n);
		cout<<"Number of collisions in the table: "<<collisionTable(table, n)<< endl;
	}
	
	
	return 0;
}
