//A Vector Calculation Program
// by application of operator overloading

/* Sample input
N a 3 0 0 0
N b 5 1 2 1 2 5
A a 8 3 4 3 4 3 4 5 6
N c 2 -1 -2
S 4 a a b c
I a 1 0
C L a b
*/

/* Sample Output
0
*/

/*
 N: (new vector) creates a new vector "a", with value "3 0 0 0"
 A: (assignment) assigns "8 3 4 3 4 3 4 5 6" to vector a
 S: (sum) adds vector "a", "b", and "c" to "a"
 I: (indexing) assign "0" to a[1]
 C: (compare) L for Less, G for Greater, E for Equal. Returns bool.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
 
class RecyclingVector
{
private:
    int length;
    int data[40];
    string name;
    int temp[40];
public:
    int right;
    int left;
    RecyclingVector():length(0), right(0), left(0)
    {
        for(int i = 0; i < 20; i++){
            data[i] = 0;
            temp[i] = 0;
        }
    }
    void set_name(string str)
    {
        this->name = str;
    }
    void set_data(int value[])
    {
        for(int i = 0; i < this->length; i++)
            this->data[i] = value[i];
    }
    void set_length(int len)
    {
        this->length = len;
    }
    void print(int result)
    {
        cout << result << endl;
    }
    RecyclingVector &operator=(const RecyclingVector& v)
    {
        for(int i = 0; i < this->length; i++)
            this->data[i] = 0;
        this->length = v.length;
        for(int i = 0; i < this->length; i++)
            this->data[i] = v.data[i];
        return *this;
    }
     
    void operator>(const RecyclingVector& v)
    {
        //find the larger length
        int len = 0;
        int k = 0;
        int arr1[40] = {0};
        int arr2[40] = {0};
        for(int i = 0; i < this->length; i++)
            arr1[i] = this->data[i];
        for(int i = 0; i < v.length; i++)
            arr2[i] = v.data[i];
        if(this->length > v.length){
            len = this->length;
            for(int i = 0; i < len; i++){
                arr2[v.length+k] = arr2[i];
                k++;
            }
        }
        else{
            len = v.length;
            for(int i = 0; i < len; i++){
                arr1[this->length+k] = arr1[i];
                k++;
            }
        }
        int result = 1;
        for(int i = 0; i < len; i++){
            if(arr1[i] <= arr2[i])
                result = 0;
        }
        print(result);
    }
    void operator<(const RecyclingVector& v)
    {
        int len = 0;
        int k = 0;
        int arr1[40] = {0};
        int arr2[40] = {0};
        for(int i = 0; i < this->length; i++)
            arr1[i] = this->data[i];
        for(int i = 0; i < v.length; i++)
            arr2[i] = v.data[i];
        if(this->length > v.length){
            len = this->length;
            for(int i = 0; i < len; i++){
                arr2[v.length+k] = arr2[i];
                k++;
            }
        }
        else{
            len = v.length;
            for(int i = 0; i < len; i++){
                arr1[this->length+k] = arr1[i];
                k++;
            }
        }
        int result = 1;
        for(int i = 0; i < len; i++){
            if(arr1[i] >= arr2[i])
                result = 0;
        }
        print(result);
    }
    void operator==(const RecyclingVector& v)
    {
        int len = 0;
        int k = 0;
        int arr1[40] = {0};
        int arr2[40] = {0};
        for(int i = 0; i < this->length; i++)
            arr1[i] = this->data[i];
        for(int i = 0; i < v.length; i++)
            arr2[i] = v.data[i];
        if(this->length > v.length){
            len = this->length;
            for(int i = 0; i < len; i++){
                arr2[v.length+k] = arr2[i];
                k++;
            }
        }
        else{
            len = v.length;
            for(int i = 0; i < len; i++){
                arr1[this->length+k] = arr1[i];
                k++;
            }
        }
        int result = 1;
        for(int i = 0; i < len; i++){
            if(arr1[i] != arr2[i])
                result = 0;
        }
        print(result);
    }
    const RecyclingVector operator-(const RecyclingVector v)
    {
        RecyclingVector answer;
        if(this->length > v.length)
            answer.length = this->length;
        else
            answer.length = v.length;
        if(this->length == 0){
            this->length = v.length;
            for(int i = 0; i < this->length; i++)
                this->data[i] = 0;
        }
        for(int i = 0; i < answer.length; i++){
            answer.data[i] = this->data[i % this->length] - v.data[i % v.length];
        }
        return answer;
    }
    const RecyclingVector operator+(const RecyclingVector v)
    {
        RecyclingVector answer;
        if(this->length > v.length)
            answer.length = this->length;
        else
            answer.length = v.length;
        if(this->length == 0){
            this->length = v.length;
            for(int i = 0; i < this->length; i++)
                this->data[i] = 0;
        }
        for(int i = 0; i < answer.length; i++){
            answer.data[i] = this->data[i % this->length] + v.data[i % v.length];
        }
        return answer;
    }
    void operator[](RecyclingVector num)
    {
        this->data[num.left-1] = num.right;
    }
    void reset_data(string status, RecyclingVector&v)
    {
        if(status == "new_name")
            this->length = v.length;
        for(int i = 0; i < this->length; i++)
            this->data[i] = 0;
    }
    void reset_data_two()
    {
        for(int i = this->length; i < 41; i++)
            this->data[i] = 0;
    }
    ~RecyclingVector(){}
};
 
//Function to check the existence of a variable in the name array
int check_name(string value, string name[], int cnt)
{
    for(int i = 0; i < cnt; i++){
        if(name[i] == value)
            return i;
    }
    return 030;//Do not exist
}
 
int main()
{
    RecyclingVector input[26];
    string task; //Store the six tasks
    string name[26];
    RecyclingVector temp;
    int data[26][40] = {0};
    int length = 0;
    int cnt = 0;
    int temp_data[40] = {0};//Store temporal data
    string temp_name;//Store name to be checked
    int index = 0;//Store temporal index
     
    while(cin >> task){
        //New
        if(task == "N"){
            cin >> name[cnt] >> length;
            for(int i = 0; i < length; i++)
                cin >> data[cnt][i];
            input[cnt].set_length(length);
            input[cnt].set_name(name[cnt]);
            input[cnt].set_data(data[cnt]);
            cnt++;
        }
        //Assignment
        else if(task == "A"){
            cin >> temp_name >> length;
            temp.set_name(temp_name);
            temp.set_length(length);
            for(int i = 0; i < length; i++)
                cin >> temp_data[i];
            temp.set_data(temp_data);
            index = check_name(temp_name, name, cnt);
            input[index] = temp;
            for(int i = 0; i < length; i++)
                data[index][i] = temp_data[i];
        }
        //Compare
        else if(task == "C"){
            string compared_to;
            int index_two = 0;
            cin >> task >> temp_name >> compared_to;
            index = check_name(temp_name, name, cnt);
            index_two = check_name(compared_to, name, cnt);
            //Greater than
            if(task == "G"){
                input[index] > input[index_two];
            }
            //Less than
            else if(task == "L"){
                input[index] < input[index_two];
            }
            //Equal to
            else if(task == "E"){
                input[index] == input[index_two];
            }
        }
        //Indexing
        else if(task == "I"){
            RecyclingVector num;
            cin >> temp_name >> num.left >> num.right;
            index = check_name(temp_name, name, cnt);
            input[index].operator[](num);
        }
        //Sum
        else if(task == "S"){
            int n = 0;
            RecyclingVector answer;
            int index2 = 0;
            string status;
            cin >> n >> task;
            string add_name[n-1];
            for(int i = 0; i < n-1; i++)
                cin >> add_name[i];
            index = check_name(task, name, cnt);
            if(index != 030){
                for(int j = 0; j < n-1; j++){
                    index2 = check_name(add_name[j], name, cnt);
                    answer = answer + input[index2];
                }
                input[index] = answer;
            }
            if(index == 030){
                input[cnt].set_name(task);
                name[cnt] = task;
                cnt++;
                for(int j = 0; j < n-1; j++){
                    index2 = check_name(add_name[j], name, cnt);
                    answer = answer + input[index2];
                }
                input[cnt-1] = answer;
            }
        }
        //Minus
        else if(task == "M"){
            int n = 0;
            RecyclingVector answer;
            int index2 = 0;
            string status;
            cin >> n >> task;
            string add_name[n-1];
            for(int i = 0; i < n-1; i++)
                cin >> add_name[i];
            index = check_name(task, name, cnt);
            if(index != 030){
                for(int j = 0; j < n-1; j++){
                    index2 = check_name(add_name[j], name, cnt);
                    if(j == 0)
                        answer = input[index2];
                    else
                        answer = answer - input[index2];
                }
                input[index] = answer;
            }
            if(index == 030){
                input[cnt].set_name(task);
                name[cnt] = task;
                cnt++;
                for(int j = 0; j < n-1; j++){
                    index2 = check_name(add_name[j], name, cnt);
                    if(j == 0)
                        answer = input[index2];
                    else
                        answer = answer - input[index2];
                }
                input[cnt-1] = answer;
            }
        }
 
    }
     
    return 0;
}
