
#include <iostream>
#include <list>
using namespace std;

//find minimum
int findMax(string str[],int s){
    //suppose the first word is smalled
    size_t max = str[0].size();
    //comparing the assymption with each word of array linerly
    for(int i=0;i<s;i++)
        //if element is smaller than word assumed as smaller
        if(str[i].length()>max)
            //if yes, then change the assymtion to that element
            max = str[i].length();
    return (int)max;
}

//helper function to do radix sort
void sort(string names[],int size, int maxLenght){
    list<string> lst[256];
    //start puting elements in bucket from msd(maxLenght)
    for(int i=0;i<size;i++)
        lst[names[i][maxLenght-1]].push_back(names[i]);
    int elem = 0;
    //retrieve element from each index and bucket and put them back in array
    //elements will be sorted according to
    for (int e = 0; e<256; e++)
        while(!lst[e].empty()){
            names[elem++] = lst[e].front();
            lst[e].pop_front();
        }
}

void Radix_Sort(string names[],int size){
    //find the string with maximum lenght
    int maxLenght = findMax(names,size);
    //loop throught each index of string for all strings
    do
        sort(names,size,maxLenght);
    while(--maxLenght);
}

//display function
void printOnConsole(string strings[],int size){
    for (int i=0; i<size; i++)
        cout<<strings[i]<<endl;
    cout<<endl;
}

//main method
int main(int argc, const char * argv[]) {
    string strings[] = {
        "a",
        "Abdul Majeed",
        "Abdul Hanan",
        "Abdul Manan",
        "Asad Ali",
        "Ali Hamza",
        "Nasir Khan Jan",
        "Hammad Latif",
        "Hammad Raza",
        "Zahra Ahmadi",
        "Zaheer Ahmad",
        "#1-Muhammad Wahab",
        "Abdul Rehman",
    };

    //size calculation
    int size = sizeof(strings)/sizeof(strings[0]);
    
    cout<<"Before sorting\n--------------\n";
    printOnConsole(strings,size);
    
    Radix_Sort(strings,size);
    
    cout<<"After sorting\n-------------\n";
    printOnConsole(strings,size);
    
    return 0;
}
