#include <sstream>
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int hashFunc(int k, int m){     //index of array

    int h = k % m;          //h(k) = k mod m

    return h;

}

list <int> insertHash(list <int> row, int key){

   row.push_front(key);    //insert front of the linked list
   return row;

}

int searchHash(list <int> row, int key){

    list<int>::iterator it = row.begin();   //direct pointer to the linked list

    for(int i =0; i < row.size(); i++){

        if(*it == key){         //if the value matches value within the list, return the index
            return i;
        }

        it++;
    }

    return -1;
}

list <int> deleteHash(list <int> row, int key){

    list<int>::iterator it = row.begin();   //direct pointer to the linked list

    for(int i =0; i < row.size(); i++){     //goes through list

        if(*it == key){                     //if key is found delete it
            row.erase(it);
            cout << key <<":DELETED;"<<endl;
            return row;
        }

        it++;
    }

    cout << key <<":DELETE_FAILED;" <<endl;     //if key isn't found, message

    return row;
}


int main(){


	//stage 1
	//receive input m, the size of the chained hash table
	//loop through till user presses e

	//stage 2
	// 4 functions
		//i# = insert
		//s# = search
		//d# = delete
		//o = asks for output

	//e = terminate

	int m;
	string input;

	cin >> m;

	list <int> * arr = new list <int> [m]; //creates array of list

	while(input != "e"){

		cin >> input;				//i11

		int length = input.size();

		if (length > 1){

            string operation = input.substr(0,1);
			string value = input.substr(1);           //string to int
			int key = atoi(value.c_str());          //int

            if (operation == "i")
               arr[hashFunc(key,m)] = insertHash(arr[hashFunc(key,m)],key);     //inserts a new link to the linked list

            if (operation == "s"){

                int s = searchHash(arr[hashFunc(key,m)],key);       //searches through the row for a key

                if (s == -1)
                    cout << key <<":NOT_FOUND;"<<endl;
                else
                    cout << key <<":FOUND_AT" << hashFunc(key, m) << "," << s << ";" <<endl;
            }


            if (operation == "d"){

                arr[hashFunc(key,m)] = deleteHash(arr[hashFunc(key,m)],key);     //deletes a part of the linked list

            }
        }


        if (input == "o"){          //prints the state of the hash table
            list<int>::iterator it;

            for(int i =0; i < m; i++){      //goes through vertically aka the arrays
                it = arr[i].begin();
                cout<< i << ":";
                for(int j =0; j< arr[i].size();j++){        //goes through the linked lists within the array horizontally
                    cout << *it << "->";
                    it++;
                }
                cout <<";"<<endl;
            }

        }
	}

}


//
